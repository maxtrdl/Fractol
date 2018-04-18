/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 11:33:17 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/09 14:41:30 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_m(unsigned int x, unsigned int y, t_env *env)
{
	int		t_y;
	int		t_x;

	t_y = 0;
	t_x = 0;
	env->f->up = 1;
	if (x > 0 && x < 800 && y > 0 && y < 800)
	{
		t_y = env->f->m_y;
		t_x = env->f->m_x;
		env->f->m_x = x;
		env->f->m_y = y;
	}
	if (env->f->var == 1)
	{
		if (t_x != env->f->m_x || t_y != env->f->m_y)
		{
			env->f->up = 1;
			env->f->up = (env->f->var == 1) ? 1 : 0;
			env->f->j_r = ((double)env->f->m_x * 5) / 8000;
			env->f->j_i = ((double)env->f->m_y * 5) / 8000;
		}
	}
	return (0);
}

int		mouse_key(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == W_UP || button == W_DWN || button == C_LFT || button == C_RGT)
	{
		env->f->up = 1;
		zoom(button, env);
	}
	return (0);
}
