/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:13 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/17 18:57:38 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new(int n)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == 0)
		return (0);
	new_node->next = NULL;
	new_node->n = n;
	return (new_node);
}

void	push(t_stack **head, t_stack *new)
{
	if (!new || !head)
		return ;
	new->next = *head;
	*head = new;
	give_index(*head, false);
}

void	push_end(t_stack **head, t_stack *new)
{
	t_stack	*last;

	if (!new || !head)
		return ;
	if (!*head)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		last = get_last(*head);
		last->next = new;
	}
	give_index(*head, false);
}

void	pop(t_stack **head)
{
	t_stack	*temp;

	if (!*head)
		return ;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

int	get_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
