#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

char	*get_next_line(int fd);
int		we_have_a_problem(int fd, char **str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *left_str);
char	*get_rest(char *left_str);


typedef struct s_stack {
    int n;
    int i;
	int	push_cost;
	bool below_median;
    struct s_stack *next;
    struct s_stack *target;
}   t_stack;

/* main.c */
t_stack *parse(int ac, char *av[]);

// void sort_two(t_stack **head, char *msg);
// void sort_three(t_stack **a, t_stack **b);
// void sort_four(t_stack **a, t_stack **b);
// void sort_five(t_stack **a, t_stack **b);

/* operations.c */
void	swap_stack(t_stack **head, char *msg);
void	push_b_to_a(t_stack **a, t_stack **b);
void	push_a_to_b(t_stack **a, t_stack **b);
void	rotate_stack(t_stack **stack, char *msg);
void	rotate_ab(t_stack **a, t_stack **b);
void	reverse_rotate_stack(t_stack **stack, char *msg);
void	reverse_rotate_ab(t_stack **a, t_stack **b);

/* split.c */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**free_all(char **res);
int	count_words(char const *s1, char c);
char	**handle_null_malloc(char const *s, char c);
char	**ft_split(char const *s, char c);

/* helper.c */
int	ft_atoi(const char *str);
void print_exit(char *msg);
int	is_stack_sorted(t_stack *head);

void give_index(t_stack *head, bool set_target_null);

/* linked_list.c */
t_stack *new (int n);
void	push(t_stack **head, t_stack *new);
void	push_end(t_stack **head, t_stack *new);
void	pop(t_stack **head);
int	get_size(t_stack *stack);
t_stack	*duplicate(t_stack *node);
t_stack	*before_last(t_stack *head);
t_stack	*get_last(t_stack *head);
int	exists(t_stack *stack, t_stack *node);
void	clear(t_stack **head);


int	is_empty(char *s);
int	valid(char *num);
#endif
