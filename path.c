/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:59:17 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/07/22 17:59:19 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char		*get_path(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strstr(env[i], "PATH") != 0)
			return (env[i] + 5);
	}
	return (NULL);
}

char		*parse_path(char *path, char *cmd)
{
	char	**dir;
	char	*curr;
	int		i;

	i = -1;
	dir = ft_strsplit(path, ':');
	while (dir[++i])
	{
		if (cmd[0] == '/')
			curr = ft_strjoin(dir[i], cmd);
		else
			curr = ft_strjoin(ft_strjoin(dir[i], "/"), cmd);
		if (!access(curr, F_OK))
			return (curr);
	}
	return (NULL);
}
