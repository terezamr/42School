t_list	*sort_three(t_list *a, int argc)
{
	int	index;
	int	aux;

	index = get_max(a);
	aux = index;
	while (index != 0)
	{
		if (aux <= argc / 2)
		{
			a = rotate(a);
			printf("ra\n");
		}
		else
		{
			a = reverse_rotate(a);
			printf("rra\n");
		}
		index--;
	}
	if (a->number > a->next->number)
	{
		a = swap(a);
		printf("sa\n");
	}
	if (argc == 3)
		return (a);
	if (a->next->number > a->next->next->number)
	{
		a = rotate(a);
		printf("ra\n");
		a = swap(a);
		printf("sa\n");
		a = reverse_rotate(a);
		printf("rra\n");
	}
	if (a->number > a->next->number)
	{
		a = swap(a);
		printf("sa\n");
	}
	if (argc == 4)
		return (a);
	if (a->next->next->number > a->next->next->next->number)
	{
		a = reverse_rotate(a);
		printf("rra\n");
		a = reverse_rotate(a);
		printf("rra\n");
		a = reverse_rotate(a);
		printf("rra\n");
		a = swap(a);
		printf("sa\n");
		a = rotate(a);
		printf("ra\n");
	}
	return (a);
}