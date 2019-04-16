/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:25:56 by cuzureau          #+#    #+#             */
/*   Updated: 2018/12/28 15:28:00 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int				ft_get_size(char *line, int *h, int *w)
{
	int			i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	*h = ft_atoi(&line[i]);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	*w = ft_atoi(&line[i]);
	ft_strdel(&line);
	return (*w <= 0 || *w > 100 || *h <= 0 || *h > 100 ? -1 : 0);
}

int				ft_alloc_map(char ***tab, int h)
{
	if (!(*tab = malloc(h * sizeof(char *))))
		return (-1);
	return (0);
}

int				ft_alloc_far(t_filler *f)
{
	int			i;

	if (!(f->far = malloc((f->map_h) * sizeof(int *))))
		return (-1);
	i = 0;
	while (i < f->map_h)
	{
		if (!(f->far[i++] = malloc(f->map_w * sizeof(int))))
			return (-1);
	}
	return (0);
}

int				ft_check_line(char *line, int size)
{
	int			w;

	w = 0;
	while (w < size)
	{
		if (line[w] != '.' && line[w] != 'O' && line[w] != 'X')
			return (-1);
		w++;
	}
	return (line[w] != '\0' ? -1 : 0);
}

void			ft_free_round(t_filler *f)
{
	int			h;

	h = 0;
	while (h < f->map_h)
	{
		ft_strdel(&f->map[h]);
		h++;
	}
	h = 0;
	while (h < f->piece_h)
	{
		ft_strdel(&f->piece[h]);
		h++;
	}
	ft_memdel((void*)&f->piece);
}
