/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:11 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/22 09:48:55 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
