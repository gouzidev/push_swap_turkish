/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:14 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/17 18:58:17 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*duplicate(t_stack *node)
{
	t_stack	*temp;

	if (!node)
		return (NULL);
	temp = new (node->n);
	if (temp == NULL)
		return (NULL);
	return (temp);
}

t_stack	*before_last(t_stack *head)
{
	while (head && head->next && head->next->next)
		head = head->next;
	return (head);
}

t_stack	*get_last(t_stack *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

int	exists(t_stack *stack, t_stack *node)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->n == node->n)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	clear(t_stack **head)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = *head;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
}
