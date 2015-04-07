/*
** feat.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 16:43:07 2015 Joris Bertomeu
** Last update Wed Mar 11 16:43:22 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_feat(t_client *client, char *str)
{
  (void) str;
  write(client->fd, "211-Extensions supported:\nSIZE\nUTF8\nPASV\n211 End.\r\n",
	strlen("211-Extensions supported:\nSIZE\nUTF8\nPASV\n211 End.\r\n"));
}

