/*
** opts.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 16:43:42 2015 Joris Bertomeu
** Last update Wed Mar 11 16:43:53 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_opts(t_client *client, char *str)
{
  (void) str;
  write(client->fd, "200 OK\r\n", strlen("200 OK\r\n"));
}

