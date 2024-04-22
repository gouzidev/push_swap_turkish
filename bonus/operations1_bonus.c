/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:19 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/22 09:28:34 by sgouzi           ###   ########.fr       */
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
	give_index(*head, false, false);
}

void	push_from_to(t_stack **from, t_stack **to, char *msg)
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
		give_index(*to, false, false);
	if (*from)
		give_index(*from, false, false);
	write(1, msg, ft_strlen(msg));
}
