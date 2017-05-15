/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:14:49 by dzui              #+#    #+#             */
/*   Updated: 2016/12/08 17:14:49 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fn_start(char **split)
{
	int i;
	int k;

	i = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (split[k++][i] == '#')
				return (i);
		}
		i++;
	}
	return (0);
}

int		fn_last(char **split)
{
	int i;
	int k;
	int	last;

	i = 0;
	last = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (split[k][i] == '#')
			{
				last = i;
				break ;
			}
			k++;
		}
		i++;
	}
	return (last);
}

char	*mk_tmp(char *copy, int start, int end)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(end - start + 3);
	while (start <= end)
	{
		temp[i++] = copy[start++];
	}
	temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}
