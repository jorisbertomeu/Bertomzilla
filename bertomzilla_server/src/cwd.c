/*
** cwd.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 17:17:40 2015 Joris Bertomeu
** Last update Sat Mar 28 16:38:37 2015 Joris Bertomeu
*/

#include		"server.h"

void		ftp_cwd(t_client *client, char *str)
{
  char		trame[4096];
  char		pwd[2][512];
  char		*arg;

  getcwd(pwd[0], 512);
  arg = get_cmd(str, 3);
  if (chdir(arg) == 0)
    {
      getcwd(pwd[1], 512);
      if (strlen(pwd[1]) < strlen(client->home) ||
	  strncmp(pwd[1], client->home, strlen(client->home)))
	{
	  chdir(pwd[0]);
	  sprintf(trame, "550 Unauthorized area\r\n");
	  write(client->fd, trame, strlen(trame));
	  return;
	}
      sprintf(trame, "250 OK. Current directory is %s\r\n", pwd[1]);
      write(client->fd, trame, strlen(trame));
    }
  else
    {
      sprintf(trame, "550 %s\r\n", strerror(errno));
      write(client->fd, trame, strlen(trame));
    }
}
