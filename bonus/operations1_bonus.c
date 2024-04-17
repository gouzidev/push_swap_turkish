/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:19 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/17 18:36:55 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_stack(t_stack **head, char *msg, bool print)
{
	int	temp;

	if ((*head) && (*head)->next)
	{
		temp = (*head)->n;
		(*head)->n = (*head)->next->n;
		(*head)->next->n = temp;
	}
	if (print)
		write(1, msg, ft_strlen(msg));
}
void	push_b_to_a(t_stack **a, t_stack **b, bool print)
{
	t_stack	*temp;

	if (!a || !b)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (*b)
	{
		temp = duplicate(*b);
		pop(b);
		push(a, temp);
	}
	if (*a)
		give_index(*a, false);
	if (*b)
		give_index(*b, false);
	if (print)
		write(1, "pa\n", 3);
}
void	push_a_to_b(t_stack **a, t_stack **b, bool print)
{
	t_stack	*temp;

	if (!a || !b)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (*a)
	{
		temp = duplicate(*a);
		pop(a);
		push(b, temp);
	}
	if (*a)
		give_index(*a, false);
	if (*b)
		give_index(*b, false);
	if (print)
		write(1, "pb\n", 3);
}
