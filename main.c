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
void set_targets(t_stack *a, t_stack *b)
{
	// find the smallest bigger a node than my b node (we should push it there)
	// if we didnt find than we go for the max node 
	t_stack *curr_a;
	long target;

	while (b)
	{
		b->target = NULL;
		target = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->n < target && curr_a->n > b->n)
			{
				target = curr_a->n;
				b->target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (b->target == NULL)
			b->target = get_min(a);
		b = b->next;
	}
}
void calc_push_cost(t_stack *a, t_stack *b)
{
	// now all b nodes have a target, should get the push cost -> 
	// if (below median)
	// index 
	// else (above median)
	// size - index
	t_stack *curr_b;

	curr_b = b;
	while (curr_b)
	{
		if (curr_b->below_median)
			curr_b->push_cost = get_size(b) - curr_b->i;
		else
			curr_b->push_cost = curr_b->i;
		if (curr_b->target->below_median)
			curr_b->push_cost += get_size(a) - curr_b->target->i;
		else
			curr_b->push_cost += curr_b->target->i;
		curr_b = curr_b->next;
	}
}
t_stack *get_cheapest(t_stack *b)
{
	t_stack *cheapest;

	cheapest = b;
	while (b)
	{
		if (b->push_cost < cheapest->push_cost)
			cheapest = b;
		b = b->next;
	}
	return cheapest;

}


void do_all(t_stack **a, t_stack **b)
{
	t_stack *cheapest;
	t_stack *target;
	t_stack *curr;

    give_index(*a, true);
    give_index(*b, true);
	set_targets(*a, *b);
	calc_push_cost(*a, *b);
	cheapest = get_cheapest(*b);
	target = cheapest->target;
	if (cheapest->below_median)
	{
		if (target->below_median)
		{
			while (cheapest != *b && target != *a)
				reverse_rotate_ab(a, b);
			while (target != *a)
				reverse_rotate_stack(a, "rra\n");
		}
		else
		{
			while (target != *a)
				rotate_stack(a, "ra\n");
		}
		while (cheapest != *b)
			reverse_rotate_stack(b, "rrb\n");
	}
	else if (!cheapest->below_median)
	{
		if (!target->below_median)
		{
			while (cheapest != *b && target != *a)
				rotate_ab(a, b);
			while (target != *a)
				rotate_stack(a, "ra\n");
		}
		else
		{
			while (target != *a)
				reverse_rotate_stack(a, "rra\n");
		}
		while (cheapest != *b)
			rotate_stack(b, "rb\n");
	}
	give_index(*b, 0);
	push_b_to_a(a, b);	
}


void sort_more(t_stack **a, t_stack **b)
{
	t_stack *smallest;
	send_all_to_b(a, b);
	sort_three(a);
	while (*b)
		do_all(a, b);
	give_index(*a, true);
	smallest = get_min(*a);
	if (smallest->below_median)
	{
		while (*a != smallest)
			reverse_rotate_stack(a, "rra\n");
	}
	else
	{
		while (*a != smallest)
			rotate_stack(a, "ra\n");
	}
}


int	main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;
	int		size;
	int		i;

	i = 0;
	b = NULL;
	a = parse(ac, av);

	if (is_stack_sorted(a))
		return 0;
	if (get_size(a) == 2)
		sort_two(&a);
	else if (get_size(a) == 3)
		sort_three(&a);
	else
		sort_more(&a, &b);
}