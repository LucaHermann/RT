/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:33:45 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 09:33:46 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	b_sd(t_stuff *e)
{
	e->bs.width--;
	e->bs.height--;
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 4);
	ft_ellipse(e, 1, 6);
	ft_init_segment_b(e, 5);
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 4);
	ft_ellipse(e, 1, 6);
	e->bs.width--;
	e->bs.height--;
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 4);
	ft_ellipse(e, 1, 6);
	e->bs.width--;
	e->bs.height--;
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 4);
	ft_ellipse(e, 1, 6);
}

void	b(t_stuff *e)
{
	ft_init_segment_b(e, 1);
	ft_segment_letter(e);
	ft_init_segment_b(e, 2);
	ft_segment_letter(e);
	ft_init_segment_b(e, 3);
	ft_segment_letter(e);
	ft_init_segment_b(e, 4);
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 4);
	ft_ellipse(e, 1, 6);
	e->bs.width--;
	e->bs.height--;
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 4);
	ft_ellipse(e, 1, 6);
	b_sd(e);
}
