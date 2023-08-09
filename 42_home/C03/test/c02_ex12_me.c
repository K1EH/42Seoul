#include <io.h>

void    ft_print_address(void *addr)
{
    long long int   add;
    int             index;
    char            output[16];

    add = (long long int)addr;
    index = 0;
    while (index < 16)
    {
        output[index] = "0123456789abcdef"[add % 16];
        add = add / 16;
        index++;
    }
    while (--index >= 0)
        write (1, &output[index], 1);
}

void    ft_print_hex(void *addr, unsigned int size)
{
    unsigned int    index;
    unsigned int    div;
    unsigned int    mod;

    index = 0;
    while (index < 16)
    {
        if (index < size)
        {
            div = *(unsigned char *)addr / 16;
            mod = *(unsigned char *)addr % 16;
            write(1, &"0123456789abcdef"[div], 1);
            write(1, &"0123456789abcdef"[mod], 1);
        }
        else
            write(1, "  ", 2);
        if (index % 2 == 1)
            write(1, " ", 1);
        addr++;
        index++;
    }
}

void    ft_print_string(char *addr, unsigned int size)
{
    unsigned int    index;

    index = 0;
    while (index < size)
    {
        if (*addr >= 32 && *addr <= 126)
            write(1, addr, 1);
        else
            write(1, ".", 1);
        index++;
        addr++;
    }
}

void    ft_print_hex_string(void *addr, unsigned int count_mod)
{
    ft_print_hex(addr, count_mod);
    ft_print_string((char *)addr, count_mod);
    write(1, "\n", 1);
}

void    *ft_print_memory(void *addr, unsigned int size)
{
    void            *return_addr;
    unsigned int    index;
    unsigned int    count_div;
    unsigned int    count_mod;

    return_addr = addr;
    index = 0;
    if (size <= 0)
        return (return_addr);
    count_div = size / 16;
    count_mod = size % 16;
    if (count_mod != 0)
        count_div++;
    while (index < count_div)
    {
        ft_print_address(addr);
        write(1, ": ", 2);
        if (index + 1 == count_div && count_mod != 0)
            ft_print_hex_string(addr, count_mod);
        else
            ft_print_hex_string(addr, 16);
        index++;
        addr = addr + 16;
    }
    return (return_addr);
}

int main() {
    char arr[] = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
    if (ft_print_memory(arr, 30) != arr)
        return -1;
    /*char brr[] = "Chuncheon is better than Seoul! :) ;)";
    ft_print_memory(brr, 38);
    ft_print_memory(brr, 10);
    ft_print_memory(brr, 0);
    for (int i = 13; i < 24; ++i)
        brr[i] = '\0';
    ft_print_memory(brr, 37);*/
    return 0;
}