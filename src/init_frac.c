/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 11:16:43 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/09 14:46:11 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_map(t_env *env)
{
	if (env->f->map == 1)
		init_mandelbrot(env);
	else if (env->f->map == 2)
		init_julia(env);
	else if (env->f->map == 3)
		init_burningship(env);
}

void	init_mandelbrot(t_env *env)
{
	if (env->f->init == 0)
	{
		env->f->x[1] = -2.1;
		env->f->x[2] = 0.6;
		env->f->y[1] = -1.2;
		env->f->y[2] = 1.2;
		env->f->m_x = 0;
		env->f->m_y = 0;
		env->f->j_r = 0;
		env->f->j_i = 0;
		env->f->var = 0;
		env->f->zoom_x = env->win->widht / (env->f->x[2] - env->f->x[1]);
		env->f->zoom_y = env->win->height / (env->f->y[2] - env->f->y[1]);
		env->f->imax = 50;
		env->f->init = 1;
	}
	mandelbrot(env->f, env->image, env->win);
}

void	init_julia(t_env *env)
{
	if (env->f->init == 0)
	{
		env->f->x[1] = -1;
		env->f->x[2] = 1;
		env->f->y[1] = -1.2;
		env->f->y[2] = 1.2;
		env->f->m_x = 0;
		env->f->m_y = 0;
		env->f->j_r = 0;
		env->f->j_i = 0;
		env->f->var = 1;
		env->f->zoom_x = env->win->widht / (env->f->x[2] - env->f->x[1]);
		env->f->zoom_y = env->win->height / (env->f->y[2] - env->f->y[1]);
		env->f->imax = 80;
		env->f->init = 1;
	}
	julia(env->f, env->image, env->win);
}

void	init_burningship(t_env *env)
{
	if (env->f->init == 0)
	{
		env->f->x[1] = -2.1;
		env->f->x[2] = 0.6;
		env->f->y[1] = -2;
		env->f->y[2] = 1;
		env->f->m_x = 0;
		env->f->m_y = 0;
		env->f->j_r = 0;
		env->f->j_i = 0;
		env->f->var = 0;
		env->f->zoom_x = env->win->widht / (env->f->x[2] - env->f->x[1]);
		env->f->zoom_y = env->win->height / (env->f->y[2] - env->f->y[1]);
		env->f->imax = 50;
		env->f->init = 1;
	}
	burningship(env->f, env->image, env->win);
}
