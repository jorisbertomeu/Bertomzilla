/*
** shared.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 18:44:22 2015 Joris Bertomeu
** Last update Fri Mar 27 18:44:42 2015 Joris Bertomeu
*/

#include	"server.h"

t_server		*init_shared_memory(t_server *server)
{
  void			*mem;

  if ((server->shared.shm_id = shmget(server->shared.key_id,
				      sizeof(*server),
				      SHM_R | SHM_W)) == -1)
    {
      if ((server->shared.shm_id = shmget(server->shared.key_id,
					  sizeof(*server),
					  IPC_CREAT | SHM_R | SHM_W)) == -1)
	show_error("Error while creating shared memory\n");
      if (!(mem = shmat(server->shared.shm_id, NULL, SHM_R | SHM_W)))
	show_error("Error while attaching sharing memory\n");
      memcpy(mem, server, sizeof(*server));
      return ((t_server*) mem);
    }
  return (NULL);
}

t_server		*get_from_shared(int *key_id)
{
  int			shm_id;
  void			*mem;

  if ((shm_id = shmget(*key_id, sizeof(t_server),
		       SHM_R | SHM_W)) != -1)
    {
      if (!(mem = shmat(shm_id, NULL, SHM_R | SHM_W)))
	show_error("Error while attaching sharing memory\n");
      return ((t_server*) mem);
    }
  else
    show_error("Error, Shared memory not created for fork !");
  return (NULL);
}

