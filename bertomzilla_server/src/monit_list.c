/*
** monit_list.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 18:41:48 2015 Joris Bertomeu
** Last update Fri Mar 27 20:21:32 2015 Joris Bertomeu
*/

#include	"server.h"

void			list_clients(t_server *server, int fd)
{
  int			i;
  char			buff[4096];

  i = 0;
  bzero(buff, 4096);
  while (server->clients[i].ip)
    {
      sprintf(buff, "%s%s&nbsp;<%d> as %s<br>", buff, server->clients[i].ip,
	      server->clients[i].pid, server->clients[i].username);
      i++;
    }
  if (!i)
    sprintf(buff, "No client connected");
  sprintf(buff, "%s\r\n", buff);
  write(fd, buff, strlen(buff));
  sprintf(buff, "Monit : Client(s) connected listed");
  mysql_notif_monit(server, "files-o", buff);
}

