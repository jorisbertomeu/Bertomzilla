/*
** quit.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Thu Mar 12 20:55:00 2015 Joris Bertomeu
** Last update Fri Mar 27 15:25:08 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_quit(t_client *client, char *str)
{
  (void) str;
  write(client->fd, "221 Goodbye\r\n",
	strlen("221 Goodbye\r\n"));
}
