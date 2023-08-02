unsigned int    ft_strlen(char *arr)
{   
	int index;

	index = 0;
	while(*(arr + index) != '\0')
		index++;
	return (index);  
}

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	index;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	index = 0;
	if (size - dest_len < 0)
		return (dest_len);
	while(index < src_len && index < size - dest_len)
	{
		dest[dest_len] = src[index];
		dest_len++;
		index++;
	}
	dest[dest_len] = '\0';
	return (dest_len);
}

