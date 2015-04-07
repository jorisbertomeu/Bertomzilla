/*
** retr.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 16:13:51 2015 Joris Bertomeu
** Last update Sat Mar 28 16:55:32 2015 Joris Bertomeu
*/

#include	"server.h"

RSA		*createRSA(unsigned char * key, int public)
{
  RSA		*rsa;
  BIO		*keybio;

  keybio = BIO_new_mem_buf(key, -1);
  if (!keybio)
    show_error("Error while creating key");
  if (public)
    rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa, NULL, NULL);
  else
    rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, NULL, NULL);
  if (!rsa)
    show_error("Error while creating RSA Key");
  return (rsa);
}

int		public_encrypt(unsigned char * data, int data_len,
			       unsigned char * key, unsigned char *encrypted)
{
  RSA		*rsa;

  rsa = createRSA(key, 1);
  return (RSA_public_encrypt(data_len, data, encrypted, rsa,
			     RSA_PKCS1_PADDING));
}

void			process_sending(t_client *client, FILE *fd,
				      t_file *file, int client_fd)
{
  unsigned char		buff[4096];
  int			times[2];
  ssize_t		n;

  file->size = 0;
  times[0] = time(NULL);
  while (!feof(fd))
    {
      bzero(buff, 4096);
      n = fread(buff, 1, 4096, fd);
      write(client_fd, buff, n);
      file->size += n;
    }
  times[1] = time(NULL);
  close(client_fd);
  fclose(fd);
  close(client->pasv_sck);
  file->time = times[1] - times[0];
}

int			preli_test_retr(t_client *client)
{
  if (!is_authorized(client, 0))
    return (0);
  if (!is_passive(client))
    return (0);
  return (1);
}

void			ftp_retr(t_client *client, char *str)
{
  FILE			*fd;
  char			*arg;
  int			client_fd;
  struct sockaddr_in	cliaddr;
  socklen_t		clilen;
  t_file		file;

  if (!preli_test_retr(client))
    return;
  arg = get_cmd(str, 4);
  if (!file_exists(arg))
    return (send_error(client));
  clilen = sizeof(cliaddr);
  if (!is_authorized_path(client, arg))
    return (bad_path(client));
  client_fd = accept(client->pasv_sck,
		     (struct sockaddr *)&cliaddr, &clilen);
  write(client->fd, "150 Accepted data connection\r\n",
	strlen("150 Accepted data connection\r\n"));
  if (!(fd = open_file(client, arg, 0, 1)))
    return (send_error(client));
  process_sending(client, fd, &file, client_fd);
  sprintf(file.filename, "%s", arg);
  do_end_retr(client, &file);
}
