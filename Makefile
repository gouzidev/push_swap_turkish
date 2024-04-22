# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 18:27:01 by sgouzi            #+#    #+#              #
#    Updated: 2024/04/22 11:28:47 by sgouzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_b = checker

BSRC = ./bonus/checker_bonus.c ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c ./bonus/parse_bonus.c ./bonus/operations1_bonus.c ./bonus/operations2_bonus.c ./bonus/split_bonus.c ./bonus/helper_bonus.c ./bonus/linked_list1_bonus.c ./bonus/linked_list2_bonus.c
SRC = main.c parse.c sort.c split.c helper.c push_to_b.c linked_list1.c linked_list2.c operations1.c operations2.c push_to_a.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

SANITIZE = -g3 -fsanitize=address

all : $(NAME)

bonus : $(NAME_b)

%.o: %.c
	$(CC) $(FLAGS) -c $? -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(NAME_b): $(BOBJ)
	$(CC) $(FLAGS) $(BOBJ) -o $(NAME_b)

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME) $(NAME_b)

re: fclean all
