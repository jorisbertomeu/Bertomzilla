/*
** signal.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Thu Mar 26 15:40:38 2015 Joris Bertomeu
** Last update Fri Mar 27 19:25:58 2015 Joris Bertomeu
*/

#include	"server.h"

void		shut_server(t_server *server)
{
  shmctl(server->shared.shm_id, IPC_RMID, NULL);
  exit (-1);
}

void		sigint_handler(int sig)
{
  char		c;
  int		key;

  key = ftok(SHM_KEY_PATH, 0);
  signal(sig, SIG_IGN);
  printf("\nDid you hit Ctrl-C?\n"
	 "Do you really want to quit? [y/n] ");
  c = getchar();
  if (c == 'y' || c == 'Y')
    shut_server(get_from_shared(&key));
  else
    signal(SIGINT, sigint_handler);
  getchar();
}

void		sigint_handler_client(int sig)
{
  int		my_pid;
  int		key;
  t_server	*server;

  key = ftok(SHM_KEY_PATH, 0);
  my_pid = (int) getpid();
  server = get_from_shared(&key);
  write(get_fd_with_pid(server, my_pid), "221 Connection closed\r\n",
	strlen("221 Connection closed\r\n"));
  delete_client_from_list_with_pid(server, my_pid);
  signal(sig, SIG_IGN);
  printf("Exiting client process\n");
  exit (-1);
}

void		sigusr2_handler_client(int sig)
{
  int		my_pid;
  int		key;
  t_server	*server;

  key = ftok(SHM_KEY_PATH, 0);
  my_pid = (int) getpid();
  server = get_from_shared(&key);
  write(get_fd_with_pid(server, my_pid), "221 Client instanciation kicked\r\n",
	strlen("221 Client instanciation kicked\r\n"));
  delete_client_from_list_with_pid(server, my_pid);
  signal(sig, SIG_IGN);
  printf("Kicking client process\n");
  exit (-1);
}

void		sigusr1_handler_client(int sig)
{
  int		my_pid;
  int		key;
  t_server	*server;

  key = ftok(SHM_KEY_PATH, 0);
  my_pid = (int) getpid();
  server = get_from_shared(&key);
  write(get_fd_with_pid(server, my_pid), "221 IP Banned\r\n",
	strlen("221 IP Banned\r\n"));
  delete_client_from_list_with_pid_and_ban(server, my_pid);
  signal(sig, SIG_IGN);
  printf("Banning client process\n");
  exit (-1);
}
