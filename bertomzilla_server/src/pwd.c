/*
** pwd.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 16:44:17 2015 Joris Bertomeu
** Last update Wed Mar 11 16:44:28 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_pwd(t_client *client, char *str)
{
  char		pwd[1024];
  char		trame[4096];

  (void) str;
  getcwd(pwd, 1024);
  sprintf(trame, "257 \"%s\" is your current location\r\n", pwd);
  write(client->fd, trame, strlen(trame));
}
