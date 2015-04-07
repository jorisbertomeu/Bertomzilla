/*
** monit_sock.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server/src
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Thu Mar 26 16:19:08 2015 Joris Bertomeu
** Last update Fri Mar 27 19:53:58 2015 Joris Bertomeu
*/

#include	"server.h"

void		create_monit_socket(t_server *server)
{
  if ((server->monit.fd_monit = socket(AF_INET , SOCK_STREAM , 0)) == -1)
    show_error("Error while creating socket !");
  server->monit.server_monit.sin_family = AF_INET;
  server->monit.server_monit.sin_addr.s_addr = INADDR_ANY;
  server->monit.server_monit.sin_port = htons(atoi(server->conf->monit_port));
  if (bind(server->monit.fd_monit,
	   (struct sockaddr *) &(server->monit.server_monit),
	   sizeof(server->monit.server_monit)) < 0)
    show_error("Error while Binding for monitoring interface !");
  listen(server->monit.fd_monit, 50);
}

void			parse_monit_cmd(t_server *server, char *str, int fd)
{
  char			*msg;

  (void) server;
  if (!strcmp(str, "help"))
    {
      msg = show_help();
      write(fd, msg, strlen(msg));
      free(msg);
    }
  else if (!strncmp(str, "client ", 7) ||
	   !strncmp(str, "client\t", 7))
    client_cmd(server, str, fd);
  else if (!strncmp(str, "server ", 7) || !strncmp(str, "server\t", 7))
    server_cmd(server, str, fd);
  else
    write(fd, "Unknown command\r\n",
	  strlen("Unknown command\r\n"));
}
