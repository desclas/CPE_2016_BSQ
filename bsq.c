/*
** bsq.c for  in /home/mathias/Bureau/bsk
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Dec 12 18:57:34 2016 Mathias
** Last update Sun Dec 18 20:19:02 2016 Mathias
*/

#include "h.h"

void step_two(t_all *all)
{
  if (all->val2 == all->val
      && all->buff[all->i + all->mod + (all->line * (all->val2 - 1))] != 'o'
      && all->mod == all->val - 1)
    {
      all->tab[2] += 1;
      all->tab[0] = all->i / all->line;
      all->tab[1] = all->i % all->line;
      all->val += 1;
      all->i = 0;
    }
}

void algo(t_all *all)
{
  all->mod = 0;
  all->val = 1;
  all->i = 0;
  while (all->buff[all->i] != '\0')
    {
      if (all->buff[all->i] != 'o')
	{
	  step_one(all);
	  step_two(all);
	}
      all->i += 1;
    }
}

void place(t_all *all)
{
  int count;
  
  all->i = 0;
  while (all->tab[0] != 0)
    {
      all->i += 1;
      while (all->buff[all->i] != '\n')
	all->i += 1;
      all->tab[0] -= 1;
    }
  all->i += all->tab[1] + 1;
  while (all->tab[0] != all->tab[2])
    {
      count = 0;
      while (count != all->tab[2])
	{
	  all->buff[all->i] = 'X';
	  all->i += 1;
	  count += 1;
	}
      while (all->buff[all->i] != '\n')
	all->i += 1;
      all->i += all->tab[1] + 1;
      all->tab[0] += 1;
    }
}

int main(int av, char **ac)
{
  t_all *all;

  all = malloc(sizeof(*all));
  all->tab = malloc(sizeof(int) * 3);
  find(all, ac[1]);
  free(all->buff);
  complete(all, ac[1]);
  algo(all);
  place(all);
  write(1, all->buff, all->len + 1);
  free(all->buff);
  free(all->tab);
  free(all);
}
