/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:30:06 by cuzureau          #+#    #+#             */
/*   Updated: 2019/01/02 16:13:12 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void			ft_calcul(t_filler *f, int h, int w)
{
	if (h + 1 < f->map_h)
	{
		f->far[h + 1][w] -= (f->far[h + 1][w] >= 0 ? 1 : 0);
		if (w + 1 < f->map_w)
			f->far[h + 1][w + 1] -= (f->far[h + 1][w + 1] >= 0 ? 1 : 0);
		if (w - 1 >= 0)
			f->far[h + 1][w - 1] -= (f->far[h + 1][w - 1] >= 0 ? 1 : 0);
	}
	if (w + 1 < f->map_w)
		f->far[h][w + 1] -= (f->far[h][w + 1] >= 0 ? 1 : 0);
	if (w - 1 >= 0)
		f->far[h][w - 1] -= (f->far[h][w - 1] >= 0 ? 1 : 0);
	if (h - 1 >= 0)
	{
		f->far[h - 1][w] -= (f->far[h - 1][w] >= 0 ? 1 : 0);
		if (w + 1 < f->map_w)
			f->far[h - 1][w + 1] -= (f->far[h - 1][w + 1] >= 0 ? 1 : 0);
		if (w - 1 >= 0)
			f->far[h - 1][w - 1] -= (f->far[h - 1][w - 1] >= 0 ? 1 : 0);
	}
}

void			ft_calcul2(t_filler *f, int i, int h, int w)
{
	if (h + 1 < f->map_h)
	{
		f->far[h + 1][w] == i ? f->far[h][w] = i + 1 : 0;
		if (w + 1 < f->map_w)
			f->far[h + 1][w + 1] == i ? f->far[h][w] = i + 1 : 0;
		if (w - 1 >= 0)
			f->far[h + 1][w - 1] == i ? f->far[h][w] = i + 1 : 0;
	}
	if (w + 1 < f->map_w)
		f->far[h][w + 1] == i ? f->far[h][w] = i + 1 : 0;
	if (w - 1 >= 0)
		f->far[h][w - 1] == i ? f->far[h][w] = i + 1 : 0;
	if (h - 1 >= 0)
	{
		f->far[h - 1][w] == i ? f->far[h][w] = i + 1 : 0;
		if (w + 1 < f->map_w)
			f->far[h - 1][w + 1] == i ? f->far[h][w] = i + 1 : 0;
		if (w - 1 >= 0)
			f->far[h - 1][w - 1] == i ? f->far[h][w] = i + 1 : 0;
	}
}

void			ft_try(t_filler *f, int i, int j)
{
	int			k;
	int			l;

	k = 0;
	f->low = 0;
	while (k < f->piece_h)
	{
		l = 0;
		while (l < f->piece_w)
		{
			k == i && j == l ? l++ : 0;
			if (f->piece[k][l] == '*')
			{
				if (((k + f->diff_x) < 0 || (k + f->diff_x) > f->map_h - 1 || \
				(l + f->diff_y) < 0 || (l + f->diff_y) > f->map_w - 1 || \
				f->far[k + f->diff_x][l + f->diff_y] <= 0) && (f->low = 10000))
					return ;
				f->low += f->far[k + f->diff_x][l + f->diff_y];
			}
			l++;
		}
		k++;
	}
}
