/*
** monit_ban.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 18:42:25 2015 Joris Bertomeu
** Last update Fri Mar 27 20:21:49 2015 Joris Bertomeu
*/

#include	"server.h"

int			get_good_pos_for_ban(int pos, char *str)
{
  int			i;

  i = pos;
  while ((str[i] == ' ' || str[i] == '\t') && str[i])
    i++;
  i += 4;
  while ((str[i] == ' ' || str[i] == '\t') && str[i])
    i++;
  return (i);
}

void			ban_clients(t_server *server, int fd, char *str)
{
  int			i;
  char			buff[4096];
  int			k[2];
  int			j;

  (void) server;
  bzero(buff, 4096);
  i = get_good_pos_for_ban(7, str);
  k[0] = 0;
  k[1] = 0;
  j = 0;
  while (j < 50)
    {
      if (server->clients[j].ip && !strcmp(server->clients[j].ip, &str[i]))
	{
	  k[1]++;
	  if (!kill(server->clients[j].pid, SIGUSR1))
	    k[0]++;
	}
      j++;
    }
  if (k[0] > 0)
    add_ban(server, &str[i]);
  sprintf(buff, "%d/%d client(s) instanciation banned\r\n", k[0], k[1]);
  write(fd, buff, strlen(buff));
  sprintf(buff, "Monit : %d/%d client(s) instanciation banned for ip %s", k[0], k[1], &str[i]);
  mysql_notif_monit(server, "ban", buff);
}

