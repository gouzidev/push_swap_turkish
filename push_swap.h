/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:26 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/17 22:52:16 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				n;
	int				i;
	int				push_cost;
	bool			below_median;
	struct s_stack	*next;
	struct s_stack	*target;
}					t_stack;

/* main.c */
t_stack				*parse(int ac, char *av[]);
int					ft_strlen(char *str);
int					is_empty(char *s);
int					valid(char *num);

/* operations.c */
void				swap_stack(t_stack **head, char *msg, bool print);
void				push_b_to_a(t_stack **a, t_stack **b, bool print);
void				push_a_to_b(t_stack **a, t_stack **b, bool print);
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
void				sort_two(t_stack **a);
void				sort_less_than_four(t_stack **a);
void				send_all_to_b(t_stack **a, t_stack **b);

/* helper1.c */
int					ft_atoi(const char *str);
void				print_exit(char *msg);
void				give_index(t_stack *head, bool set_target_null);
int					is_stack_sorted(t_stack *head);
void				sort_more(t_stack **a, t_stack **b);

void				prepare_and_push(t_stack **a, t_stack **b);

/* prepare.c */
void				set_targets(t_stack *a, t_stack *b);
void				calc_push_cost(t_stack *a, t_stack *b);
t_stack				*get_cheapest(t_stack *b);
void				handle_cheapest_above_med(t_stack **a, t_stack **b,
						t_stack *cheapest);
void				handle_cheapest_below_med(t_stack **a, t_stack **b,
						t_stack *cheapest);

void				give_index(t_stack *head, bool set_target_null);

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
