/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:42:03 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/08 17:47:39 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(t_f *f)
{
	int		tmp;

	tmp = 0;
	if (f->i == f->imax)
		return (f->color2);
	else
	{
		tmp = (int)(f->i * f->color1) % 16711680;
		if (tmp <= 2147483647 && tmp > 0)
			return (tmp);
		else
			return (f->color1);
	}
}

void	init_color(char *col1, char *col2, t_env *env, int ac)
{
	int			i;
	static t_co	col[8] = {
		{"Rose", (int)0x00FE28F0},
		{"Rouge", (int)0x00EA0037},
		{"Bleu", (int)0x000073F7},
		{"Violet", (int)0x00EB00F3},
		{"Vert", (int)0x0000F018},
		{"Jaune", (int)0x00E0F000},
		{"Orange", (int)0x00F09000},
		{"Noir", (int)0x00000000},
	};

	i = -1;
	while (++i < 8 && ac == 4)
	{
		if (!strcmp(col1, col[i].name))
			env->f->color1 = col[i].co;
		if (!strcmp(col2, col[i].name))
			env->f->color2 = col[i].co;
	}
	if (ac != 4)
	{
		env->f->color1 = col[2].co;
		env->f->color2 = col[7].co;
	}
}
