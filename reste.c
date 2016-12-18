/*
** reste.c for  in /home/mathias/Bureau/bsk
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Sun Dec 18 19:57:35 2016 Mathias
** Last update Sun Dec 18 19:59:13 2016 Mathias
*/

#include "h.h"

void find(t_all *all, char *str)
{
  int fd;
  int st;

  st = 4;
  all->len = 0;
  all->line = 0;
  fd = open(str, O_RDONLY);
  all->buff = malloc(sizeof(char) * 2);
  while (all->buff[0] != '\n')
    read(fd, all->buff, 1);
  read(fd, all->buff, 1);
  all->len += 1;
  all->line += 1;
  while (all->buff[0] != '\n')
    {
      read(fd, all->buff, 1);
      all->len += 1;
      all->line += 1;
    }
  while (st != 0 && st != -1)
    {
      st = read(fd, all->buff, 1);
      all->len += 1;
    }
  close(fd);
}

void complete(t_all *all, char *str)
{
  int fd;
  char c;

  fd = open(str, O_RDONLY);
  while (c != '\n')
    read(fd, &c, 1);
  all->buff = malloc(sizeof(char) * all->len + 2);
  read(fd, all->buff, all->len + 1);
  close(fd);
}

void step_one(t_all *all)
{
  all->val2 = 0;
  while (all->val2 != all->val
	 && all->buff[all->i + all->mod + (all->line * all->val2)] != 'o'
	 && (all->i % all->line) + all->val <= all->line
	 && all->i + all->val + (all->line * all->val) <= all->len)
    {
      all->mod = 0;
      while (all->mod != all->val - 1
	     && all->buff[all->i + all->mod + (all->line * all->val2)] != 'o')
	all->mod += 1;
      if (all->buff[all->i + all->mod + (all->line * all->val2)] != 'o')
	all->val2 += 1;
    }
}
