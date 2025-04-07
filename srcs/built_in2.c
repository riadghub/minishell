/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:02:30 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/07 15:00:09 by reeer-aa         ###   ########.fr       */
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

	exit_code = 0;
	printf("exit\n");
	if (args[1] && !is_numeric(args[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", args[1]);
		free_all(env->vars);
		free_all(args);
		exit(2);
	}
	if (!args[1])
	{
		free_all(env->vars);
		free_all(args);
		exit(exit_code);
	}
	exit_code = ft_atoi(args[1]) % 256;
	if (exit_code < 0)
		exit_code += 256;
	free_all(env->vars);
	free_all(args);
	exit(exit_code);
}
