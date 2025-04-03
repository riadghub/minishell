/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:38:54 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/03 10:25:42 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	penser a echo mais pas dans la sortie standard
*/

void	execute_command(char *input)
{
	char	**args;

	args = ft_split(input, ' ');
	if (args[0])
	{
		if (ft_strcmp(args[0], "echo") == 0)
			echo_builtin(args);
		else if (ft_strcmp(args[0], "cd") == 0)
			cd_builtin(args);
		else if (ft_strcmp(args[0], "pwd") == 0)
			pwd_builtin();
		else
			printf("%s: command not found\n", args[0]);
	}
	free_all(args);
}

int	main(void)
{
	char	*input;

	printbanner();
	while (1)
	{
		input = readline("minishell > ");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		if (*input)
			add_history(input);
		execute_command(input);
		free(input);
	}
	return (0);
}
