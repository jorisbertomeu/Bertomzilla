/*
** monit_help.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 27 18:42:08 2015 Joris Bertomeu
** Last update Fri Mar 27 19:23:08 2015 Joris Bertomeu
*/

#include	"server.h"

char			*show_help()
{
  char			*buff;

  buff = malloc(4096 * sizeof(char));
  bzero(buff, 4096);
  sprintf(buff, "BertomZilla Monit V0.1<br><br>- client [-list|-ban\
 <ip>|-kick <ip>|-listen]<br>&nbsp;&nbsp;Do some operations about\
 client-side<br><br>- server [-info|-log]<br>&nbsp;&nbsp;\
Do some operations about server-side\r\n");
  return (buff);
}
