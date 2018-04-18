/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 10:18:20 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/09 14:46:01 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			zoom(int mouse_key, t_env *env)
{
	double	tmpx;
	double	tmpy;

	tmpx = env->f->zoom_x;
	tmpy = env->f->zoom_y;
	if (mouse_key == C_LFT || mouse_key == W_DWN)
	{
		env->f->zoom_y *= 1.1;
		env->f->zoom_x *= 1.1;
		if (env->f->imax < 2147483647)
			env->f->imax *= 1.1;
	}
	if (mouse_key == C_RGT || mouse_key == W_UP)
	{
		env->f->zoom_x /= 1.1;
		env->f->zoom_y /= 1.1;
		if (env->f->imax > 3)
			env->f->imax /= 1.01;
	}
	env->f->x[1] += (env->f->m_x / tmpx) - (env->f->m_x / env->f->zoom_x);
	env->f->y[1] += (env->f->m_y / tmpy) - (env->f->m_y / env->f->zoom_y);
}

static void		move(int key_code, double tmpx, double tmpy, t_env *env)
{
	if (key_code == K_UP || key_code == K_DWN)
	{
		if (key_code == K_UP && env->f->y[1] < env->f->y[2])
			env->f->op = -1;
		else if (key_code == K_DWN && env->f->y[1] < env->f->y[2])
			env->f->op = 1;
		env->f->y[1] += env->f->op * 0.1 * fabs(env->f->y[2] - env->f->y[1]);
		env->f->y[2] += env->f->op * 0.1 * fabs(env->f->y[2] - tmpy);
	}
	else if (key_code == K_LFT || key_code == K_RGT)
	{
		if (key_code == K_RGT && env->f->x[1] < env->f->x[2])
			env->f->op = 1;
		else if (key_code == K_LFT && env->f->x[1] < env->f->x[2])
			env->f->op = -1;
		env->f->x[1] += env->f->op * 0.1 * fabs(env->f->x[2] - env->f->x[1]);
		env->f->x[2] += env->f->op * 0.1 * fabs(env->f->x[2] - tmpx);
	}
}

int				get_key(int key_code, t_env *env)
{
	if (key_code == K_ESC)
	{
		mlx_destroy_image(env->win->mlx, env->image->img);
		exit(1);
	}
	else if ((key_code >= K_LFT && key_code <= K_UP) ||\
		key_code == K_PLS || key_code == K_MNS || key_code == \
		K_RES || key_code == K_VAR)
	{
		env->f->up = 1;
		if (key_code >= K_LFT && key_code <= K_UP)
			move(key_code, env->f->x[1], env->f->y[1], env);
		if (key_code == K_RES)
			env->f->init = 0;
		if (key_code == K_PLS && (env->f->imax * 1.5) < 2147483647)
			env->f->imax *= 1.5;
		if (key_code == K_MNS && env->f->imax > 3)
			env->f->imax /= 1.1;
		if (key_code == K_VAR)
			env->f->var = (env->f->var == 0) ? 1 : 0;
	}
	return (0);
}
