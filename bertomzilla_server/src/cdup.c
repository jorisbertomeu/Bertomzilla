/*
** cdup.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 17:20:24 2015 Joris Bertomeu
** Last update Wed Mar 11 17:20:33 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_cdup(t_client *client, char *str)
{
  char		trame[4096];

  (void) str;
  bzero(trame, 4096);
  sprintf(trame, "CWD ../\r\n");
  ftp_cwd(client, &trame[0]);
}

