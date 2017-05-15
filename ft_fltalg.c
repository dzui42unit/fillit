/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fltalg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:29:47 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/12/04 12:29:49 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**g_map;

void	ft_mapinit(size_t size)
{
	size_t	i;

	i = 0;
	g_map = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		g_map[i] = ft_strnew(size);
		ft_memset((void*)g_map[i], '.', size);
		i++;
	}
	g_map[i] = NULL;
}

int		ft_can_place(int x, int y, t_fig *figure)
{
	register int	i;
	register int	j;
	int				width;
	int				height;

	ft_sfparam(figure, &width, &height);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (g_map[y + i][x + j] != '.' && (figure->figure)[i][j] != '.'
				&& figure->figure[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_w2map(int x, int y, t_fig *figure)
{
	register int	i;
	register int	j;
	int				width;
	int				height;

	i = 0;
	ft_sfparam(figure, &width, &height);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((figure->figure)[i][j] != '.' && (figure->figure)[i][j])
				g_map[y + i][x + j] = figure->figure[i][j];
			j++;
		}
		i++;
	}
}

int		ft_fillit(t_fig *figure, size_t f_size)
{
	int		var[4];
	char	**map_tmp;

	var[1] = -1;
	ft_sfparam(figure, &var[2], &var[3]);
	while (++var[1] + var[3] <= (int)f_size)
	{
		var[0] = -1;
		while (++var[0] + var[2] <= (int)f_size)
		{
			if (ft_can_place(var[0], var[1], figure))
			{
				map_tmp = ft_mapclone(g_map);
				ft_w2map(var[0], var[1], figure);
				if (figure->next == NULL)
					return (ft_delmap(&map_tmp));
				else if (ft_fillit(figure->next, f_size))
					return (ft_delmap(&map_tmp));
				g_map = map_tmp;
			}
		}
	}
	return (0);
}

char	**ft_fillit_ctrl(t_fig *figure)
{
	size_t	size;

	size = ft_csize(figure);
	ft_mapinit(size);
	while (!ft_fillit(figure, size))
	{
		size++;
		free(g_map);
		ft_mapinit(size);
	}
	return (g_map);
}
