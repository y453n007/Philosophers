# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 13:21:55 by yelgharo          #+#    #+#              #
#    Updated: 2022/05/25 00:13:43 by yelgharo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_philo.a

define PHILO
 			!! sɹǝɥdosoʅᴉɥԀ !!
endef
export PHILO

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC := philo.c tools.c tasks.c

OBJ := $(SRC:.c=.o)

all : $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $<

$(NAME): text $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -pthread -o philo -g
	
clean : 
	@rm -f $(OBJ) philo
	

fclean : clean
	@rm -f $(NAME)

re : fclean all

text :
	@echo "$${PHILO}"

.PHONY : clean fclean re