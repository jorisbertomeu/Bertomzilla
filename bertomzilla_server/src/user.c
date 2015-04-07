/*
** user.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 17:22:56 2015 Joris Bertomeu
** Last update Thu Mar 12 18:54:22 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_user(t_client *client, char *str)
{
  char		*arg;
  char		response[4096];

  arg = get_cmd(str, 4);
  if (client->username)
    free(client->username);
  if (strlen(arg) == 0)
    {
      client->username = malloc((strlen("Anonymous") + 1) * sizeof(char));
      bzero(client->username, strlen("Anonymous") + 1);
      strcpy(client->username, "Anonymous");
    }
  else
    {
      client->username = malloc((strlen(arg) + 1) * sizeof(char));
      bzero(client->username, strlen(arg) + 1);
      strcpy(client->username, arg);
    }
  bzero(response, 4096);
  sprintf(response, "331 User %s OK\r\n", client->username);
  write(client->fd, response, strlen(response));
}
