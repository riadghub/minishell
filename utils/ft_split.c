/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:25:55 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/07 12:08:22 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	count_words(const char *str, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			res++;
		i++;
	}
	return (res);
}

char	*get_word(char const *str, char c, int *index)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[*index] == c && str[*index])
		(*index)++;
	while (str[*index + j] && str[*index + j] != c)
		j++;
	res = malloc(sizeof(char) * (j + 1));
	if (!res)
		return (NULL);
	while (i < j)
	{
		res[i] = str[*index];
		i++;
		(*index)++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		word_total;

	if (!s || !*s)
		return (NULL);
	word_total = count_words(s, c);
	res = malloc(sizeof(char *) * (word_total + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_total)
	{
		res[j] = get_word(s, c, &i);
		if (!res[j])
		{
			free_all(res);
			return (NULL);
		}
		j++;
	}
	res[j] = NULL;
	return (res);
}
