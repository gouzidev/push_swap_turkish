/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:22 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/22 09:28:34 by sgouzi           ###   ########.fr       */
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
	give_index(*stack, false, false);
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
	give_index(*stack, false, false);
	if (print)
		write(1, msg, ft_strlen(msg));
}

void	reverse_rotate_ab(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate_stack(a, "", false);
	reverse_rotate_stack(b, "", false);
	if (print)
		write(1, "rrr\n", 4);
}
