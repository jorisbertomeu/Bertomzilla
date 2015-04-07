/*
** syst.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 16:42:20 2015 Joris Bertomeu
** Last update Wed Mar 11 16:42:42 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_syst(t_client *client, char *str)
{
  (void) str;
  write(client->fd, "215 UNIX Type: L8\r\n", strlen("215 UNIX Type: L8\r\n"));
}

