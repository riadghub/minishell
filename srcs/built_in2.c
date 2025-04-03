/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:02:30 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/03 15:02:56 by reeer-aa         ###   ########.fr       */
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

void	exit_builtin(void)
{
	printf("exit\n");
	exit(0);
}
