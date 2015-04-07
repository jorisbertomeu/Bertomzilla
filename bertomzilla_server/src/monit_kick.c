/*
** monit_kick.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 18:42:56 2015 Joris Bertomeu
** Last update Fri Mar 27 20:23:31 2015 Joris Bertomeu
*/

#include	"server.h"

void			kick_clients(t_server *server, int fd, char *str)
{
  int			i;
  char			buff[4096];

  (void) server;
  i = 7;
  bzero(buff, 4096);
  while ((str[i] == ' ' || str[i] == '\t') && str[i])
    i++;
  i += 5;
  while ((str[i] == ' ' || str[i] == '\t') && str[i])
    i++;
  if (!kill(atoi(&str[i]), SIGUSR2))
    write(fd, "Client successfully kicked !",
	  strlen("Client successfully kicked !"));
  else
    {
      sprintf(buff, "Error while kicking : %s", strerror(errno));
      write(fd, buff, strlen(buff));
      return;
    }
  sprintf(buff, "Monit : Client instanciation %s kicked successfully", &str[i]);
  mysql_notif_monit(server, "times", buff);
}

