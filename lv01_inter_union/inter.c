/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$
*/

#include <unistd.h>

int     ft_strlen(char *s)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while(s[i])
        i++;
    return (i);
}

int     not_seen_before(char c, char *s, int max)
{
    int i;

    i = 0;
    while (i < max)
    {
        if (s[i] == c)
            return (0);
        i++;
    }
    return (1);
}

void    inter(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (not_seen_before(s1[i], s1, i) && !not_seen_before(s1[i], s2, ft_strlen(s2)))
            write(1, &s1[i], 1);
        i++;
    }
}

int     main(int ac, char **av)
{
    char c = '\n';

    if (ac == 3)
        inter(av[1], av[2]);
    write(1, &c, 1);
    return (0);
}