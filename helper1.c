/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:11 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/20 18:40:25 by sgouzi           ###   ########.fr       */
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

int	is_stack_sorted(t_stack *head)
{
	while (head && head->next)
	{
		if (head->n > head->next->n)
			return (0);
		head = head->next;
	}
	return (1);
}
void sort_four(t_stack **a, t_stack **b)
{
	t_stack *min;

	min = get_min(*a);
	while (*a != min)
		rotate_stack(a, "ra\n", true);
	push_from_to(a, b, "pb\n");
	sort_less_than_four(a);
	push_from_to(b, a, "pa\n");
	push_from_to(b, a, "pa\n");
}

void sort_five(t_stack **a, t_stack **b)
{
	t_stack *min;
	give_index(*a, true, true);
	min = get_min(*a);
	if (min->below_median)
		while (*a != min)
			reverse_rotate_stack(a, "rra\n", true);
	else
		while (*a != min)
			rotate_stack(a, "ra\n", true);
	push_from_to(b, a, "pa\n");
	sort_less_than_four(a);
	push_from_to(a, b, "pb\n");
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

void	sort_more(t_stack **a, t_stack **b)
{
	if (get_size(*a) == 5)
	{
		sort_five(a, b);
		return ;
	}
	else if (get_size(*a) == 4)
	{
		sort_four(a, b);
		return ;
	}
	push_from_to(a, b, "pb\n");
	push_from_to(a, b, "pb\n");
	while (get_size(*a) > 3 && !is_stack_sorted(*a))
		prepare_and_push_to_b(a, b);
	if (get_size(*a) < 4 && !is_stack_sorted(*a))
		sort_less_than_four(a);
	while (*b)
		prepare_and_push_to_a(a, b);
	give_index(*a, false, false);
	give_index(*b, false, false);
	clean_up(a);
}
