#include <io.h>
#include <stdio.h>

void    print_hex_addr(char *addr)
{
    long long int addr1;
    int    i;
    char        *hexa;
    char         tmp[16];

    addr1 = (unsigned long long) addr;
    hexa = "0123456789abcdef";
    i = 15;
    while (i >= 0)
    {
        tmp[i] = hexa[(unsigned long long) addr1 % 16];
        addr1 /= 16;
        i--;
    }
    write(1, tmp, 16);
    write(1, ": ", 2);
}

void    print_hex_characters(char *addr, unsigned int size)
{
    unsigned int    i;
    char    *hexa;

    i = 0;
    hexa = "0123456789abcdef";
    while (i < 16)
    {
        if (i >= size)
            write(1, "  ", 2);
        else
        {
            write(1, &hexa[(unsigned char) addr[i] / 16], 1);
            write(1, &hexa[(unsigned char) addr[i] % 16], 1);
        }
        if (i % 2 == 1)
            write(1, " ", 1);
        i++;
    }
}

void    print_str(char *addr, unsigned int size)
{
    unsigned int    i;

    i = 0;
    while (i < size && i < 16)
    {
        if (*addr >= 32 && *addr <= 127)
        {
            write(1, addr + i, 1);
        }
        else
            write(1, ".", 1);
        i++;
    }
    write(1, "\n", 1);
}

void    *ft_print_memory(void *addr, unsigned int size)
{
    char    *addr1;

    if (size == 0)
        return (addr);
    addr1 = (char*)addr;
    while (size > 0)
    {
        print_hex_addr(addr1);
        print_hex_characters(addr1, size);
        print_str(addr1, size);
        addr1 = addr1 + 16;
        if (size < 16)
            size = 0;
        else
            size = size - 16;
    }
    return (addr);
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