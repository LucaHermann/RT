/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:00:01 by jgaillar          #+#    #+#             */
/*   Updated: 2018/02/08 15:24:07 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		shadows(t_stuff *e, t_vec *inter, t_rgb color)
{
	t_rgb caca;

	caca.r = 0;
	caca.g = 0;
	caca.b = 0;

	reboot_list_loop(e, 2);
	while (e->light)
	{
		reboot_list_loop(e, 1);
		getlightdir(e, e->c.inter);
		check(e, &e->light->lightdir, &e->c.inter, 2);
		check_dist(e, 2);
		if (e->c.dist < e->light->t && e->c.dist > 0.00001 && e->c.obj != LIGHT)
			rgb_add(&e->c.colorf, caca, color, 0.8);
		e->light = e->light->next;
	}
	return (0);
}

t_rgb		reflect(t_stuff *e, int obj, int nm)
{
	t_vec tmp;
	t_rgb tmp2;

	reboot_list_loop(e, 3);
	e->ref->tmpcolor = e->c.colorf;
	e->ref->tmpl = e->l;
	e->ref->tmpinter = e->c.inter;
	e->ref->tmpscolor = e->d.color;
	e->ref->objet = e->c.obj;
	if (obj == SPHERE)
	{
		searchlist(e, e->c.objsph, SPHERE);
		e->ref->tmpsph = e->sph;
		tmp = getrefray(e, &e->sph->norm, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		tmp2 = raythingy(e, &tmp, &e->c.inter);
		e->sph = e->ref->tmpsph;
	}
	else if (obj == PLAN)
	{
		searchlist(e, e->c.objpla, PLAN);
		e->ref->tmpplan = e->pla;
		tmp = getrefray(e, &e->pla->norm, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		tmp2 = raythingy(e, &tmp, &e->c.inter);
		e->pla = e->ref->tmpplan;
	}
	else if (obj == CYLINDRE)
	{
		searchlist(e, e->c.objcyl, CYLINDRE);
		e->ref->tmpcyl = e->cyl;
		tmp = getrefray(e, &e->cyl->norml, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		tmp2 = raythingy(e, &tmp, &e->c.inter);
		e->cyl = e->ref->tmpcyl;
	}
	else if (obj == CONE)
	{
		searchlist(e, e->c.objcone, CONE);
		e->ref->tmpcone = e->cone;
		tmp = getrefray(e, &e->cone->norml, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		tmp2 = raythingy(e, &tmp, &e->c.inter);
		e->cone = e->ref->tmpcone;
	}
	e->c.colorf = e->ref->tmpcolor;
	e->l = e->ref->tmpl;
	e->c.inter = e->ref->tmpinter;
	e->d.color = e->ref->tmpscolor;
	e->c.obj = e->ref->objet;
	return (tmp2);
}
