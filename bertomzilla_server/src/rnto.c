/*
** rnto.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 17:29:56 2015 Joris Bertomeu
** Last update Wed Mar 11 17:36:00 2015 Joris Bertomeu
*/

#include	"server.h"

int		is_dst(t_client *client)
{
  int		ret;
  char		trame[4096];

  ret = 1;
  if (!client->rnfr)
    {
      sprintf(trame, "550 You have to specify a file to rename \
or to rename !\r\n");
      write(client->fd, trame, strlen(trame));
      ret = 0;
    }
  client->rnfr = 0;
  return (ret);
}

void		ftp_rnto(t_client *client, char *str)
{
  char		*arg;
  char		trame[4096];

  arg = get_cmd(str, 4);
  if (!is_dst(client))
    return;
  if (rename(client->rndst, arg) != 0)
    {
      sprintf(trame, "Error while renaming or moving file or directory : %s",
	      strerror(errno));
      mysql_notif(client, "tag", trame);
      sprintf(trame, "550 %s\r\n", strerror(errno));
      write(client->fd, trame, strlen(trame));
    }
  else
    {
      sprintf(trame, "File or directory \"%s\" renamed or moved successfully",
	      arg);
      mysql_notif(client, "tag", trame);
      sprintf(trame, "250 File successfully renamed or moved\r\n");
      write(client->fd, trame, strlen(trame));
    }
}
