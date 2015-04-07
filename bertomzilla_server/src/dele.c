/*
** dele.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 17:33:37 2015 Joris Bertomeu
** Last update Wed Mar 18 12:36:42 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_dele(t_client *client, char *str)
{
  char		*arg;
  char		trame[4096];

  arg = get_cmd(str, 4);
  if (remove(arg) != 0)
    {
      sprintf(trame, "Error while deleting file \"%s\" or directory : %s",
	      arg, strerror(errno));
      mysql_notif(client, "remove", trame);
      sprintf(trame, "550 %s\r\n", strerror(errno));
      write(client->fd, trame, strlen(trame));
    }
  else
    {
      sprintf(trame, "Directory or file \"%s\" deleted successfully !",
	      arg);
      mysql_notif(client, "remove", trame);
      sprintf(trame, "250 \"%s\" : Deleted successfully\r\n", arg);
      write(client->fd, trame, strlen(trame));
    }
}
