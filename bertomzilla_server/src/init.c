/*
** init.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/server/src
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 18 13:45:32 2015 Joris Bertomeu
** Last update Sat Mar 21 17:13:22 2015 Joris Bertomeu
*/

#include	"server.h"

int		check_arg(t_server *server, int ac, char **argv)
{
  int		i;

  i = 0;
  server->mysql = 0;
  if (ac < 2)
    return (0);
  while (i < ac)
    {
      if (!strcmp(argv[i], "--with-sql"))
	{
	  server->mysql = 1;
	  printf("[INFO] SQL Mode enabled\n");
	}
      else if (!strcmp(argv[i], "--help"))
	{
	  printf("Usage : %s <Port> [--with-sql]\n", argv[0]);
	  exit (-1);
	}
      i++;
    }
  return (1);
}

void		init_struct(t_client *client, int sock)
{
  client->fd = sock;
  client->logged = 0;
  client->passive = 0;
  client->rnfr = 0;
  client->rsa = 0;
}

void		init_ptr_func(t_server *server)
{
  init_tab_func_names(server);
  init_tab_func_ptr(server);
}

void		show_error(char *str)
{
  printf("%s\n", str);
  exit (-1);
}

char		*get_first(char *str)
{
  char		*new;

  if (!(new = malloc((strlen(str) + 1) * sizeof(*new))))
    show_error("Error while mallocing !");
  bzero(new, strlen(str) + 1);
  strcpy(new, str);
  return (strtok(new, " "));
}
