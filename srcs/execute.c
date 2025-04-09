/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:57:17 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/09 14:58:09 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_builtin(char **args, t_env *env)
{
	if (ft_strcmp(args[0], "echo") == 0)
		echo_builtin(args, env);
	else if (ft_strcmp(args[0], "cd") == 0)
		cd_builtin(args);
	else if (ft_strcmp(args[0], "pwd") == 0)
		pwd_builtin();
	else if (ft_strcmp(args[0], "export") == 0)
		export_builtin(args, env);
	else if (ft_strcmp(args[0], "unset") == 0)
		unset_builtin(args, env);
	else if (ft_strcmp(args[0], "env") == 0)
		env_builtin(env);
	else if (ft_strcmp(args[0], "exit") == 0)
	{
		exit_builtin(args, env);
		return (env->exit_code);
	}
	else
	{
		printf("minishell: %s: command not found\n", args[0]);
		return (127);
	}
	return (0);
}

void	execute_command(char *input, t_env *env)
{
	char	**args;

	args = ft_split(input, ' ');
	if (!args || !args[0])
	{
		free_all(args);
		return ;
	}
	env->exit_code = execute_builtin(args, env);
	free_all(args);
}
