/*
** pasv.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 16:45:37 2015 Joris Bertomeu
** Last update Sat Mar 21 16:29:35 2015 Joris Bertomeu
*/

#include		"server.h"

int			set_pasv(t_client *client, int p1, int p2)
{
  struct sockaddr_in	servaddr;

  if (!p1 && !p2)
    return (0);
  client->pasv_sck = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(p1 * 256 + p2);
  if (bind(client->pasv_sck, (struct sockaddr *) &servaddr,
	   sizeof(servaddr)) == -1)
    {
      close(client->pasv_sck);
      return (0);
    }
  return (1);
}

char			*replace_me_a_char(char *str, char orig, char sep, int s)
{
  char			*final;
  int			i;

  close(s);
  final = malloc((strlen(str) + 1) * sizeof(char));
  bzero(final, strlen(str) + 1);
  strcpy(final, str);
  i = 0;
  while (final[i])
    {
      if (final[i] == orig)
	final[i] = sep;
      i++;
    }
  return (final);
}

char			*get_my_ip(char *iface, char sep, int i)
{
  int			s;
  struct ifconf		ifconf;
  struct ifreq		ifr[50];
  char			ip[INET_ADDRSTRLEN];
  struct sockaddr_in	*s_in;
  int			ifs;

  s = socket(AF_INET, SOCK_STREAM, 0);
  ifconf.ifc_buf = (char*) ifr;
  ifconf.ifc_len = sizeof(ifr);
  if (ioctl(s, SIOCGIFCONF, &ifconf) == -1)
    return ("0,0,0,0");
  ifs = ifconf.ifc_len / sizeof(ifr[0]);
  while (i < ifs)
    {
      s_in = (struct sockaddr_in *) &ifr[i].ifr_addr;
      if (!inet_ntop(AF_INET, &s_in->sin_addr, ip, sizeof(ip)))
	return ("0,0,0,0");
      if (!strcmp(ifr[i].ifr_name, iface))
	return (replace_me_a_char(ip, '.', sep, s));
      i++;
    }
  close(s);
  return ("0,0,0,0");
}

void			ftp_pasv(t_client *client, char *str)
{
  char			trame[4096];
  int			p1;
  int			p2;
  int			i;

  (void) str;
  i = 0;
  p1 = 0;
  p2 = 0;
  while (!set_pasv(client, p1, p2))
    {
      srand(i * 4);
      p1 = 200 + rand() % 50;
      p2 = 100 + rand() % 50;
      i++;
    }
  client->passive = 1;
  mysql_notif(client, "gears", "Passive mode enabled");
  sprintf(trame, "227 Entering Passive Mode (%s,%d,%d)\r\n",
	  get_my_ip(client->server->conf->net_iface, ',', 0), p1, p2);
  listen(client->pasv_sck, 1024);
  write(client->fd, trame, strlen(trame));
}
