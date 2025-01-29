

#include "push_swap.h"

int ft_atoi(const char *str)
{
    int signe;
    int res;
    int i;

    i = 0;
    res = 0;
    signe = 1;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            signe = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (signe * res);
}

int ft_nbrwrds(char const *s, char c)
{
    int i;
    int wrd;

    i = 0;
    wrd = 0;
    while (s[i])
    {
        if (s[i] == c)
            i++;
        else
        {
            wrd++;
            while (s[i] != c && s[i])
                i++;
        }
    }
    return (wrd);
}

int ft_sizewrd(char c, char const *wrd)
{
    int i;

    i = 0;
    while (wrd[i] && wrd[i] != c)
        i++;
    return (i);
}

void *ft_clear(int j, char **res)
{
    while (j > 0)
        free(res[--j]);
    free(res);
    return (NULL);
}

char **ft_split(char const *s, char c)
{
    int i;
    int j;
    char **res;

    i = 0;
    j = 0;
    res = malloc(sizeof(char *) * (ft_nbrwrds(s, c) + 1));
    if (!res)
        return (NULL);
    while (s[i] && res)
    {
        if (s[i] == c)
            i++;
        else
        {
            res[j] = malloc(sizeof(char) * (ft_sizewrd(c, s + i) + 1));
            if (!res[j])
                return (ft_clear(j, res));
            ft_strlcpy(res[j], s + i, ft_sizewrd(c, s + i) + 1);
            i += ft_sizewrd(c, s + i);
            j++;
        }
    }
    res[j] = NULL;
    return (res);
}