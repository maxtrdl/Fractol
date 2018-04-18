/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:10:09 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/05 16:51:15 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	map_choice(char *str, t_env *env)
{
	env->f->init = 0;
	env->f->up = 1;
	env->f->op = 0;
	if (!ft_strcmp(str, "Mandelbrot"))
		env->f->map = 1;
	else if (!ft_strcmp(str, "Julia"))
		env->f->map = 2;
	else if (!ft_strcmp(str, "Burningship"))
		env->f->map = 3;
	init_map(env);
}

void	mlx_init_img(t_env *env)
{
	env->image->img = mlx_new_image(env->win->mlx, \
			env->win->widht, env->win->height);
	env->image->data = (int *)mlx_get_data_addr(env->image->img\
			, &env->image->bpp, &env->image->sl, &env->image->ed);
}

void	mlx_init_win(t_env *env)
{
	env->win->mlx = mlx_init();
	env->win->widht = 800;
	env->win->height = 800;
	env->win->fen = mlx_new_window(env->win->mlx\
			, env->win->widht, env->win->height, "fractol");
	mlx_init_img(env);
}

int		init_env(t_env *env)
{
	if (!(env->win = (t_window *)malloc(sizeof(t_window))))
		return (0);
	if (!(env->image = (t_image *)malloc(sizeof(t_image))))
		return (0);
	if (!(env->f = (t_f *)malloc(sizeof(t_f))))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_env		*env;

	if (!(consigne(argc, argv)))
		return (-1);
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if (!(init_env(env)))
		return (-1);
	mlx_init_win(env);
	init_color(argv[2], argv[3], env, argc);
	map_choice(argv[1], env);
	print_image(env);
	return (0);
}
