/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:04:47 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/20 14:07:02 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_fds(int pipefds[2])
{
	close(pipefds[0]);
	close(pipefds[1]);
}

int	ft_strichr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*ft_strndup(char *str, unsigned int n)
{
	char				*s2;
	unsigned int		i;

	i = 0;
	s2 = malloc(sizeof(char) * (n + 1));
	while (i < n)
		s2[i++] = *str++;
	s2[n] = 0;
	return (s2);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	error_msg(void)
{
	perror("Error");
	exit(1);
}
