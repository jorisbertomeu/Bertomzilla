/*
** stor.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 17:48:39 2015 Joris Bertomeu
** Last update Sat Mar 21 17:56:26 2015 Joris Bertomeu
*/

#include	"server.h"

void			process_receving(t_client *client, int client_fd,
					 t_file *file, FILE *fd)
{
  int			times[2];
  ssize_t		n;
  char			buff[4096];

  file->size = 0;
  times[0] = time(NULL);
  while ((n = read(client_fd, buff, 4096)) > 0)
    {
      fwrite(buff, 1, n, fd);
      bzero(buff, 4096);
      file->size += n;
    }
  times[1] = time(NULL);
  close(client_fd);
  fclose(fd);
  close(client->pasv_sck);
  file->time = times[1] - times[0];
}

void			ftp_stor(t_client *client, char *str)
{
  FILE			*fd;
  int			client_fd;
  struct sockaddr_in	cliaddr;
  socklen_t		clilen;
  char			*arg;
  t_file		file;

  if (!is_authorized(client, 1))
    return;
  if (!is_passive(client))
    return;
  arg = get_cmd(str, 4);
  clilen = sizeof(cliaddr);
  client_fd = accept(client->pasv_sck,
		     (struct sockaddr *)&cliaddr, &clilen);
  write(client->fd, "150 Accepted data connection\r\n",
	strlen("150 Accepted data connection\r\n"));
  if (!(fd = open_file(client, arg, 0, 0)))
    return (send_error(client));
  process_receving(client, client_fd, &file, fd);
  sprintf(file.filename, "%s", arg);
  mysql_add_down_up(client, 1, &file);
  mysql_notif(client, "upload", "File uploaded successfully");
  write(client->fd, "226 File successfully received\r\n",
	strlen("226 File successfully received\r\n"));
}

