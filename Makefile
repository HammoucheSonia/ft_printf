# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shammouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 18:09:35 by shammouc          #+#    #+#              #
#    Updated: 2021/12/14 16:04:21 by shammouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

FLAG = -Wall -Werror -Wextra

SRC = ft_itoa_u.c ft_itoa.c ft_itoa_base.c ft_printf.c ft_putchar.c ft_strdup.c ft_putstr.c ft_strlen.c ft_itoa_base_2.c 

EXEC = libftprintf.a

OBJ = $(SRC:.c=.o)

all : $(EXEC)
%.o : %.c
	$(CC) $(FLAG) -o $@ -c $<

$(EXEC) : $(OBJ)
	ar rcs $(EXEC) $^

clean :
	rm -f $(OBJ) 

fclean : clean
	 rm -f $(EXEC)

re : fclean all

.PHONY: all clean fclean re
