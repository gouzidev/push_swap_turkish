/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:12 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/17 21:47:51 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max;
	t_stack	*curr;

	curr = stack;
	max = curr;
	while (curr)
	{
		if (curr->n > max->n)
			max = curr;
		curr = curr->next;
	}
	return (max);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*curr;

	curr = stack;
	min = curr;
	while (curr)
	{
		if (curr->n < min->n)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

void	sort_less_than_four(t_stack **a)
{
	if (get_size(*a) == 2)
	{
		if (*a && (*a)->next && (*a)->n > (*a)->next->n)
			swap_stack(a, "sa\n", true);
		return ;
	}
	if ((*a)->next == get_max(*a))
	{
		if (get_last(*a)->n < (*a)->n)
			reverse_rotate_stack(a, "rra\n", true);
		else
		{
			swap_stack(a, "sa\n", true);
			rotate_stack(a, "ra\n", true);
		}
	}
	if (*a == get_max(*a))
		rotate_stack(a, "ra\n", true);
	if (get_last(*a) == get_max(*a) && (*a)->n > (*a)->next->n)
		swap_stack(a, "sa\n", true);
}
