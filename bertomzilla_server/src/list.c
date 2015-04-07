/*
** list.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 17:12:17 2015 Joris Bertomeu
** Last update Sat Mar 28 16:55:52 2015 Joris Bertomeu
*/

#include		"server.h"

void			process_sending_list(t_client *client,
					     FILE *fd, int client_fd)
{
  char			buff[4096];
  ssize_t		n;

  while (!feof(fd))
    {
      bzero(buff, 4096);
      n = fread(buff, 1, 4096, fd);
      write(client_fd, buff, n);
    }
  close(client_fd);
  close(client->pasv_sck);
  fclose(fd);
}

void			end_list(t_client *client, FILE *fd, int client_fd)
{
  process_sending_list(client, fd, client_fd);
  mysql_notif(client, "files-o", "Directory listed");
  write(client->fd, "226 LIST Successfully\r\n",
	strlen("226 LIST Successfully\r\n"));
}

void			cond_is_ok(t_client *client, int client_fd)
{
  write(client->fd, "550 LIST failed\r\n", strlen("550 LIST failed\r\n"));
  close(client_fd);
}

void		bad_path(t_client *client)
{
  write(client->fd, "426 DTI Connection refused : Unauthaurized area\r\n",
	strlen("426 DTI Connection refused : Unauthaurized area\r\n"));
}

void			ftp_list(t_client *client, char *str)
{
  FILE			*fd;
  int			client_fd;
  struct sockaddr_in	cliaddr;
  socklen_t		clilen;
  char			*arg;
  char			buff[4096];

  arg = get_cmd(str, 4);
  if (!is_passive(client))
    return;
  clilen = sizeof(cliaddr);
  if (!is_authorized_path(client, arg))
    return (bad_path(client));
  client_fd = accept(client->pasv_sck,
		     (struct sockaddr *)&cliaddr, &clilen);
  write(client->fd, "150 Accepted data connection\r\n",
	strlen("150 Accepted data connection\r\n"));
  sprintf(buff, "ls -la %s > /tmp/.result", arg);
  system(buff);
  if (!(fd = fopen("/tmp/.result", "r")))
    return (cond_is_ok(client, client_fd));
   end_list(client, fd, client_fd);
}
