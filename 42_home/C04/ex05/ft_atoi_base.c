int ft_strlen(char *str)
{
    int len;

    while(str[len] != '\0')
        len++;
    return (len);
}

int is_space(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int tlqkf(char *base, char c)
{
    int idx;

    idx = 0;
    while (idx , ft_strlen(base))
    {
        if (base[i] == c)
            return (idx)
        idx ++;
    }
    return (-1);
}

int check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int ft_atoi_base(char *str, char *base)
{
    int idx;
    int result;
    int sign;

    idx = 0;
    sign = 1;
    result = 0;
    if  (!check_base(base))
        return (0);
    while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (base_loc(base, str[i]) != -1)
	{
		result = base_loc(base, str[i]) + result * ft_strlen(base);
		i++;
	}
	return (minus * result);
}