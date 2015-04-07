/*
** network.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/server/src
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 18 13:14:02 2015 Joris Bertomeu
** Last update Thu Mar 26 16:19:50 2015 Joris Bertomeu
*/

#include	"server.h"

void		create_socket(t_server *server)
{
  if ((server->fd_srv = socket(AF_INET , SOCK_STREAM , 0)) == -1)
    show_error("Error while creating socket !");
  server->srv_sck.server.sin_family = AF_INET;
  server->srv_sck.server.sin_addr.s_addr = INADDR_ANY;
  server->srv_sck.server.sin_port = htons(server->port);
  if (bind(server->fd_srv, (struct sockaddr *) &(server->srv_sck.server),
	  sizeof(server->srv_sck.server)) < 0)
    show_error("Error while Binding !");
  listen(server->fd_srv, 50);
}

void		init_server(t_server *server)
{
  create_socket(server);
  create_monit_socket(server);
}

void		send_banner(t_server *server, int fd)
{
  char		banner[4096];
  FILE		*fh;
  char		buff[4096];

  if (!(fh = fopen(server->conf->srv_banner, "r")))
    write(fd, "220 - Welcome !\r\n", strlen("220 - Welcome !\r\n"));
  fread(buff, 1, 4096, fh);
  bzero(banner, 4096);
  sprintf(banner, "220 %s\r\n", buff);
  write(fd, banner, strlen(banner));
  fclose(fh);
}

int		check_auth(t_client *client, char *str)
{
  if (!client->username && strncmp(str, "USER", 4))
    {
      write(client->fd, "530 You aren't logged in\n",
	    strlen("530 You aren't logged in\n"));
      return (0);
    }
  else if (!client->password && strncmp(str, "PASS", 4) &&
	   strncmp(str, "USER", 4))
    {
      write(client->fd, "530 You aren't logged in\r\n",
	    strlen("530 You aren't logged in\r\n"));
      return (0);
    }
  return (1);
}
