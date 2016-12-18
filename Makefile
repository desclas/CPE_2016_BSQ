##
## Makefile for  in /home/mathias/Bureau/bsk
## 
## Made by Mathias
## Login   <mathias.descoin@epitech.eu@epitech.net>
## 
## Started on  Sun Dec 18 20:26:38 2016 Mathias
## Last update Sun Dec 18 20:28:49 2016 Mathias
##

SRC	=	reste.c	\
		bsq.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
