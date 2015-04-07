/*
** rsaupld.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Thu Mar 12 12:17:07 2015 Joris Bertomeu
** Last update Thu Mar 12 12:41:58 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_rsaupld(t_client *client, char *str)
{
  char		txt[4096];

  (void) str;
  bzero(txt, 4096);
  sprintf(txt, "STOR /etc/bertomzilla/.rsa/%s.pub\r\n", client->username);
  ftp_stor(client, txt);
}
