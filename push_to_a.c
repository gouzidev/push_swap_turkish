/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:25 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/20 17:30:13 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_and_push_to_a(t_stack **a, t_stack **b)
{
	give_index(*a, true, false);
	give_index(*b, true, false);
	set_b_targets_in_a(*a, *b);
	give_index(*a, false, false);
	give_index(*b, false, false);
	prep_for_push(a, (*b)->target, 'a');
	give_index(*a, false, false);
	give_index(*b, false, false);
	push_from_to(b, a, "pa\n");
	give_index(*a, false, false);
	give_index(*b, false, false);
}

void	set_b_targets_in_a(t_stack *a, t_stack *b)
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
	t_stack	*curr_a;
	curr_a = a;

	while (curr_a)
	{
		if (curr_a->below_median && curr_a->target->below_median)
		{
			curr_a->push_cost = get_size(a) - curr_a->i;
			if (get_size(a) - curr_a->i < get_size(b) - curr_a->target->i)
				curr_a->push_cost = get_size(b) - curr_a->target->i;
		}
		else if (!curr_a->below_median && !curr_a->target->below_median)
		{
			curr_a->push_cost = curr_a->i;
			if (curr_a->i < curr_a->target->i)
				curr_a->push_cost = curr_a->target->i;
		}
		else if (!curr_a->below_median && curr_a->target->below_median)
			curr_a->push_cost = curr_a->i + get_size(b) - curr_a->target->i;
		else
			curr_a->push_cost = get_size(a) - curr_a->i + curr_a->target->i;
		curr_a = curr_a->next;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->push_cost < cheapest->push_cost)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}
