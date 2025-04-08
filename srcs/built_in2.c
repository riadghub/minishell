/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:02:30 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/08 12:47:24 by reeer-aa         ###   ########.fr       */
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

void	exit_builtin(char **args, t_env *env)
{
	int	exit_code;
	int	should_exit;

	should_exit = 1;
	exit_code = 0;
	printf("exit\n");
	if (args[1] && !is_numeric(args[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", args[1]);
		env->exit_code = 2;
	}
	else if (args[1] && args[2])
	{
		printf("minishell: exit: too many arguments\n");
		env->exit_code = 1;
		should_exit = 0;
	}
	else if (args[1])
	{
		exit_code = ft_atoi(args[1]);
		if (exit_code < 0)
			exit_code += 256;
		env->exit_code = exit_code % 256;
	}
	free_all(args);
	if (should_exit)
	{
		free_env(env);
		exit(env->exit_code);
	}
}
