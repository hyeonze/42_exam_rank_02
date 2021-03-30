/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

int    not_seen_before(char c, char *s, int i)
{
    int     j;

    j = 0;
    while (j < i)
    {
        if (c == s[j])
            return (0);
        j++;
    }
    return (1);
}

void    ft_union(char *s1, char *s2)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (s1[i])
    {
        if (not_seen_before(s1[i], s1, i))
            write(1, &s1[i], 1);
        i++;
    }
    while (s2[j])
    {
        if (not_seen_before(s2[j], s1, i) && not_seen_before(s2[j], s2, j))
            write(1, &s2[j], 1);
        j++;
    }
}

int     main(int ac, char **av)
{
    char c;

    c = '\n';
    if (ac != 3)
    {
        write(1, &c, 1);
        return (0);
    }
    ft_union(av[1], av[2]);
    write(1, &c, 1);
    return (0);
}
