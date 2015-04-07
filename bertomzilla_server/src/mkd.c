/*
** mkd.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 17:21:11 2015 Joris Bertomeu
** Last update Sat Mar 21 17:56:48 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_mkd(t_client *client, char *str)
{
  char		*arg;
  char		trame[4096];

  arg = get_cmd(str, 3);
  if (!is_authorized(client, 2))
    return;
  if (mkdir(arg, S_IRWXU | S_IRWXG | S_IRWXO) != 0)
    {
      sprintf(trame, "Error while creating directory : %s", strerror(errno));
      mysql_notif(client, "folder", trame);
      sprintf(trame, "550 %s\r\n", strerror(errno));
      write(client->fd, trame, strlen(trame));
    }
  else
    {
      sprintf(trame, "Directory \"%s\" created successfully !", arg);
      mysql_notif(client, "folder", trame);
      sprintf(trame, "257 \"%s\" : The directory\
 was successfully created\r\n", arg);
      write(client->fd, trame, strlen(trame));
    }
}
