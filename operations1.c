/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:19 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/17 22:49:23 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


void push_from_to(t_stack **to, t_stack **from, char *msg)
{
	t_stack	*new_node;

	if (!to || !from)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (*from)
	{
		new_node = duplicate(*from);
		pop(from);
		push(to, new_node);
	}
	if (*to)
		give_index(*to, false);
	if (*from)
		give_index(*from, false);
	write(1, msg, ft_strlen(msg));
}
