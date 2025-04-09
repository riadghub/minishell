/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:22:19 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/09 15:08:03 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _XOPEN_SOURCE 500

# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_env
{
	char			**vars;
	unsigned char	exit_code;
}					t_env;

int					count_words(const char *str, char c);
int					execute_builtin(char **args, t_env *env);
int					find_var_index(char *arg, t_env *env);
int					ft_atoi(const char *nptr);
int					ft_is_space(const char c);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strlen(char *str);
int					get_exit_code(char **args);
int					is_numeric(const char *str);
int					validate_exit_args(char **args, t_env *env);

void				cd_builtin(char **args);
void				echo_builtin(char **args, t_env *env);
void				env_builtin(t_env *env);
void				execute_command(char *input, t_env *env);
void				exit_builtin(char **args, t_env *env);
void				export_builtin(char **args, t_env *env);
void				free_all(char **str);
void				free_env(t_env *env);
void				handle_signals(void);
void				printbanner(void);
void				pwd_builtin(void);
void				remove_var(int index, t_env *env);
void				set_env(t_env *env);
void				sigint_handler(int sig, siginfo_t *info, void *ucontext);
void				unset_builtin(char **args, t_env *env);

char				**ft_split(char const *s, char c);
char				*ft_strdup(char *s);
char				*get_word(char const *str, char c, int *index);

t_env				init_env(char **envi);
t_env				*get_env(void);
t_env				**get_envr(void);

#endif