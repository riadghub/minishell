/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:22:19 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/03 15:11:26 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _XOPEN_SOURCE 500

# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_env
{
	char	**vars;
}			t_env;

int			count_words(const char *str, char c);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(char *str);

void		cd_builtin(char **args);
void		echo_builtin(char **args);
void		env_builtin(t_env *env);
void		execute_command(char *input, t_env *env);
void		exit_builtin(void);
void		export_builtin(char **args, t_env *env);
void		free_all(char **str);
void		free_env(t_env *env);
void		printbanner(void);
void		pwd_builtin(void);
void		unset_builtin(char **args, t_env *env);

char		**ft_split(char const *s, char c);
char		*ft_strdup(char *s);
char		*get_word(char const *str, char c, int *index);

t_env		init_env(char **envi);

#endif