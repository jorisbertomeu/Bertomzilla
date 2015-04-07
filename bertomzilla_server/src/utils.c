/*
** utils.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/server/src
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 18 13:33:57 2015 Joris Bertomeu
** Last update Wed Mar 25 18:01:36 2015 Joris Bertomeu
*/

#include	"server.h"

void		send_error(t_client *client)
{
  char		buff[4096];

  bzero(buff, 4096);
  sprintf(buff, "550 %s\r\n", strerror(errno));
  write(client->fd, buff, strlen(buff));
  close(client->pasv_sck);
}

FILE		*open_file(t_client *client, char *filename, int flg, int mode)
{
  FILE		*fd;
  char		flags[3];

  flags[2] = 0x00;
  flags[1] = (client->type == ASCII && !flg) ? 0x00 : 'b';
  flags[0] = (mode == 1) ? 'r' : 'w' ;
 if (!(fd = fopen(filename, flags)))
    {
      if (flg == 0)
	mysql_notif(client, "download", "File downloading failed");
      else if (flg == 1)
	mysql_notif(client, "upload", "File uploading failed");
      printf("Error while openning file \"%s\"\n", filename);
      return (NULL);
    }
 return (fd);
}

int		file_exists(char *filename)
{
  if (access(filename, F_OK) != -1 )
    return (1);
  else
    return (0);
}

char		*get_cmd(char *str, int len)
{
  int		i;

  i = len;
  str[strlen(str) - 2] = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  return (&str[i]);
}

int		is_passive(t_client *client)
{
  if (!client->passive)
    {
      write(client->fd, "425 No data connection\r\n",
	    strlen("425 No data connection\r\n"));
      return (0);
    }
  return (1);
}
