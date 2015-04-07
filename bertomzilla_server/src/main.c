/*
** main.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar  6 18:38:13 2015 Joris Bertomeu
** Last update Fri Mar 27 20:30:47 2015 Joris Bertomeu
*/

#include	"server.h"

void		parse_cmd(t_client *client, char *str)
{
  int		i;
  t_server	*server;
  char		*tmp;

  server = client->server;
  i = 0;
  if (!client->logged && !check_auth(client, str))
    return;
  tmp = get_first(str);
  if (tmp[strlen(tmp) - 1] == '\n')
    tmp[strlen(tmp) - 2] = 0;
  while (server->tab_func_ptr[i])
    {
      if (!strncmp(str, server->tab_func_name[i], strlen(tmp)))
	{
	  free(tmp);
	  server->tab_func_ptr[i](client, str);
	  return;
	}
      i++;
    }
  send_unknown(client, tmp);
  free(tmp);
}

void		close_with_msg(t_client *client, char *msg, int sock)
{
  mysql_notif(client, "sign-out", msg);
  close(sock);
}

void		*connection_handler(void *ptr)
{
  t_client	client;
  int		sock;
  int		size;
  char		buff[4096];

  signal(SIGINT, sigint_handler_client);
  signal(SIGUSR2, sigusr2_handler_client);
  signal(SIGUSR1, sigusr1_handler_client);
  client.server = get_from_shared((int*) ptr);
  sock = client.server->fd_cl;
  send_banner(client.server, sock);
  bzero(buff, 4096);
  init_struct(&client, sock);
  init_new_connection(&client);
  while ((size = read(sock, buff, 4096)) > 0)
    {
      parse_cmd(&client, buff);
      bzero(buff, 4096);
    }
  delete_client_from_list(&client, sock);
  if (size == 0)
    close_with_msg(&client, "Successfully disconnected", sock);
  else if (size == -1)
    close_with_msg(&client, "Error while disconnecting", sock);
  return (NULL);
}

void			wait_clients(t_server *server)
{
  int			fd_client;
  struct sockaddr_in	client;
  int			cl_len;
  int			*new_sock;
  int			pid;

  server->clients_nbr = 0;
  cl_len = sizeof (struct sockaddr_in);
  while ((fd_client = accept(server->fd_srv,
			     (struct sockaddr *) &client,
			     (socklen_t*) &cl_len)))
    {
      new_sock = malloc(sizeof(int));
      *new_sock = fd_client;
      server->fd_cl = fd_client;
      if (is_banned(server, client, fd_client))
	continue;
      if ((pid = fork()) == 0)
	connection_handler(&(server->shared.key_id));
      else
	add_new_client(server, client, fd_client, pid);
    }
}

int		main(int ac, char *argv[])
{
  t_server	server;
  pthread_t	monit_if;
  t_server	*server_ptr;

  (void) ac;
  (void) argv;
  if ((server.shared.key_id = ftok(SHM_KEY_PATH, 0)) == -1)
    show_error("Error while generating key ...\n");
  signal(SIGINT, sigint_handler);
  parse_me_conf_file(&server);
  server.port = atoi(server.conf->net_port);
  server.mysql = (atoi(server.conf->mysql_enabled) == 0) ? 0 : 1;
  init_server(&server);
  init_ptr_func(&server);
  init_clients_tab(&server);
  server.uptime = (int) time(NULL);
  if (!(server_ptr = init_shared_memory(&server)))
    show_error("Error while initializing shared memory");
  if (atoi(server.conf->monit_enabled))
    pthread_create(&monit_if, NULL, monit_managing, (void*) server_ptr);
  wait_clients(server_ptr);
  return (0);
}
