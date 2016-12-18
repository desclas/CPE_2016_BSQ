/*
** h.h for  in /home/mathias/Bureau/bsk
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Sun Dec 18 17:58:04 2016 Mathias
** Last update Sun Dec 18 20:18:03 2016 Mathias
*/

#ifndef H_H_
# define H_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_all
{
  char *buff;
  int line;
  int len;
  int *tab;
  int i;
  int val;
  int val2;
  int mod;
}		t_all;

void find(t_all *all, char *str);
void complete(t_all *all, char *str);
void step_one(t_all *all);

#endif /* !H_H_ */
