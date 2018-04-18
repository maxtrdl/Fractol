/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:01:23 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/09 15:15:53 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		commun_frac(t_f *f, t_image *image, t_window *win)
{
	f->i = 0;
	while ((f->z_r * f->z_r + f->z_i * f->z_i + f->c_r) < 4 && f->i < f->imax)
	{
		f->tmp = f->z_r;
		f->z_r = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
		if (f->map == 1 || f->map == 2)
			f->z_i = 2 * f->z_i * f->tmp + f->c_i;
		else
			f->z_i = 2 * fabs(f->z_i) * fabs(f->tmp) + f->c_i;
		f->i++;
	}
	if (f->i == f->imax)
		image->data[(int)(f->x[0] + f->y[0] * win->widht)] = get_color(f);
	else
		image->data[(int)(f->x[0] + f->y[0] * win->widht)] = get_color(f);
}

int				mandelbrot(t_f *f, t_image *image, t_window *win)
{
	f->y[0] = 0;
	while (f->y[0] < win->height)
	{
		f->x[0] = 0;
		while (f->x[0] < win->widht)
		{
			f->c_r = f->x[0] / f->zoom_x + f->x[1];
			f->c_i = f->y[0] / f->zoom_y + f->y[1];
			f->z_r = 0;
			f->z_i = 0;
			commun_frac(f, image, win);
			f->x[0] += 1;
		}
		f->y[0] += 1;
	}
	return (0);
}

int				julia(t_f *f, t_image *image, t_window *win)
{
	f->y[0] = 0;
	while (f->y[0] < win->height)
	{
		f->x[0] = 0;
		while (f->x[0] < win->widht)
		{
			f->z_r = f->x[0] / f->zoom_x + f->x[1];
			f->z_i = f->y[0] / f->zoom_y + f->y[1];
			f->c_r = 0.285 + f->j_r;
			f->c_i = 0.01 + f->j_i;
			commun_frac(f, image, win);
			f->x[0] += 1;
		}
		f->y[0] += 1;
	}
	return (0);
}

int				burningship(t_f *f, t_image *image, t_window *win)
{
	f->y[0] = 0;
	while (f->y[0] < win->height)
	{
		f->x[0] = 0;
		while (f->x[0] < win->widht)
		{
			f->c_r = f->x[0] / f->zoom_x + f->x[1];
			f->c_i = f->y[0] / f->zoom_y + f->y[1];
			f->z_r = 0;
			f->z_i = 0;
			commun_frac(f, image, win);
			f->x[0] += 1;
		}
		f->y[0] += 1;
	}
	return (0);
}
