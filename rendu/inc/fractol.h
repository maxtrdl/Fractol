/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:53:46 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/10 10:58:04 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define K_UP 126
# define K_DWN 125
# define K_LFT 123
# define K_RGT 124
# define K_PLS 69
# define K_MNS 78
# define K_RES 15
# define K_ESC 53
# define K_VAR 9

# define C_LFT 1
# define C_RGT 2
# define W_UP 5
# define W_DWN 4

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

typedef struct		s_co
{
	char			*name;
	int				co;
}					t_co;

typedef struct		s_f
{
	double			x[3];
	double			y[3];
	double			zoom_x;
	double			zoom_y;
	double			zoom;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			j_r;
	double			j_i;
	int				m_x;
	int				m_y;
	int				init;
	int				up;
	double			i;
	long int		imax;
	double			tmp;
	double			co;
	int				op;
	double			color1;
	double			color2;
	int				var;
	int				map;
}					t_f;

typedef struct		s_window
{
	int				widht;
	int				height;
	void			*mlx;
	void			*fen;
}					t_window;

typedef struct		s_image
{
	void			*img;
	int				*data;
	int				bpp;
	int				sl;
	int				ed;
}					t_image;

typedef struct		s_env
{
	t_window		*win;
	t_image			*image;
	t_f				*f;
}					t_env;

void				print_image(t_env *env);
int					get_key(int key_code, t_env *env);
int					event_key(t_env *env);
int					init_env(t_env *env);
int					consigne(int ac, char **str);
int					get_color(t_f *f);
void				mlx_init_img(t_env *env);
void				init_map(t_env *env);
void				init_mandelbrot(t_env *env);
void				init_julia(t_env *env);
void				init_burningship(t_env *env);
void				init_color(char *col1, char *col2, t_env *env, int ac);
void				map_choice(char *str, t_env *env);
int					mandelbrot(t_f *f, t_image *image, t_window *win);
int					julia(t_f *f, t_image *image, t_window *win);
int					burningship(t_f *f, t_image *image, t_window *win);
int					mouse_m(unsigned int x, unsigned int y, t_env *env);
int					mouse_key(int button, int x, int y, t_env *env);
void				zoom(int mouse_key, t_env *env);
int					loop(t_env *env);
#endif
