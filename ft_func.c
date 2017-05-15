/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 20:04:00 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/12/07 20:04:01 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_csize(t_fig *figure)
{
	register size_t	i;
	register size_t	j;

	i = 0;
	j = 2;
	while (figure->next)
	{
		i++;
		figure = figure->next;
	}
	i *= 4;
	while (j * j < i)
		j++;
	return (j);
}

void	ft_sfparam(t_fig *figure, int *width, int *height)
{
	register int	i;

	i = 0;
	while ((figure->figure)[i])
	{
		i++;
	}
	*height = i;
	*width = ft_strlen((figure->figure)[i - 1]);
}

char	**ft_mapclone(char **map)
{
	char			**out;
	register int	i;

	i = 0;
	while (map[i])
		i++;
	out = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		out[i] = ft_strnew(ft_strlen(map[i]));
		ft_strcpy(*(out + i), *(map + i));
		i++;
	}
	out[i] = NULL;
	return (out);
}

int		ft_delmap(char ***map_tmp)
{
	int	i;

	i = 0;
	if (!map_tmp)
		return (0);
	while ((*map_tmp)[i])
	{
		free((*map_tmp)[i]);
		i++;
	}
	free(*map_tmp);
	return (1);
}

void	ft_printmap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
}
