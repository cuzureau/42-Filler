/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:20:21 by cuzureau          #+#    #+#             */
/*   Updated: 2018/12/18 13:51:51 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static void		ft_distance2(t_filler *f)
{
	int			h;
	int			w;

	h = 0;
	while (h < f->map_h)
	{
		w = 0;
		while (w < f->map_w)
		{
			f->far[h][w] == 8 ? f->far[h][w] = 0 : 0;
			if (f->far[h][w] < 4 && f->far[h][w] > 0)
				f->far[h][w] *= 4;
			w++;
		}
		h++;
	}
}

static void		ft_distance3(t_filler *f)
{
	int			h;
	int			w;
	int			i;

	i = 1;
	while (i < f->map_w)
	{
		h = 0;
		while (h < f->map_h)
		{
			w = 0;
			while (w < f->map_w)
			{
				f->far[h][w] == 0 ? ft_calcul2(f, i, h, w) : 0;
				w++;
			}
			h++;
		}
		i++;
	}
}

static void		ft_distance4(t_filler *f)
{
	int			h;
	int			w;

	h = 0;
	while (h < f->map_h)
	{
		w = 0;
		while (w < f->map_w)
		{
			f->far[h][w] == 0 ? f->far[h][w] = 99 : 0;
			w++;
		}
		h++;
	}
}

void			ft_distance(t_filler *f)
{
	int			h;
	int			w;

	h = 0;
	while (h < f->map_h)
	{
		w = 0;
		while (w < f->map_w)
		{
			if (f->far[h][w] == -1)
				ft_calcul(f, h, w);
			w++;
		}
		h++;
	}
	ft_distance2(f);
	ft_distance3(f);
	ft_distance4(f);
}
