# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 18:27:01 by sgouzi            #+#    #+#              #
#    Updated: 2024/04/21 20:34:55 by sgouzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_b = checker

BSRC = ./bonus/checker_bonus.c ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c ./bonus/parse_bonus.c ./bonus/operations1_bonus.c ./bonus/operations2_bonus.c ./bonus/split_bonus.c ./bonus/helper1_bonus.c ./bonus/helper2_bonus.c ./bonus/linked_list1_bonus.c ./bonus/linked_list2_bonus.c ./bonus/prepare_bonus.c 
SRC = main.c parse.c sort.c split.c helper.c push_to_b.c linked_list1.c linked_list2.c operations1.c operations2.c push_to_a.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CC = cc


all : $(NAME)

bonus : $(NAME_b)

%.o: %.c
	$(CC)  -g3 -fsanitize=address -Wall -Wextra -Werror -c $? -o $@

$(NAME): $(OBJ)
	$(CC)  -g3 -fsanitize=address $(OBJ) -o $(NAME)

$(NAME_b): $(BOBJ)
	$(CC) -g3 -fsanitize=address $(BOBJ) -o $(NAME_b)

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME) $(NAME_b)

re: fclean all
