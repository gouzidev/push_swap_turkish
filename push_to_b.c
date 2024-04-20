#include "push_swap.h"

void	prepare_and_push_to_b(t_stack **a, t_stack **b)
{
    t_stack *cheapest;
    t_stack *target;

    set_a_targets_in_b(*a, *b);
    calc_push_cost(*a, *b);
    cheapest = get_cheapest(*a);
    target = cheapest->target;
    bring_to_top(a, b, cheapest);
    clean_top(a, cheapest, 'a');
    clean_top(b, cheapest->target, 'b');
    push_from_to(a, b, "pb\n");
}

void	set_a_targets_in_b(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;
	long	target;

	while (a)
	{
		a->target = NULL;
		target = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->n > target && curr_b->n < a->n)
			{
				target = curr_b->n;
				a->target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (a->target == NULL)
			a->target = get_max(b);
		a = a->next;
	}
}

void bring_to_top(t_stack **a, t_stack **b, t_stack *cheapest)
{
    if (cheapest->below_median && cheapest->target->below_median)
    {
        while (cheapest != *a && cheapest->target != *b)
            reverse_rotate_ab(a, b, true);
    }
    else if (!cheapest->below_median && !cheapest->target->below_median)
        while (cheapest != *a && cheapest->target != *b)
            rotate_ab(a, b, true);
}

void clean_top(t_stack **stack, t_stack *node, char stackname)
{
    while (*stack != node)
    {
        if (stackname == 'a')
        {
            if (node->below_median)
                reverse_rotate_stack(stack, "rra\n", true);
            else
                rotate_stack(stack, "ra\n", true);
        }
        else
        {
            if (node->below_median)
                reverse_rotate_stack(stack, "rrb\n", true);
            else
                rotate_stack(stack, "rb\n", true);
        }
    }
}
