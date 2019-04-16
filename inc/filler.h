/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:33:13 by cuzureau          #+#    #+#             */
/*   Updated: 2019/01/02 16:47:15 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../lib/inc/libft.h"

typedef struct	s_filler
{
	int			i;
	int			j;

	char		*line;
	int			round;

	char		me;
	char		it;

	int			map_h;
	int			map_w;

	char		**map;
	int			**far;
	char		**piece;

	int			piece_h;
	int			piece_w;

	int			diff_x;
	int			diff_y;
	int			final_x;
	int			final_y;

	int			low;
	int			lowest;
}				t_filler;

void			ft_distance(t_filler *f);
void			ft_free_all(t_filler *f);
int				main(void);

void			ft_calcul(t_filler *f, int h, int w);
void			ft_calcul2(t_filler *f, int i, int h, int w);
void			ft_try(t_filler *f, int i, int j);

int				ft_exit(t_filler *f);
int				ft_fill_map(t_filler *f);
int				ft_get_map(t_filler *f);
int				ft_get_piece(t_filler *f);
int				ft_get_first(t_filler *f);

int				ft_get_size(char *line, int *h, int*w);
int				ft_alloc_map(char ***tab, int h);
int				ft_alloc_far(t_filler *f);
int				ft_check_line(char *line, int size);
void			ft_free_round(t_filler *f);
void			ft_free_all(t_filler *f);

#endif
