/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:00:28 by prossi            #+#    #+#             */
/*   Updated: 2018/03/12 13:28:17 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_save_scene(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
			pixel_put_to_img(&e->i.mlx, x, y, e->i.color.saves.col1);
	}
}

void	save_scene(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
		init_struct(e, 5);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 5);
	}
	draw_save_scene(e);
	save_scene_draw_ellipse_background(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, (WIN_X - WIDTH) * 2, 0);
}
