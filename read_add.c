/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:17:10 by dzui              #+#    #+#             */
/*   Updated: 2016/12/08 17:17:11 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check(t_fig **out, char buff[21], char ch)
{
	char	**split;

	if (!valid_map(buff, 20))
		ft_error();
	ft_trim(buff);
	if (ft_pattern_check(buff))
	{
		split = ft_strsplit(buff, '\n');
		set_chars(split, ch);
		ft_lstcadd(out, &split);
	}
	else
		ft_error();
}

t_fig	*read_map(int fd, int i, char ch, t_fig *out)
{
	char	buff[21];
	int		j;

	ch = 'A';
	while (1 && !(j = 0))
	{
		if ((i = read(fd, buff, 21)) == 21)
			j = 1;
		if ((i == 20 || i == 21) && !(buff[20] = 0))
		{
			ft_check(&out, buff, ch++);
			if (!j)
				break ;
		}
		else
			ft_error();
	}
	return (out);
}

void	set_chars(char **figure, char ch)
{
	int i;
	int j;

	i = 0;
	while (figure[i])
	{
		j = 0;
		while (figure[i][j] != '\0')
		{
			if (figure[i][j] == '#')
				figure[i][j] = ch;
			j++;
		}
		i++;
	}
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	ft_lstcadd(t_fig **lst, char ***figure)
{
	t_fig	*l_bg;

	l_bg = *lst;
	if (!*lst)
	{
		*lst = (t_fig*)malloc(sizeof(t_fig));
		(*lst)->next = NULL;
		(*lst)->figure = *figure;
		return ;
	}
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = (t_fig*)malloc(sizeof(t_fig));
	(*lst)->next->next = NULL;
	(*lst)->next->figure = *figure;
	*lst = l_bg;
}
