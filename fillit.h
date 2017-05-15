/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 20:15:50 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/12/07 20:15:52 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct		s_fig
{
	char			**figure;
	struct s_fig	*next;
}					t_fig;

char				**ft_fillit_ctrl(t_fig *figure);
void				ft_sfparam(t_fig *figure, int *width, int *height);
char				**ft_mapclone(char **map);
int					ft_delmap(char ***map_tmp);
void				ft_printmap(char **map);
size_t				ft_csize(t_fig *figure);
int					fn_start(char **split);
int					fn_last(char **split);
char				*mk_tmp(char *copy, int start, int end);
t_fig				*read_map(int fd, int i, char ch, t_fig *out);
void				set_chars(char **figure, char ch);
void				ft_error(void);
void				ft_lstcadd(t_fig **lst, char ***figure);
int					is_empty(char *str);
int					valid_map(char *buff, int size);
int					ft_pattern_check(char *figure);
void				ft_trim(char *buff);

#endif
