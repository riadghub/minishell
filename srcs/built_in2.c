/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:02:30 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/10 14:42:02 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_builtin(t_env *env)
{
	int	i;

	i = 0;
	while (env->vars[i])
	{
		printf("%s\n", env->vars[i]);
		i++;
	}
}

void	add_env_var(t_env *env, char *var)
{
	int		i;
	int		j;
	char	**v;

	i = 0;
	while (env->vars[i])
	{
		if (ft_strncmp(env->vars[i], var, slen(var, '=')) == 0
			&& env->vars[i][slen(var, '=')] == '=')
		{
			free(env->vars[i]);
			env->vars[i] = ft_strdup(var);
			return ;
		}
		i++;
	}
	v = malloc(sizeof(char *) * (i + 2));
	j = 0;
	while (j < i)
	{
		v[j] = env->vars[j];
		j++;
	}
	v[j] = strdup(var);
	v[j + 1] = NULL;
	free(env->vars);
	env->vars = v;
}

void	remove_var(int index, t_env *env)
{
	int	k;

	free(env->vars[index]);
	k = index;
	while (env->vars[k])
	{
		env->vars[k] = env->vars[k + 1];
		k++;
	}
}

int	find_var_index(char *arg, t_env *env)
{
	int	j;

	j = 0;
	while (env->vars[j])
	{
		if (ft_strncmp(env->vars[j], arg, ft_strlen(arg)) == 0
			&& env->vars[j][ft_strlen(arg)] == '=')
			return (j);
		j++;
	}
	return (-1);
}

void	unset_builtin(char **args, t_env *env)
{
	int	i;
	int	index;

	i = 1;
	while (args[i])
	{
		index = find_var_index(args[i], env);
		if (index != -1)
			remove_var(index, env);
		i++;
	}
}
