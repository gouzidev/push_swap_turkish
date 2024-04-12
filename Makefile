CC = cc
NAME = push_swap
bonus = bonus
FLAGS = -Wall -Wextra -Werror
LEAK = -fsanitize=address

BSRCS = get_next_line.c get_next_line_utils.c parse.c operations1.c operations2.c split.c verify.c helper1.c helper2.c linked_list1.c linked_list2.c prepare.c
BOBJS = $(BSRCS:.c=.o)
SRCS = parse.c split.c verify.c helper1.c helper2.c linked_list1.c linked_list2.c operations1.c operations2.c prepare.c
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) main.c $^ -o $(NAME)
	rm -rf $(OBJS)

bonus: bonus.c $(BOBJS)
	$(CC) $? -o $(bonus)

%o:%c
	$(CC)  -c $< 
re:	fclean all

clean:
	rm -rf $(OBJS)
	rm -rf $(BOBJS)

fclean:	clean
	rm -rf $(NAME)
	rm -rf $(CHECKER)