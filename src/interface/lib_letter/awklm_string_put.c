/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awklm_string_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:01:05 by prossi            #+#    #+#             */
/*   Updated: 2018/03/06 08:03:05 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rt.h"

void	draw_high_letter_td(t_stuff *e)
{
	if (e->lt.charac == 'R')
		R(e);
	else if (e->lt.charac == 'S')
		S(e);
	else if (e->lt.charac == 'T')
		T(e);
	else if (e->lt.charac == 'U')
		U(e);
	else if (e->lt.charac == 'V')
		V(e);
	else if (e->lt.charac == 'W')
		W(e);
	else if (e->lt.charac == 'X')
		X(e);
	else if (e->lt.charac == 'Y')
		Y(e);
	else
		Z(e);
}

void	draw_high_letter_sd(t_stuff *e)
{
	if (e->lt.charac == 'K')
		K(e);
	else if (e->lt.charac == 'L')
		L(e);
	else if (e->lt.charac == 'M')
		M(e);
	else if (e->lt.charac == 'N')
		N(e);
	else if (e->lt.charac == 'O')
		O(e);
	else if (e->lt.charac == 'P')
		P(e);
	else if (e->lt.charac == 'Q')
		Q(e);
	else
		draw_high_letter_td(e);
}

void	draw_high_letter(t_stuff *e)
{
	if (e->lt.charac == 'A')
		A(e);
	else if (e->lt.charac == 'B')
		B(e);
	else if (e->lt.charac == 'C')
		C(e);
	else if (e->lt.charac == 'D')
		D(e);
	else if (e->lt.charac == 'E')
		E(e);
	else if (e->lt.charac == 'F')
		F(e);
	else if (e->lt.charac == 'G')
		G(e);
	else if (e->lt.charac == 'H')
		H(e);
	else if (e->lt.charac == 'I')
		I(e);
	else if (e->lt.charac == 'J')
		J(e);
	else
		draw_high_letter_sd(e);
}

void	draw_numbers(t_stuff *e)
{
	if (e->lt.charac == '0')
		zero(e);
	else if (e->lt.charac == '1')
		one(e);
	else if (e->lt.charac == '2')
		two(e);
}

void	draw_letter(t_stuff *e)
{
	if (e->lt.charac >= 65 && e->lt.charac <= 90)
		draw_high_letter(e);
	if (e->lt.charac >= 48 && e->lt.charac <= 57)
		draw_numbers(e);
}

void	awklm_string_put(char *str, t_stuff *e)
{
	int 	i;
	double	tmp_coeff;
	int		posx;
	int		posy;
	int		space;

	i = -1;
	posx = e->lt.posx;
	posy = e->lt.posy;
	space = e->lt.space;
	while (str[++i])
	{
		tmp_coeff = e->lt.coeff;
		if (i == 0 && (str[i] < 48 || str[i] > 57))
			e->lt.coeff *= 1.5;
		e->lt.charac = str[i];
		draw_letter(e);
		e->lt.posx += space * e->lt.coeff;
		e->lt.coeff = tmp_coeff;
	}
	e->lt.posx = posx;
	e->lt.posy = posy;
}
