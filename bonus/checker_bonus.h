/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:06:50 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/22 11:40:07 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	int				n;
	int				i;
	int				push_cost;
	bool			below_median;
	struct s_stack	*next;
	struct s_stack	*target;
}					t_stack;

char				*get_next_line(int fd);
int					we_have_a_problem(int fd, char **str);
char				*ft_strchr(char *s, int c);
char				*ft_strjoin(char *left_str, char *buff);
int					ft_strlen(char *s);
char				*ft_get_line(char *left_str);
char				*get_rest(char *left_str);
int					ft_strcmp(char *s1, char *s2);

/* main.c */
t_stack				*parse(int ac, char *av[]);
int					ft_strlen(char *str);
int					is_empty(char *s);
int					valid(char *num);
bool				handle_rotate(char *op, t_stack **a, t_stack **b);
int					is_stack_sorted(t_stack *head);

/* operations.c */
void				swap_stack(t_stack **head, char *msg, bool print);
void				push_b_to_a(t_stack **a, t_stack **b, bool print);
void				push_a_to_b(t_stack **a, t_stack **b, bool print);
void				rotate_stack(t_stack **stack, char *msg, bool print);
void				rotate_ab(t_stack **a, t_stack **b, bool print);
void				reverse_rotate_stack(t_stack **stack, char *msg,
						bool print);
void				reverse_rotate_ab(t_stack **a, t_stack **b, bool print);
void				swap_both(t_stack **a, t_stack **b, bool print);

t_stack				*parse(int ac, char *av[]);
int					ft_strlen(char *str);
int					is_empty(char *s);
int					valid(char *num);

/* operations.c */
void				swap_stack(t_stack **head, char *msg, bool print);
void				push_from_to(t_stack **from, t_stack **to, char *msg);
void				rotate_stack(t_stack **stack, char *msg, bool print);
void				rotate_ab(t_stack **a, t_stack **b, bool print);
void				reverse_rotate_stack(t_stack **stack, char *msg,
						bool print);
void				reverse_rotate_ab(t_stack **a, t_stack **b, bool print);

/* split.c */
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**free_all(char **res);
int					count_words(char const *s1, char c);
char				**handle_null_malloc(char const *s, char c);
char				**ft_split(char const *s, char c);

/* helper2.c */
t_stack				*get_max(t_stack *stack);
t_stack				*get_min(t_stack *stack);
void				prepare_and_push_to_b(t_stack **a, t_stack **b);

/* helper1.c */
int					ft_atoi(const char *str);
void				print_exit(char *msg);
void				give_index(t_stack *head, bool set_target_null,
						bool reset_push_cost);
int					is_stack_sorted(t_stack *head);
void				sort(t_stack **a, t_stack **b);

/* linked_list.c */
t_stack				*new(int n);
void				push(t_stack **head, t_stack *new);
void				push_end(t_stack **head, t_stack *new);
void				pop(t_stack **head);
int					get_size(t_stack *stack);
t_stack				*duplicate(t_stack *node);
t_stack				*before_last(t_stack *head);
t_stack				*get_last(t_stack *head);
int					exists(t_stack *stack, t_stack *node);
void				clear(t_stack **head);

#endif
