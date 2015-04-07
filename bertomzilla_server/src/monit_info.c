/*
** monit_info.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 19:12:39 2015 Joris Bertomeu
** Last update Fri Mar 27 19:22:40 2015 Joris Bertomeu
*/

#include	"server.h"

int		get_number_clients_connected(t_server *server)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < 50)
    {
      if (server->clients[i].ip)
	j++;
      i++;
    }
  return (j);
}

void		monit_info(t_server *server, int fd)
{
  char		buff[4096];
  int		nb_connected;

  nb_connected = get_number_clients_connected(server);
  bzero(buff, 4096);
  sprintf(buff, "Server Informations<br><br>\
- Clients connected : %d<br>\
- Uptime (sec) : %d<br>\
- Thread(s) : %d<br>\
- Fork(s) : %d<br>\r\n", nb_connected,
	  ((int) time(NULL)) - server->uptime,
	  nb_connected * 2 + 1, nb_connected);
  write(fd, buff, strlen(buff));
}
