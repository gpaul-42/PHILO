# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 03:32:26 by gpaul             #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/01/03 15:45:24 by gpaul            ###   ########.fr        #
=======
#    Updated: 2021/12/20 17:08:31 by gpaul            ###   ########.fr        #
>>>>>>> 2b6b0fab82a3aa5872c323ba83fd79505011926c
#                                                                              #
# **************************************************************************** #

NAME = philo

_SRCS =		main.c			\
			utils.c			\
			utils2.c		\
			error_free.c	\
			init_parse.c	\
			philo_life.c	\
			philo_action.c	\

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(_SRCS))
SRCO = $(SRCS:.c=.o)

<<<<<<< HEAD
FLAG = -Wall -Wextra -Werror -g -fsanitize=address
=======
FLAG = -Wall -Wextra -Werror -g -fsanitize=thread
>>>>>>> 2b6b0fab82a3aa5872c323ba83fd79505011926c
INC = -I include/

all : $(NAME)

$(NAME) : $(SRCO)
	clang -o $(NAME) $(FLAG) $(SRCO)

%.o : %.c
	clang $(FLAG) -c $< -o $@ $(INC)

clean :
	rm -f $(SRCO)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make

.PHONY			:	all clean fclean re
