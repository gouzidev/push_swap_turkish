#include "push_swap.h"

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
		sort_three_and_two(a);
	while (*b)
		prepare_and_push_to_a(a, b);
	clean_up(a);
}

void	sort_three_and_two(t_stack **a)
{
	if (get_size(*a) == 2)
	{
		if (*a && (*a)->next && (*a)->n > (*a)->next->n)
			swap_stack(a, "sa\n", true);
		return ;
	}
	if ((*a)->next == get_max(*a))
	{
		if (get_last(*a)->n < (*a)->n)
			reverse_rotate_stack(a, "rra\n", true);
		else
		{
			swap_stack(a, "sa\n", true);
			rotate_stack(a, "ra\n", true);
		}
	}
	if (*a == get_max(*a))
		rotate_stack(a, "ra\n", true);
	if (get_last(*a) == get_max(*a) && (*a)->n > (*a)->next->n)
		swap_stack(a, "sa\n", true);
}

void sort_four(t_stack **a, t_stack **b)
{
	t_stack *min;

	min = get_min(*a);
	while (*a != min)
		rotate_stack(a, "ra\n", true);
	push_from_to(a, b, "pb\n");
	sort_three_and_two(a);
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
	sort_three_and_two(a);
	push_from_to(a, b, "pb\n");
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
