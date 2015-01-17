/* === HEADER == */

#include <unistd.h>
/*
plop
int     ft_strlen(char *s1)
{
    int i = 0;
    
    while (s1[i])
        i++;
    return (i);
}

int     ft_strchr(char *s1, char c)
{
    int i;
    
    i = 0;
    while (s1[i])
        {
            if (s1[i] == c) 
                return (1);
            i++;
        }
    return (0);
}

void    wdmatch(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    
    while(s1[i])
    {
        if (ft_strchr(s2, s1[i]))
            i++;
        else
            break;
    }
    if (i == ft_strlen(s1))
        write(1, s1, i);
}

int     main(int ac, char **av)
{
    if (ac == 3)
        wdmatch(av[1], av[2]);
    write(1, "\n", 1);
    return (0);
}
*/
#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int     i;
    int     len;
    char    *str;
    
    i = 0;
    if (!src)
        return (NULL);
    while (src[i])
        i++;
    len = i;
    i = 0;
    if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL )
        return (NULL);
    while (i < len)
    {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
        
}

int     main()
{
    char *src;
    char *str;
    
    src = "plop";
    str = ft_strdup(src);
    printf("%s", str);
    return (0);
} 
