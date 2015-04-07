/*
** rnfr.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 17:28:53 2015 Joris Bertomeu
** Last update Sat Mar 21 16:15:39 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_rnfr(t_client *client, char *str)
{
  char		*arg;
  char		trame[4096];

  arg = get_cmd(str, 4);
  if (file_exists(arg))
    {
      client->rnfr = 1;
      sprintf(trame, "350 RNFR accepted - file exists,\
 ready for destination\r\n");
      sprintf(client->rndst, "%s", arg);
      write(client->fd, trame, strlen(trame));
    }
  else
    {
      client->rnfr = 0;
      sprintf(trame, "550 %s\r\n", strerror(errno));
      write(client->fd, trame, strlen(trame));
    }
}

