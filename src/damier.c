/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:11:40 by jgaillar          #+#    #+#             */
/*   Updated: 2018/03/07 15:11:41 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		fill_parity(t_stuff *e, t_vec *pos, t_damier *a)
{
    a->px = e->c.inter.x - pos->x;
    a->py = e->c.inter.y - pos->y;
    a->pz = e->c.inter.z - pos->z;
	a->x1 = (int)(floor((a->px / LENGHT_PROCED)));
	a->y1 = (int)(floor((a->py / LENGHT_PROCED)));
	a->z1 = (int)(floor((a->pz / LENGHT_PROCED)));
}

void			damier(t_stuff *e, t_rgb *color, t_vec *pos)
{
    t_damier	a;

    fill_parity(e, pos, &a);
    if (a.x1 % 2 == 0)
    {
        if(((a.y1 % 2 == 0) && (a.z1 % 2 == 0)) || \
		(((a.y1 % 2 != 0) && (a.z1 % 2 != 0))))
        {
            color->r = 0;
            color->g = 0;
            color->b = 0;
        }
        else
        {
            color->r = 255;
            color->g = 255;
            color->b = 255;
        }
    }
    else
		damier_sd(e, color, pos, &a);
}

void			damier_sd(t_stuff *e, t_rgb *color, t_vec *pos, t_damier *a)
{
	if (((a->y1 % 2 == 0) && (a->z1 % 2 == 0)) || \
	(((a->y1 % 2 != 0) && (a->z1 % 2 != 0))))
	{
		color->r = 255;
		color->g = 255;
		color->b = 255;
	}
	else
	{
		color->r = 0;
		color->g = 0;
		color->b = 0;
	}
}
