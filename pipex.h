/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:21:16 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/20 14:07:16 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "./libft/libft.h"

char	*get_path(char *cmd, char **envp);

char	*get_env_path(char **envp);

char	*search_bin_in_path(char *cmd, char *path);

void	close_fds(int pipefds[2]);

int		ft_strichr(char *str, char c);

char	*ft_strndup(char *str, unsigned int n);

void	error_msg(void);

void	free_matrix(char **matrix);

#endif
