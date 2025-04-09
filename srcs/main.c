/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:38:54 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/09 15:15:14 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	bash --posix
	penser a echo mais pas dans la sortie standard
	corriger exit + argument
*/

t_env	init_env(char **envi)
{
	t_env	env;
	int		count;
	int		i;

	count = 0;
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

	(void)argc;
	(void)argv;
	env = init_env(envi);
	set_env(&env);
	printbanner();
	handle_signals();
	env.exit_code = 0;
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
	free_env(&env);
	return (env.exit_code);
}
