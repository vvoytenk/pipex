/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opokusyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:59:25 by opokusyn          #+#    #+#             */
/*   Updated: 2018/07/21 11:59:28 by opokusyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_pip
{
	char		**cmd1;
	char		**cmd2;
	char		*path;
	char		*file1;
	char		*file2;
}				t_pip;

char			*get_path(char **env);
int				inputfile(int fdpid, char *path, t_pip *p, char **env);
int				sourcefile(int fdpid, char *path, t_pip *p, char **env);
int				pipex(t_pip *p, char **env);
void			ft_panic(char *massage);
char			*parse_path(char *path, char *cmd);

#endif
