#include "push_swap.h"

// void swap_stack_ab(t_stack **a, t_stack **b)
// {
//     t_stack *tmp1;
//     t_stack *tmp2;
//     if ((*a) && (*a)->next)
//     {
//         tmp1 = new ((*a)->n);
//         pop(a);
//         tmp2 = new ((*a)->n);
//         pop(a);
//         push(a, tmp1);
//         push(a, tmp2);
//     }
// }

int	*make_arr(t_stack *head, int *arr_size)
{
	int	*arr;
	int	i;

	*arr_size = size(head);
	arr = malloc((*arr_size + 1) * sizeof(int));
	i = 0;
	while (head && i < *arr_size)
	{
		arr[i++] = head->n;
		head = head->next;
	}
	i = 0;
	return (arr);
}
void	sort_arr(int *arr, int arr_size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < arr_size)
	{
		j = 0;
		while (j < arr_size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
void sort_two(t_stack **head, char *msg)
{
	if ((*head)->n > (*head)->next->n)
		swap_stack(head, msg);
}
void sort_three(t_stack **a, t_stack **b)
{
	t_stack *min;

	min = find_min(*a);
	if (min->i == 1)
	{
		if ((*a)->n > (*a)->next->next->n)
			rotate_stack(a, "ra");
		else
			swap_stack(a, "sa");
	}
	else if (min->i == 2)
	{
		if ((*a)->n > (*a)->next->n)
		{
			swap_stack(a, "sa");
			reverse_rotate_stack(a, "rra");
		}
		else
		{
			swap_stack(a, "sa");
			rotate_stack(a, "ra");
		}
	}
	else if (min->i == 0)
	{
		if ((*a)->next->n > (*a)->next->next->n)
		{
			swap_stack(a, "sa");
			rotate_stack(a, "ra");
		}
	}
}
void sort_four(t_stack **a, t_stack **b)
{
	t_stack *min;

	min = find_min(*a);
	if (min->i > 2)
	{
		while (*a != min)
			reverse_rotate_stack(a, "rra");
	}
	else
	{
		while (*a != min)
			rotate_stack(a, "ra");
	}
	push_a_to_b(a, b);
	sort_three(a, b);
	push_b_to_a(a, b, "pb");
}
void sort_five(t_stack **a, t_stack **b)
{
	t_stack *min;

	min = find_min(*a);
	if (min->i > 2)
	{
		while (*a != min)
			reverse_rotate_stack(a, "rra");
	}
	else
	{
		while (*a != min)
			rotate_stack(a, "ra");
	}
	push_a_to_b(a, b);
	sort_four(a, b);
	push_b_to_a(a, b, "pb");
}

t_stack	*find_max_usin_arr(t_stack *stack, t_data *data)
{
	t_stack	*max_node;

	max_node = NULL;
	if (data->curr_max_i < 0)
		return NULL;
	while (stack)
	{
		if (stack->n == data->arr[data->curr_max_i])
			max_node = stack;
		stack = stack->next;
	}
	return max_node;
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;

	min_node = stack;
	while (stack)
	{
		if (stack->n < min_node->n)
			min_node = stack;
		stack = stack->next;
	}
	return min_node;
}

void set_up(t_stack **stack_a, t_data *data)
{
	give_index(*stack_a);
	data->arr = make_arr(*stack_a, &data->arr_size);
	sort_arr(data->arr, data->arr_size);
	data->mid = data->arr_size / 2 - 1;
	data->div = data->arr[data->mid];
	data->offset = 45;
	if (data->arr_size <= 500)
		data->offset = 30;
	if (data->arr_size <= 100)
		data->offset = 12;
	if (data->arr_size < 50)
		data->offset = 6;
	if (data->arr_size < 20)
		data->offset = 2;

    data->end = data->mid + data->offset;
    data->start = data->mid - data->offset;
	data->orig_max = data->arr[data->arr_size - 1];
	data->curr_max_i = data->arr_size - 1;
	data->push_counter = 0;
	check_offset(&data->start, &data->end, data->offset, data->arr_size);
}

t_stack *find_node_in_range(t_stack *stack, int start, int end)
{
	while (stack)
	{
		if (stack->n >= start && stack->n <= end)
			return stack;
		stack = stack->next;
	}
	return NULL;
}
void push_B(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack	*temp;
    int stack_size;
	int flag;
	while (*stack_a)
	{
		if ((*stack_a)->n >= data->arr[data->start] && (*stack_a)->n <= data->arr[data->end])
		{
			push_a_to_b(stack_a, stack_b);
			if ((*stack_b)->n < data->arr[data->mid])
				rotate_stack(stack_b, "rb");
		}
		else
		{
			flag = 0;
			stack_size = size(*stack_a);
			temp = *stack_a;
			give_index(*stack_a);
			while (temp)
			{
				if (temp->n >= data->arr[data->start] && temp->n <= data->arr[data->end])
				{
					if (temp->i < (stack_size / 2))
					{
						while (*stack_a != temp)
							rotate_stack(stack_a, "ra");
					}
					else
					{
						while (*stack_a != temp)
							reverse_rotate_stack(stack_a, "rra");
					}
					push_a_to_b(stack_a, stack_b);
					if ((*stack_b)->n < data->arr[data->mid])
						rotate_stack(stack_b, "rb");
					flag = 1;
					break;
				}
				temp = temp->next;
			}
			if (flag == 0)
				update_offset(&data->start, &data->end, data->offset, data->arr_size);
		}
	}
	*stack_a = NULL;
	give_index(*stack_b);

}

void push_A(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*max_node;
	int	k;

	k = 0;
	while (*b)
	{
		max_node = find_max_usin_arr(*b, data);
		if (max_node) // in b
		{
			if (*b == max_node)
			{
				data->curr_max_i--;
				push_b_to_a(a, b, "pa");
			}
			else if (last(*b) == max_node)
			{
				reverse_rotate_stack(b, "rrb");
				max_node = find_max_usin_arr(*b, data);
				data->curr_max_i--;
				push_b_to_a(a, b, "pa");
			}
			else // not up and now down but in there
			{
				if (k == 0)
				{
					push_b_to_a(a, b, "pa");
					rotate_stack(a, "ra");
					k++;
				}
				else
				{
					if (*b < last(*a))
						rotate_stack(b, "rb");
					else
					{
						push_b_to_a(a, b, "pa");
						rotate_stack(a, "ra");
					}
				}
			}
		}
		else // in a
		{
			while (k-- > 0)
				reverse_rotate_stack(a, "rra");
			data->curr_max_i--;
		}
	}
	
	
}



int	main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;
	t_data data;
	t_stack *max_node;
	
	int		i;
	i = 0;
	b = NULL;
	a = parse(ac, av);
	set_up(&a, &data);	

	if (is_stack_sorted(a))
		return 0;
	else if (size(a) == 2)
		sort_two(&a, "sa");
	else if (size(a) == 3)
		sort_three(&a, &b);
	else if (size(a) == 4)
		sort_four(&a, &b);
	else if (size(a) == 5)
		sort_five(&a, &b);
	else
	{
		push_B(&a, &b, &data);
		print_stack(b);
		printf("done push to a now push to b\n");
		push_A(&a, &b, &data);
		printf ("stack a\n");
		print_stack(a);

	}
}