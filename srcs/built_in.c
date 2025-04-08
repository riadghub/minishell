/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:13:58 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/08 14:07:59 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_builtin(char **args, t_env *env)
{
	int	n;
	int	i;

	n = 0;
	i = 1;
	while (args[i] && ft_strcmp(args[i], "-n") == 0)
	{
		n = 1;
		i++;
	}
	while (args[i])
	{
		if (ft_strcmp(args[i], "$?") == 0)
			printf("%d", env->exit_code);
		else
			printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (!n)
		printf("\n");
}

void	cd_builtin(char **args)
{
	char	*home;

	if (!args[1])
	{
		home = getenv("HOME");
		if (home)
			chdir(home);
		else
			printf("cd: HOME not set\n");
	}
	else if (chdir(args[1]) != 0)
		perror("cd");
}

void	pwd_builtin(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	else
		perror("pwd");
}

void	export_builtin(char **args, t_env *env)
{
	int	i;

	i = 0;
	if (!args[1])
	{
		while (env->vars[i])
		{
			printf("%s\n", env->vars[i]);
			i++;
		}
		return ;
	}
	i = 1;
	while (args[i])
	{
		putenv(args[i]);
		i++;
	}
}

void	unset_builtin(char **args, t_env *env)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (env->vars[j])
		{
			if (ft_strncmp(env->vars[j], args[i], ft_strlen(args[i])) == 0
				&& env->vars[j][ft_strlen(args[i])] == '=')
			{
				free(env->vars[j]);
				k = j;
				while (env->vars[k])
				{
					env->vars[k] = env->vars[k + 1];
					k++;
				}
				break ;
			}
			j++;
		}
		i++;
	}
}
