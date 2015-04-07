/*
** monit_server.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 19:08:02 2015 Joris Bertomeu
** Last update Fri Mar 27 19:23:56 2015 Joris Bertomeu
*/

#include	"server.h"

void			server_cmd(t_server *server, char *str, int fd)
{
  int			i;

  i = 7;
  (void) server;
  while ((str[i] == ' ' || str[i] == '\t') && str[i])
    i++;
  if (!strcmp(&str[i], "-reboot"))
    write(fd, "Error while rebooting (0x10bf2)\r\n",
	  strlen("Error while rebooting (0x10bf2)\r\n"));
  else if (!strcmp(&str[i], "-info"))
    monit_info(server, fd);
  else
    write(fd, "Unknown option\r\n",
	  strlen("Unknown option\r\n"));
}

