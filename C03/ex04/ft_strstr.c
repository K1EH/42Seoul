char    *ft_strstr(char *str, char *to_find)
{
    char    *str_ptr;
    char    *find_ptr;

    if (*to_find == '\0')
        return (0);
    while(*str != '\0')
    {
        str_ptr = str;
        find_ptr = to_find;
        while (*str_ptr == *find_ptr && *find_ptr != '\0')
        {
            str_ptr++;
            find_ptr++;
        }
        if (*find_ptr == '\0')
            return (str);
        str++;            
    }
    return (0);
}