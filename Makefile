CC = cc
NAME = push_swap
bonus = bonus
FLAGS = -Wall -Wextra -Werror
LEAK = -fsanitize=address

BSRCS = get_next_line.c get_next_line_utils.c
BOBJS = $(BSRCS:.c=.o)
SRCS = parse.c split.c verify.c helper.c linked_list.c operations.c 
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) main.c $^ -o $(NAME)
	rm -rf $(OBJS)

bonus: $(SRCS) bonus.c $(BOBJS)
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