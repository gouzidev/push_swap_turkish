/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:25 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/17 22:03:38 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_targets(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	long	target;

	while (b)
	{
		b->target = NULL;
		target = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->n < target && curr_a->n > b->n)
			{
				target = curr_a->n;
				b->target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (b->target == NULL)
			b->target = get_min(a);
		b = b->next;
	}
}

void	calc_push_cost(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;

	curr_b = b;
	while (curr_b)
	{
		if (curr_b->below_median)
			curr_b->push_cost = get_size(b) - curr_b->i;
		else
			curr_b->push_cost = curr_b->i;
		if (curr_b->target->below_median)
			curr_b->push_cost += get_size(a) - curr_b->target->i;
		else
			curr_b->push_cost += curr_b->target->i;
		curr_b = curr_b->next;
	}
}

t_stack	*get_cheapest(t_stack *b)
{
	t_stack	*cheapest;

	cheapest = b;
	while (b)
	{
		if (b->push_cost < cheapest->push_cost)
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

void	handle_cheapest_above_med(t_stack **a, t_stack **b, t_stack *cheapest)
{
	t_stack	*target;

	target = cheapest->target;
	if (!target->below_median)
	{
		while (cheapest != *b && target != *a)
			rotate_ab(a, b, true);
		while (target != *a)
			rotate_stack(a, "ra\n", true);
	}
	else
	{
		while (target != *a)
			reverse_rotate_stack(a, "rra\n", true);
	}
	while (cheapest != *b)
		rotate_stack(b, "rb\n", true);
}

void	handle_cheapest_below_med(t_stack **a, t_stack **b, t_stack *cheapest)
{
	t_stack	*target;

	target = cheapest->target;
	if (target->below_median)
	{
		while (cheapest != *b && target != *a)
			reverse_rotate_ab(a, b, true);
		while (target != *a)
			reverse_rotate_stack(a, "rra\n", true);
	}
	else
	{
		while (target != *a)
			rotate_stack(a, "ra\n", true);
	}
	while (cheapest != *b)
		reverse_rotate_stack(b, "rrb\n", true);
}
