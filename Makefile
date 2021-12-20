# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 03:32:26 by gpaul             #+#    #+#              #
#    Updated: 2021/12/19 23:52:07 by gpaul            ###   ########.fr        #
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

FLAG = -Wall -Wextra -Werror #-g -fsanitize=thread
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
