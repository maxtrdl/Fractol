/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 16:05:57 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/10 11:05:59 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		loop(t_env *env)
{
	if (env->f->up == 1)
	{
		mlx_destroy_image(env->win->mlx, env->image->img);
		mlx_init_img(env);
		init_map(env);
		env->f->up = 0;
		mlx_put_image_to_window(env->win->mlx, \
			env->win->fen, env->image->img, 0, 0);
	}
	return (0);
}

void	print_image(t_env *env)
{
	mlx_hook(env->win->fen, 2, (1L << 0), get_key, env);
	mlx_hook(env->win->fen, 4, 1L << 2, mouse_key, env);
	mlx_hook(env->win->fen, 6, (1L << 0), mouse_m, env);
	mlx_loop_hook(env->win->mlx, loop, env);
	mlx_loop(env->win->mlx);
}
