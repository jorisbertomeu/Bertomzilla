/*
** monit_init.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 18:40:15 2015 Joris Bertomeu
** Last update Fri Mar 27 20:09:04 2015 Joris Bertomeu
*/

#include	"server.h"

void			add_new_client(t_server *server,
				       struct sockaddr_in client,
				       int fd, int pid)
{
  int			i;

  i = 0;
  while (i < 50)
    {
      if (!server->clients[i].ip)
	{
	  server->clients[i].ip = inet_ntoa(client.sin_addr);
	  server->clients[i].fd = fd;
	  server->clients[i].pid = pid;
	  bzero(server->clients[i].username, 4096);
	  strcpy(server->clients[i].username, "NC");
	  server->clients_nbr++;
	  break;
	}
      i++;
    }
}

int			get_fd_with_pid(t_server *server, int pid)
{
  int			i;

  i = 0;
  while (i < 50)
    {
      if (server->clients[i].pid == pid)
	return (server->clients[i].fd);
      i++;
    }
  return (1);
}

void			init_clients_tab(t_server *server)
{
  int			i;

  i = 0;
  while (i < 50)
    {
      server->clients[i].ip = NULL;
      server->banned[i] = NULL;
      i++;
    }
}

void			add_ban(t_server *server, char *ip)
{
  int			i;

  i = 0;
  while (i < 50)
    {
      if (!server->banned[i])
	{
	  server->banned[i] = malloc(128 * sizeof(char));
	  bzero(server->banned[i], 128);
	  strcpy(server->banned[i], ip);
	  break;
	}
      i++;
    }
}
