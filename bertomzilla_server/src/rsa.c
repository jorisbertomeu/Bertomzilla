/*
** rsa.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Thu Mar 12 13:22:13 2015 Joris Bertomeu
** Last update Sat Mar 21 19:25:19 2015 Joris Bertomeu
*/

#include	"server.h"

int		fill_publicKey(t_client *client)
{
  char		filename[4096];
  FILE		*fd;

  sprintf(filename, "/etc/bertomzilla/.rsa/%s.pub", client->username);
  if (!file_exists(filename))
    {
      send_error(client);
      return (0);
    }
  if (!(fd = open_file(client, filename, 0, 1)))
    {
      send_error(client);
      return (0);
    }
  bzero(client->publicKeyRSA, 4096);
  fread(client->publicKeyRSA, 1, 4096, fd);
  fclose(fd);
  return (1);
}

void		ftp_rsa(t_client *client, char *str)
{
  char		*arg;

  arg = get_cmd(str, 3);
  if (!strcmp(arg, "ON"))
    {
      client->rsa = 1;
      if (!fill_publicKey(client))
	return;
      mysql_notif(client, "gear", "FTP Server switched to RSA Mode");
      write(client->fd, "250 Server switched to RSA Mode\r\n",
	    strlen("250 Server switched to RSA Mode\r\n"));
    }
  else
    {
      client->rsa = 0;
      mysql_notif(client, "gear", "FTP Server switched to non-RSA Mode");
      write(client->fd, "250 Server switched to non-RSA Mode\r\n",
	    strlen("250 Server switched to non-RSA Mode\r\n"));
    }
}
