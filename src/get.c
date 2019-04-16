/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:28:08 by cuzureau          #+#    #+#             */
/*   Updated: 2018/12/28 16:03:40 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int				ft_exit(t_filler *f)
{
	ft_strdel(&f->line);
	ft_free_round(f);
	ft_free_all(f);
	return (-1);
}

int				ft_fill_map(t_filler *f)
{
	f->j = 0;
	if (ft_check_line(&f->line[4], f->map_w) < 0 || \
		!(f->map[f->i] = ft_strdup(&f->line[4])))
		return (-1);
	ft_strdel(&f->line);
	while (f->j < f->map_w)
	{
		f->map[f->i][f->j] == f->me ? f->far[f->i][f->j] = -2 : 0;
		f->map[f->i][f->j] == f->it ? f->far[f->i][f->j] = -1 : 0;
		f->map[f->i][f->j] == '.' ? f->far[f->i][f->j] = 8 : 0;
		f->j++;
	}
	return (0);
}

int				ft_get_map(t_filler *f)
{
	if (get_next_line(0, &f->line) <= 0)
		return (ft_exit(f));
	while (!ft_isdigit(f->line[0]))
	{
		ft_strdel(&f->line);
		if (get_next_line(0, &f->line) <= 0)
			return (ft_exit(f));
	}
	f->i = 0;
	while (f->i < f->map_h)
	{
		ft_fill_map(f);
		f->i++;
		if (get_next_line(0, &f->line) <= 0)
			return (ft_exit(f));
	}
	return (0);
}

int				ft_get_piece(t_filler *f)
{
	int			i;

	i = 0;
	if (ft_get_size(f->line, &f->piece_h, &f->piece_w) < 0)
		return (-1);
	ft_alloc_map(&f->piece, f->piece_h);
	while (i < f->piece_h)
	{
		if (get_next_line(0, &f->line) <= 0)
			return (ft_exit(f));
		f->piece[i++] = f->line;
	}
	return (0);
}

int				ft_get_first(t_filler *f)
{
	if (get_next_line(0, &f->line) <= 0)
		return (ft_exit(f));
	if (ft_strlen(f->line) < 31)
		return (ft_exit(f));
	if (f->line[10] != '1' && f->line[10] != '2')
		return (ft_exit(f));
	f->me = (f->line[10] == '1' ? 'O' : 'X');
	f->it = (f->line[10] == '1' ? 'X' : 'O');
	ft_strdel(&f->line);
	if (get_next_line(0, &f->line) <= 0)
		return (ft_exit(f));
	if (ft_get_size(f->line, &f->map_h, &f->map_w) < 0)
		return (ft_exit(f));
	ft_alloc_map(&f->map, f->map_h);
	ft_alloc_far(f);
	return (0);
}
