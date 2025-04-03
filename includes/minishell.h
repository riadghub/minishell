/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:22:19 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/04/03 10:22:52 by reeer-aa         ###   ########.fr       */
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

int		count_words(const char *str, char c);
int		ft_strcmp(char *s1, char *s2);

void	cd_builtin(char **args);
void	echo_builtin(char **args);
void	execute_command(char *input);
void	free_all(char **str);
void	printbanner(void);
void	pwd_builtin(void);

char	*get_word(char const *str, char c, int *index);
char	**ft_split(char const *s, char c);

#endif