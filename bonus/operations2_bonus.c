/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:22 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/17 18:36:53 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate_stack(t_stack **stack, char *msg, bool print)
{
	t_stack	*last_a;
	t_stack	*new_head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	new_head = (*stack)->next;
	last_a = get_last(*stack);
	if (last_a)
		last_a->next = *stack;
	(*stack)->next = NULL;
	(*stack) = new_head;
	give_index(*stack, false);
	if (print)
		write(1, msg, ft_strlen(msg));
}
void	rotate_ab(t_stack **a, t_stack **b, bool print)
{
	rotate_stack(a, "", false);
	rotate_stack(b, "", false);
	if (print)
		write(1, "rr\n", 3);
}
void	reverse_rotate_stack(t_stack **stack, char *msg, bool print)
{
	t_stack	*before_last_node;
	t_stack	*last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	before_last_node = before_last(*stack);
	last_node = before_last_node->next;
	last_node->next = *stack;
	before_last_node->next = NULL;
	*stack = last_node;
	give_index(*stack, false);
	if (print)
		write(1, msg, ft_strlen(msg));
}
void	reverse_rotate_ab(t_stack **a, t_stack **b, bool print)
{
	// t_stack	*before_last_node_a;
	// t_stack	*before_last_node_b;
	// t_stack	*last_node_a;
	// t_stack	*last_node_b;
	// if (!a || !(*a) || !(*a)->next)
	// 	return ;
	// if (!b || !(*b) || !(*b)->next)
	// 	return ;
	// before_last_node_a = before_last(*a);
	// before_last_node_b = before_last(*b);
	// last_node_a = before_last_node_a->next;
	// last_node_b = before_last_node_b->next;
	// last_node_a->next = *a;
	// last_node_b->next = *b;
	// before_last_node_a->next = NULL;
	// before_last_node_b->next = NULL;
	// *a = last_node_a;
	// *b = last_node_b;
	reverse_rotate_stack(a, "", false);
	reverse_rotate_stack(b, "", false);
	if (print)
		write(1, "rrr\n", 4);
}
