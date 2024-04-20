/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:12 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/20 21:03:47 by sgouzi           ###   ########.fr       */
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

