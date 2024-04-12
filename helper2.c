#include "push_swap.h"

t_stack *get_max(t_stack *stack)
{
	t_stack *max;
	t_stack *curr;

	curr = stack;
	max = curr;
	while (curr)
	{
		if (curr->n > max->n)
			max = curr;
		curr = curr->next;
	}
	return max;
}
t_stack *get_min(t_stack *stack)
{
	t_stack *min;
	t_stack *curr;

	curr = stack;
	min = curr;
	while (curr)
	{
		if (curr->n < min->n)
			min = curr;
		curr = curr->next;
	}
	return min;
}
void sort_two(t_stack **a)
{
	if (*a && (*a)->next && (*a)->n > (*a)->next->n)
		swap_stack(a, "sa\n");
}
void sort_three(t_stack **a)
{
	if ((*a)->next == get_max(*a))
	{
		if (get_last(*a)->n < (*a)->n)
			reverse_rotate_stack(a, "rra\n");
		else
		{
			swap_stack(a, "sa\n");
			rotate_stack(a, "ra\n");
		}
	}
	if (*a == get_max(*a))
		rotate_stack(a, "ra\n");
	if (get_last(*a) == get_max(*a) && (*a)->n > (*a)->next->n)
		swap_stack(a, "sa\n");
}
void send_all_to_b(t_stack **a, t_stack **b)
{
	while (get_size(*a) > 3)
		push_a_to_b(a, b);
}
