/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:32:41 by cuzureau          #+#    #+#             */
/*   Updated: 2016/11/25 19:44:48 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_memdel(void **ap)
{
	if (!*ap)
		return ;
	if (*ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}
