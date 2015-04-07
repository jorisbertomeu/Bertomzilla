/*
** monit_operations.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 18:38:54 2015 Joris Bertomeu
** Last update Fri Mar 27 19:25:25 2015 Joris Bertomeu
*/

#include	"server.h"

int			is_banned(t_server *server, struct sockaddr_in client, int fd)
{
  int			i;

  i = 0;
  while (i < 50)
    {
      if (server->banned[i] && !strcmp(server->banned[i],
				       inet_ntoa(client.sin_addr)))
	{
	  write(fd, "1061 Connexion refused : IP Banned\r\n",
		strlen("1061 Connexion refused : IP Banned\r\n"));
	  return (1);
	}
      i++;
    }
  return (0);
}

void			delete_client_from_list(t_client *client, int fd)
{
  int			i;

  i = 0;
  while (i < 50)
    {
      if (client->server->clients[i].fd == fd)
	{
	  client->server->clients[i].ip = NULL;
	  close(client->server->clients[i].fd);
	  client->server->clients[i].fd = -1;
	  client->server->clients[i].pid = -1;
	  printf("Client successfully removed from list\n");
	  return;
	}
      i++;
    }
}

void			delete_client_from_list_with_pid(t_server *server, int pid)
{
  int			i;

  i = 0;
  while (i < 50)
    {
      if (server->clients[i].pid == pid)
	{
	  server->clients[i].ip = NULL;
	  close(server->clients[i].fd);
	  server->clients[i].fd = -1;
	  server->clients[i].pid = -1;
	  printf("Client successfully removed from list\n");
	  return;
	}
      i++;
    }
}

void			add_user_to_client_list(t_client *client)
{
  int			i;
  int			pid;

  i = 0;
  pid = (int) getpid();
  while (i < 50)
    {
      if (client->server->clients[i].pid == pid)
	{
	  strcpy(client->server->clients[i].username, client->username);
	  return;
	}
      i++;
    }
}

void			delete_client_from_list_with_pid_and_ban(t_server *server, int pid)
{
  int			i;

  i = 0;
  while (i < 50)
    {
      if (server->clients[i].pid == pid)
	{
	  server->clients[i].ip = NULL;
	  close(server->clients[i].fd);
	  server->clients[i].fd = -1;
	  server->clients[i].pid = -1;
	  printf("Client successfully removed from list\n");
	  return;
	}
      i++;
    }
}
