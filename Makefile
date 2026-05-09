##
## EPITECH PROJECT, 2026
## Panoramix
## File description:
## Makefile
##

.PHONY: all clean fclean re

CC = clang

CFLAGS = -Wall -Wextra -g -I./include

LDFLAGS = -lpthread

SRC =	./src/main.c \
		./src/druid.c \
		./src/villager.c \
		./src/villager_actions.c \
		./src/print_usage.c \
		./src/semaphore.c \
		./src/pot.c \
		./src/simulation.c \

OBJ = $(SRC:.c=.o)

NAME = panoramix

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all
