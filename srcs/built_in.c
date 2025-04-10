/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:13:58 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/10 14:26:30 by reeer-aa         ###   ########.fr       */
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

int	is_valid_identifier(const char *str)
{
	int	i;

	if (!str || (!is_alpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!is_alnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	export_builtin(char **args, t_env *env)
{
	int	i;

	if (!args[1])
	{
		i = 0;
		while (env->vars[i])
		{
			printf("export %s\n", env->vars[i]);
			i++;
		}
		return ;
	}
	i = 1;
	while (args[i])
	{
		if (!is_valid_identifier(args[i]))
			printf("minishell: export: `%s': not a valid identifier\n",
				args[i]);
		else
			add_env_var(env, args[i]);
		i++;
	}
}
