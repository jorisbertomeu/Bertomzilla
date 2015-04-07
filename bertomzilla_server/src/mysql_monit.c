/*
** mysql_monit.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 20:11:36 2015 Joris Bertomeu
** Last update Fri Mar 27 20:20:56 2015 Joris Bertomeu
*/

#include	"server.h"

void		mysql_notif_monit(t_server *server, char *icon, char *label)
{
  char	requete[4096];

  bzero(requete, 4096);
  if (server->conf->log_enabled)
    {
      check_log_file_monit(server);
      server->conf->log_fd = fopen(server->conf->log_file,
					   "a+");
      sprintf(requete,
	      "[%d][%s]\t%s\n", (int) time(NULL), icon, label);
      fwrite(requete, 1, strlen(requete), server->conf->log_fd);
      fclose(server->conf->log_fd);
    }
}

