/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:35:06 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/09 14:52:28 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	**get_envr(void)
{
	static t_env	*env = NULL;

	return (&env);
}

void	set_env(t_env *env)
{
	t_env	**envi;

	envi = get_envr();
	*envi = env;
}

t_env	*get_env(void)
{
	return (*get_envr());
}

void	sigint_handler(int sig, siginfo_t *info, void *ucontext)
{
	t_env	*env;

	(void)sig;
	(void)info;
	(void)ucontext;
	env = get_env();
	if (env)
		env->exit_code = 130;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sigint_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}
