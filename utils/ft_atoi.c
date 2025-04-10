/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:56:19 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/10 13:22:42 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_long(const char *str, int is_negative)
{
	const char	*llong_max = "9223372036854775807";
	const char	*llong_min = "9223372036854775808";
	const char	*ref;
	int			i;

	if (is_negative)
		ref = llong_min;
	else
		ref = llong_max;
	i = 0;
	while (i < 19)
	{
		if (str[i] < ref[i])
			return (1);
		if (str[i] > ref[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_long_range(const char *str)
{
	int	is_negative;
	int	len;

	is_negative = 0;
	while (ft_is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = 1;
		str++;
	}
	while (*str == '0')
		str++;
	len = 0;
	while (str[len] && is_numeric(&str[len]))
		len++;
	if (len < 19)
		return (1);
	if (len > 19)
		return (0);
	return (is_long(str, is_negative));
}

int	ft_is_space(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atoi(const char *nptr)
{
	long long	i;
	long long	minus;
	long long	res;

	i = 0;
	minus = 0;
	res = 0;
	while (ft_is_space(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			minus++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
		res = res * 10 + nptr[i++] - '0';
	if (minus % 2 != 0)
		res *= -1;
	return (res);
}
