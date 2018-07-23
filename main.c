/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opokusyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:56:42 by opokusyn          #+#    #+#             */
/*   Updated: 2018/07/21 11:56:44 by opokusyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		main(int argc, char **argv)
{
	extern char	**environ;
	t_pip		p;

	p.path = "PATH";
	if (argc != 5)
		ft_panic("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2\n");
	p.file1 = argv[1];
	p.file2 = argv[4];
	p.cmd1 = ft_strsplit(argv[2], ' ');
	if (!(p.cmd1[0]))
		ft_panic("ERROR: no first command.\n");
	p.cmd2 = ft_strsplit(argv[3], ' ');
	if (!(p.cmd2[0]))
		ft_panic("ERROR: no second command.\n");
	if (!(p.path = get_path(environ)))
		ft_panic("ERROR: can't find path.\n");
	pipex(&p, environ);
	return (0);
}
