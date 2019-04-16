/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:35:15 by cuzureau          #+#    #+#             */
/*   Updated: 2019/01/02 16:50:06 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void			ft_find_star(t_filler *f, int h, int w)
{
	int			i;
	int			j;

	i = 0;
	while (i < f->piece_h)
	{
		j = 0;
		while (j < f->piece_w)
		{
			if (f->piece[i][j] == '*')
			{
				f->diff_x = h - i;
				f->diff_y = w - j;
				ft_try(f, i, j);
				if (f->low < f->lowest)
				{
					f->lowest = f->low;
					f->final_x = f->diff_x;
					f->final_y = f->diff_y;
				}
			}
			j++;
		}
		i++;
	}
}

void			ft_find_me(t_filler *f)
{
	int			h;
	int			w;

	h = 0;
	f->lowest = 10000;
	while (h < f->map_h)
	{
		w = 0;
		while (w < f->map_w)
		{
			if (f->map[h][w] == f->me)
				ft_find_star(f, h, w);
			w++;
		}
		h++;
	}
}

void			ft_free_all(t_filler *f)
{
	int			h;

	h = 0;
	while (h < f->map_h)
	{
		ft_memdel((void*)&f->far[h]);
		h++;
	}
	ft_memdel((void*)&f->far);
	ft_memdel((void*)&f->map);
}

int				main(void)
{
	t_filler	f;

	ft_bzero(&f, sizeof(f));
	while (1)
	{
		if (f.round == 0)
			if (ft_get_first(&f) < 0)
				return (-1);
		if (ft_get_map(&f) < 0)
			return (-1);
		if (ft_get_piece(&f) < 0)
			return (-1);
		ft_distance(&f);
		ft_find_me(&f);
		ft_free_round(&f);
		if (f.lowest == 10000)
			break ;
		else
			ft_printf("%d %d\n", f.final_x, f.final_y);
		f.round++;
	}
	ft_printf("0 0\n");
	ft_free_all(&f);
	return (0);
}
