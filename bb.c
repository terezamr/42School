int	check_n(const char *string)
{
	int	a;

	a = 0;
	if (string == 0)
		return (-1);
	while (string[a] != '\0')
	{
		if (string[a] == '\n')
			return (a);
		a++;
	}
	return (-1);
}

int main()
{
	printf("%d", check_n(""));
}