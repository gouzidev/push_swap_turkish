/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:11 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/21 12:31:32 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_exit(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	give_index(t_stack *head, bool set_target_null, bool reset_push_cost)
{
	t_stack	*curr;
	int		i;
	int		median;

	if (!head)
		return ;
	median = get_size(head) / 2;
	curr = head;
	i = 0;
	while (curr)
	{
		if (set_target_null == true)
			curr->target = NULL;
		curr->i = i++;
		if (reset_push_cost == true)
			curr->push_cost = -1;
		curr->below_median = false;
		if (curr->i >= median)
			curr->below_median = true;
		curr = curr->next;
	}
}

void clean_up(t_stack **a)
{
	t_stack	*smallest;

	smallest = get_min(*a);
	if (smallest->below_median)
	{
		while (*a != smallest)
			reverse_rotate_stack(a, "rra\n", true);
	}
	else
	{
		while (*a != smallest)
			rotate_stack(a, "ra\n", true);
	}
}

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
