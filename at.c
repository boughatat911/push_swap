int	ft_astoi(const char *str)
{
	int		sign;
	long	num;
	long	tmp;

	sign = 1;
	num = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		// tmp = num;
		num = (num * 10) + (*str - 48);
		if (tmp != num / 10 && sign == 1)
			return (-1);
		else if (tmp != num / 10 && sign == -1)
			return (0);
		str++;
	}
	if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return (sign * (int)num);
}
int main()
{
	printf("{%d} == {%d}\n",ft_astoi())
}