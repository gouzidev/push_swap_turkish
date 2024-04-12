#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res > INT_MAX || (res * sign) < INT_MIN)
			print_exit("laaaarge number");
		i++;
	}
	return (res * sign);
}

void	print_exit(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void prepare_and_push(t_stack **a, t_stack **b)
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
		handle_cheapest_below_med(a, b, cheapest);	
	else if (!cheapest->below_median)
		handle_cheapest_above_med(a, b, cheapest);
	push_b_to_a(a, b);	
}

void	give_index(t_stack *head, bool set_target_null)
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
		curr->push_cost = -1;
		curr->below_median = false;
		if (curr->i > median)
			curr->below_median = true;
		curr = curr->next;
	}
}

int	is_stack_sorted(t_stack *head)
{
	while (head && head->next)
	{
		if (head->n > head->next->n)
			return 0;
		head = head->next;
	}
	return 1;
}

void sort_more(t_stack **a, t_stack **b)
{
	t_stack *smallest;
	send_all_to_b(a, b);
	sort_three(a);
	while (*b)
		prepare_and_push(a, b);
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
