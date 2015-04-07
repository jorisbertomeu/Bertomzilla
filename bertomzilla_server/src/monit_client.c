/*
** monit_client.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 19:08:16 2015 Joris Bertomeu
** Last update Fri Mar 27 19:08:26 2015 Joris Bertomeu
*/

#include	"server.h"

void			client_cmd(t_server *server, char *str, int fd)
{
  int			i;

  i = 7;
  while ((str[i] == ' ' || str[i] == '\t') && str[i])
    i++;
  if (!strcmp(&str[i], "-list"))
    list_clients(server, fd);
  else if (!strncmp(&str[i], "-kick", 5))
    kick_clients(server, fd, str);
  else if (!strncmp(&str[i], "-ban", 4))
    ban_clients(server, fd, str);
  else
    write(fd, "Unknown option\r\n",
	  strlen("Unknown option\r\n"));
}

