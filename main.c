/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:10:35 by dzui              #+#    #+#             */
/*   Updated: 2016/12/08 17:10:35 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_trim(char *buff)
{
	char	**split;
	int		k;
	int		end;

	k = 0;
	split = ft_strsplit(buff, '\n');
	while (is_empty(split[k]) && k < 4)
		k++;
	end = k;
	while (!is_empty(split[end]) && end < 4)
		end++;
	ft_strclr(buff);
	while (k < end)
	{
		ft_strcat(buff, (mk_tmp(split[k], fn_start(split),
									fn_last(split))));
		k++;
	}
}

int		is_empty(char *str)
{
	int i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i++] == '#')
			return (0);
	}
	return (1);
}

int		valid_map(char *buff, int size)
{
	int		i;
	int		ch;

	i = 0;
	while (i < size)
	{
		ch = 0;
		while (buff[i] == '.' || buff[i] == '#')
		{
			i++;
			ch++;
		}
		if (buff[i++] == '\n' && ch == 4)
			continue;
		return (0);
	}
	return (1);
}

int		ft_pattern_check(char *figure)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!ft_strcmp(figure, "##\n..\n##\n") || !ft_strcmp(figure, "#.#\n#.#\n"))
		return (0);
	while (*figure)
	{
		if (*figure == '#')
			i++;
		if (*figure == '.')
			j++;
		figure++;
	}
	if (i == 4 && (j == 2 || j == 0))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	ch;
	t_fig	*out;

	i = 0;
	ch = '\0';
	out = NULL;
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("No such file\n");
		return (1);
	}
	ft_printmap(ft_fillit_ctrl(read_map(fd, i, ch, out)));
	close(fd);
	return (0);
}
