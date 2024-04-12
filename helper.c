#include "push_swap.h"

void ft_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
}
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
void	print_stack(t_stack *stack)
{
	printf("---\n");
	while (stack)
	{
		printf("-> %d [%d]  $%d", stack->n, stack->i, stack->push_cost);
		if (stack->target)
			printf("|  target => %d\n", stack->target->n);
		else
			printf("|  target => %p\n", NULL);


		stack = stack->next;
	}
	printf("---\n");
}
void	fill_stack(t_stack **stack)
{
	push(stack, new (1));
	push(stack, new (2));
	push(stack, new (3));
	push(stack, new (4));
}
void	give_index(t_stack *head, bool set_target_null)
{
	t_stack	*curr;
	int		i;
	int		median;

	median = get_size(head) / 2;
	if (!head)
		return ;
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