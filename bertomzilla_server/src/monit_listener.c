/*
** monit_listener.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 19:07:11 2015 Joris Bertomeu
** Last update Fri Mar 27 20:05:20 2015 Joris Bertomeu
*/

#include	"server.h"

int			read_for_monit(t_server *server, int fd)
{
  char			buff[4096];
  int			n;

  (void) server;
  bzero(buff, 4096);
  n = read(fd, buff, 4096);
  if (n < 3)
    return (0);
  buff[strlen(buff) - 2] = 0x00;
  parse_monit_cmd(server, buff, fd);
  return (n);
}

void			add_new_client_monit(t_server *server,
					     struct sockaddr_in *clientname)
{
  int			new;
  socklen_t		size;

  size = sizeof(clientname);
  new = accept(server->monit.fd_monit,
	       (struct sockaddr *) clientname,
	       &size);
  if (new < 0)
    show_error("Error while accepting !");
  FD_SET(new, &(server->monit.active_fd_set));
}

void			choose_select_fd(t_server *server, struct sockaddr_in *clientname)
{
  int			i;

  i = 0;
  while (i < FD_SETSIZE)
    {
      if (FD_ISSET(i, &(server->monit.read_fd_set)))
	{
	  if (i == server->monit.fd_monit)
	    add_new_client_monit(server, clientname);
	  else
	    {
	      if (read_for_monit(server, i) < 0)
		{
		  close(i);
		  FD_CLR(i, &(server->monit.active_fd_set));
		}
	    }
	}
      i++;
    }
}

void			*monit_managing(void *ptr)
{
  t_server		*server;
  struct sockaddr_in	clientname;

  server = (t_server *) ptr;
  FD_ZERO(&(server->monit.active_fd_set));
  FD_SET(server->monit.fd_monit, &(server->monit.active_fd_set));
  while (1)
    {
      server->monit.read_fd_set = server->monit.active_fd_set;
      if (select(FD_SETSIZE, &(server->monit.read_fd_set),
		 NULL, NULL, NULL) < 0)
	show_error("Error while selecting !");
      choose_select_fd(server, &clientname);
   }
  return (NULL);
}
