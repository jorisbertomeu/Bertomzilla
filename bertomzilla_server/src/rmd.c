/*
** rmd.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 17:36:36 2015 Joris Bertomeu
** Last update Sat Mar 21 17:57:04 2015 Joris Bertomeu
*/

#include	"server.h"

int		browse_dir(DIR *d, int r, char *path, int r2)
{
  char		*buf;
  struct stat	statbuf;
  struct dirent *p;

  while (!r && (p = readdir(d)))
    {
      r2 = -1;
      if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
	continue;
      if ((buf = malloc(strlen(path) + strlen(p->d_name) + 2)))
	{
	  snprintf(buf, strlen(path) + strlen(p->d_name) + 2,
		   "%s/%s", path, p->d_name);
	  if (!stat(buf, &statbuf))
	    {
	      if (S_ISDIR(statbuf.st_mode))
		r2 = remove_directory(buf);
	      else
		r2 = unlink(buf);
	    }
	  free(buf);
	}
      r = r2;
    }
  return (r);
}

int		remove_directory(char *path)
{
  DIR		*d;
  int		r;

  r = -1;
  if ((d = opendir(path)))
    {
      r = browse_dir(d, 0, path, -1);
      closedir(d);
    }
  if (!r)
    r = rmdir(path);
  return (r);
}

void		ftp_rmd(t_client *client, char *str)
{
  char		*arg;
  char		trame[4096];

  arg = get_cmd(str, 3);
  if (!is_authorized(client, 3))
    return;
  if (remove_directory(arg) != 0)
    {
      sprintf(trame, "Error while deleting file or directory : %s",
	      strerror(errno));
      mysql_notif(client, "remove", trame);
      sprintf(trame, "550 %s\r\n", strerror(errno));
      write(client->fd, trame, strlen(trame));
    }
  else
    {
      sprintf(trame, "Directory or file \"%s\" deleted successfully !", arg);
      mysql_notif(client, "remove", trame);
      sprintf(trame, "250 \"%s\" : Deleted successfully\r\n", arg);
      write(client->fd, trame, strlen(trame));
    }
}
