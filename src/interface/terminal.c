/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:26:52 by prossi            #+#    #+#             */
/*   Updated: 2018/02/12 11:20:27 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_terminal(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.img_y)
	{
		x = -1;
		while (++x < e->i.img_x)
		{
			pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
		}
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, 0, (WIN_Y - LENGTH) * 3);
}

void	aff_angle(t_stuff *e)
{
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Valeur de l'angle en degre ? : ");
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
}

void	aff_value(t_stuff *e)
{
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Valeur de la translation ? : ");
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
}

void	aff_tab(t_stuff *e)
{
	if (e->i.term.tabfill == 1)
	{
		if (e->i.term.indextab >= 0)
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + (0 * 40), 0xFFFFFF, e->i.term.tab[0]);
		if (e->i.term.indextab >= 1)
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + (1 * 40), 0xFFFFFF, e->i.term.tab[1]);
		if (e->i.term.indextab > 2)
		{
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + (2 * 40), 0xFFFFFF, e->i.term.tab[2]);
			free2d(e);
			e->i.term.indextab = 0;
			e->i.term.tabfill = 0;
			e->i.term.first = 0;
		}
	}
}

void	end_aff(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(35)))
		err = 1;
	if (err == 0)
	{
		if (e->i.mat.act_angle == 1)
		{
			tmp = ft_strcpy(tmp, "Valeur de l'angle en degre ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->m.angle = ft_atoi(e->i.term.wbuf);
		}
		if (e->i.mat.act_value == 1)
		{
			tmp = ft_strcpy(tmp, "Valeur de la translation ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->m.value = ft_atoi(e->i.term.wbuf);
		}
		e->i.term.tab[e->i.term.indextab] = ft_strcpy(e->i.term.tab[e->i.term.indextab], tmp);
		e->i.term.tabfill = 1;
		ft_strdel(&e->i.term.wbuf);
		ft_strdel(&tmp);
	}
	else
		ft_putstr("\nMalloc error in end_aff - terminal (interface)\n");
}

void	terminal(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - ((WIN_Y - LENGTH) * 3);
		new_img(e);
		init_struct(e, 2);
		draw_terminal(e);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 3);
		draw_terminal(e);
		if (e->i.mat.act_angle == 1 && e->i.term.wbuf[e->i.term.index] != '\n')
			aff_angle(e);
		if (e->i.mat.act_value == 1 && e->i.term.wbuf[e->i.term.index] != '\n')
			aff_value(e);
		if (e->i.term.wbuf[e->i.term.index] == '\n')
		{
			end_aff(e);
			e->i.mat.act_angle = 0;
			e->i.mat.act_value = 0;
			e->i.term.index = 0;
			e->i.term.indextab++;
		}
		aff_tab(e);
	}
}