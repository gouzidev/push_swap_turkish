#include "push_swap.h"

void	swap_stack(t_stack **head, char *msg)
{
	int	temp;

	if ((*head) && (*head)->next)
	{
		temp = (*head)->n;
		(*head)->n = (*head)->next->n;
		(*head)->next->n = temp;
	}
	printf("%s", msg);

}
void	push_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a || !b)
	{
		printf("Error\n");
		exit(1);
	}
	if (*b)
	{
		temp = duplicate(*b);
		pop(b);
		push(a, temp);
	}
	if (*a)
		give_index(*a, false);
	if (*b)
		give_index(*b, false);
    printf("pa\n");

}
void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a || !b)
	{
		printf("Error\n");
		exit(1);
	}
	if (*a)
	{
		temp = duplicate(*a);
		pop(a);
		push(b, temp);
	}
	if (*a)
		give_index(*a, false);
	if (*b)
		give_index(*b, false);
	printf("pb\n");
}
