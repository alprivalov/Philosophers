NAME		= philo
HEADER		= src/philo.h
CFLAGS		= -lpthread
CC			= gcc -g -Wall -Werror -Wextra
 

SRC_CLIENT	= src/philo.c \

SRC_UTILS	=	src/utils.c \
				src/ft_check_argument.c \
				src/ft_init_argument.c \
				src/ft_mutex.c \
				src/ft_init.c \
				src/ft_actions.c \
				src/ft_sleep.c \
				src/ft_create_thread.c \
				src/ft_death_thread.c \
                        
CLIENT		= $(SRC_CLIENT:.c=.o)

all:  $(NAME)

$(NAME): $(CLIENT)
	$(CC) $(CFLAGS) $(CLIENT) $(SRC_UTILS) -lpthread $(HEADER) -o $@

clean:
	$(RM) $(CLIENT)

fclean:	clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY:            all clean fclean re
