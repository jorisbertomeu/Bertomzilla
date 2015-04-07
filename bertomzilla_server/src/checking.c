/*
** checking.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 20:25:49 2015 Joris Bertomeu
** Last update Fri Mar 27 20:28:47 2015 Joris Bertomeu
*/

#include	"server.h"

void		send_unknown(t_client *client, char *str)
{
  char		buff[4096];

  bzero(buff, 4096);
  sprintf(buff, "550 Unknown command \"%s\"\r\n", str);
  write(client->fd, buff, strlen(buff));
}
