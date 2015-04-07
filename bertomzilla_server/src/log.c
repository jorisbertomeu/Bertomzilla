/*
** log.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sat Mar 21 23:11:23 2015 Joris Bertomeu
** Last update Fri Mar 27 20:23:14 2015 Joris Bertomeu
*/

#include	"server.h"

int		get_next_nbr(t_client *client)
{
  int		nbr;
  char		str[4096];

  (void) client;
  nbr = 0;
  sprintf(str, "/etc/bertomzilla/bertomeilla.log.%d", nbr);
  while (file_exists(str))
    {
      sprintf(str, "/etc/bertomzilla/bertomeilla.log.%d", nbr);
      nbr++;
    }
  return (nbr);
}

void		move_log_file(t_client *client)
{
  char		trame[4096];
  int		nbr;
  FILE		*fd;

  bzero(trame, 4096);
  nbr = get_next_nbr(client);
  sprintf(trame, "/etc/bertomzilla/bertomzilla.log.%d", nbr);
  if (rename(client->server->conf->log_file, trame) != 0)
    perror("Error while moving log File ");
  else
    printf("Maximum Log File Size reached, moving !\n");
  if (!(fd = fopen(client->server->conf->log_file, "w")))
    return (perror("Error while recreating new Log file "));
  fclose(fd);
}

void		check_log_file(t_client *client)
{
  struct stat	st;
  ssize_t	size;

  stat(client->server->conf->log_file, &st);
  size = st.st_size;
  if (size > atoi(client->server->conf->log_max_size))
    move_log_file(client);
}

void		check_log_file_monit(t_server *server)
{
  (void) server;
}
