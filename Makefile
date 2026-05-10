##
## EPITECH PROJECT, 2026
## Panoramix
## File description:
## Makefile
##

.PHONY: all clean fclean re help

CC = clang

CFLAGS = -Wall -Wextra -g -I./include

LDFLAGS = -lpthread

SRC =	./src/main.c \
		./src/druid/druid.c \
		./src/druid/druid_actions.c \
		./src/villager/villager.c \
		./src/villager/villager_actions.c \
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

help:
	@echo "Available rules:"
	@echo "	all	-> build the project"
	@echo "	clean	-> remove object files"
	@echo "	fclean	-> remove object files and binary"
	@echo "	re	-> rebuild from scratch"
	@echo "	help	-> show this message"
