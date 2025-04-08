/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:38:54 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/08 12:54:03 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	bash --posix
	penser a echo mais pas dans la sortie standard
	gerer ctrl+D ctrl+C ctrl+\
*/

void	execute_command(char *input, t_env *env)
{
	char	**args;

	args = ft_split(input, ' ');
	if (!args || !args[0])
	{
		free_all(args);
		return ;
	}
	if (ft_strcmp(args[0], "echo") == 0)
	{
		echo_builtin(args, env);
		env->exit_code = 0;
	}
	else if (ft_strcmp(args[0], "cd") == 0)
	{
		cd_builtin(args);
		env->exit_code = 0;
	}
	else if (ft_strcmp(args[0], "pwd") == 0)
	{
		pwd_builtin();
		env->exit_code = 0;
	}
	else if (ft_strcmp(args[0], "export") == 0)
	{
		export_builtin(args, env);
		env->exit_code = 0;
	}
	else if (ft_strcmp(args[0], "unset") == 0)
	{
		unset_builtin(args, env);
		env->exit_code = 0;
	}
	else if (ft_strcmp(args[0], "env") == 0)
	{
		env_builtin(env);
		env->exit_code = 0;
	}
	else if (ft_strcmp(args[0], "exit") == 0)
	{
		exit_builtin(args, env);
		return ;
	}
	else
	{
		printf("minishell: %s: command not found\n", args[0]);
		env->exit_code = 127;
	}
	free_all(args);
}

t_env	init_env(char **envi)
{
	t_env	env;
	int		count;
	int		i;

	count = 0;
	env.exit_code = 0;
	while (envi[count])
		count++;
	env.vars = malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (i < count)
	{
		env.vars[i] = ft_strdup(envi[i]);
		i++;
	}
	env.vars[count] = NULL;
	return (env);
}

void	free_env(t_env *env)
{
	int	i;

	i = 0;
	if (!env || !env->vars)
		return ;
	while (env->vars[i])
	{
		free(env->vars[i]);
		i++;
	}
	free(env->vars);
}

int	main(int argc, char **argv, char **envi)
{
	char	*input;
	t_env	env;

	env = init_env(envi);
	(void)argc;
	(void)argv;
	printbanner();
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		if (*input)
			add_history(input);
		execute_command(input, &env);
		free(input);
	}
	free_all(argv);
	free_env(&env);
	return (0);
}
