/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:07:21 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/10 13:22:15 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_exit_args(char **args, t_env *env)
{
	if (args[1] && !is_numeric(args[1]) || !is_long_range(args[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", args[1]);
		env->exit_code = 2;
		return (0);
	}
	else if (args[1] && args[2])
	{
		printf("minishell: exit: too many arguments\n");
		env->exit_code = 1;
		return (0);
	}
	return (1);
}

int	get_exit_code(char **args)
{
	int	exit_code;

	exit_code = 0;
	if (args[1])
	{
		exit_code = ft_atoi(args[1]);
		if (exit_code < 0)
			exit_code += 256;
		return (exit_code % 256);
	}
	return (0);
}

void	exit_builtin(char **args, t_env *env)
{
	printf("exit\n");
	validate_exit_args(args, env);
	if (env->exit_code != 2)
		env->exit_code = get_exit_code(args);
	free_all(args);
	free_env(env);
	exit(env->exit_code);
}
