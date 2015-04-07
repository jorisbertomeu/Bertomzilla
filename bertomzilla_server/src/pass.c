/*
** pass.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 17:25:53 2015 Joris Bertomeu
** Last update Sat Mar 21 17:07:19 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_pass(t_client *client, char *str)
{
  char		*arg;
  char		response[4096];

  arg = get_cmd(str, 4);
  if (client->password)
    free(client->password);
  if (check_mysql(client, arg) ||
      (!strcmp(client->username, "Anonymous") && !strcmp(arg, "")))
    {
      client->password = malloc((strlen(arg) + 1) * sizeof(char));
      strcpy(client->password, arg);
      mysql_notif(client, "sign-in", "Successfully Connected");
    }
  else
    {
      bzero(response, 4096);
      sprintf(response, "530 Login authentication failed\r\n");
      write(client->fd, response, strlen(response));
      return;
    }
  sprintf(response, "230 OK. Current directory is %s\r\n", client->home);
  write(client->fd, response, strlen(response));
  client->logged = 1;
  chdir(client->home);
}
