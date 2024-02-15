#include "../../include/parsing.h"

size_t  ft_strlen_no_newlines(const char *s1)
{
    size_t  i;
    size_t  len;

    i = 0;
	len = 0;
    while (s1[i] && s1[i] == ' ')
        i++;
    while (s1[i])
    {
        if (s1[i] == '\n')
            break ;
		len++;
        i++;
    }
    return (len);
}

char	*ft_strdup_no_newlines(const char *s1)
{
	int		i;
    int     j;
	char	*str;

	i = 0;
    j = 0;
	str = malloc((ft_strlen_no_newlines(s1) + 1) * sizeof(char));
	if (!str)
		exit (1);
    while (s1[i] == ' ' && s1[i])
        i++;
	while (s1[i] && s1[i] != '\n')
	{
        str[j] = s1[i];
        j++;
        i++;
    }
	str[j] = '\0';
	return (str);
}

void	free_2darr(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		if (tab[i])
			free (tab[i]);
		tab[i] = NULL;
		i++;
	}
	// if (tab)
	// 	free (tab);
	tab = NULL;
}

size_t	ft_2dlen(char **tab)
{
	size_t	len;

	len = 0;
	while (tab && tab[len] != NULL)
		len++;
	return (len);
}

char	**realloc_2d(char **tab, char *str)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_2dlen(tab) + 2));
	if (!ret)
		exit (0);
	while (tab && tab[i] != NULL)
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	ret[i] = ft_substr(str, 0, ft_strlen(str));
	ret[i + 1] = NULL;
	if (str)
		free (str);
	if (tab)
		free_2darr(tab);
	return (ret);
}
