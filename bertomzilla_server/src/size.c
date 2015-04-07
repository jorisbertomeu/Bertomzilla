/*
** size.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Thu Mar 12 15:48:49 2015 Joris Bertomeu
** Last update Sat Mar 21 16:10:26 2015 Joris Bertomeu
*/

#include	"server.h"

off_t		getFileSize(const char *filename)
{
  struct stat st;

  if (stat(filename, &st) == 0)
    return (st.st_size);
  return (-1);
}

void		ftp_size(t_client *client, char *str)
{
  char		*arg;
  off_t		size;
  char		trame[4096];

  arg = get_cmd(str, 4);
  if ((size = getFileSize(arg)) != -1)
    {
      sprintf(trame, "250 %ld\r\n", size);
      write(client->fd, trame, strlen(trame));
    }
  else
    {
      sprintf(trame, "550 %s\r\n", strerror(errno));
      write(client->fd, trame, strlen(trame));
    }
}
