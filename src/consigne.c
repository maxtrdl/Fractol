/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consigne.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:43:17 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/08 17:51:28 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		write_consigne(void)
{
	ft_putendl("usage : ./fractol [fractale] [couleur 1] [couleur 2]\n");
	ft_putendl("Choix Fractales:");
	ft_putendl("\tMandelbrot, Julia, Burningship\n");
	ft_putendl("Choix couleurs :");
	ft_putendl("\tRose, Rouge, Bleu, Violet, Vert,\n\tJaune, Orange, Noir\n");
}

static int		if_color(char *str)
{
	if (ft_strcmp(str, "Rose") == 0)
		return (1);
	if (ft_strcmp(str, "Rouge") == 0)
		return (1);
	if (ft_strcmp(str, "Bleu") == 0)
		return (1);
	if (ft_strcmp(str, "Violet") == 0)
		return (1);
	if (ft_strcmp(str, "Vert") == 0)
		return (1);
	if (ft_strcmp(str, "Jaune") == 0)
		return (1);
	if (ft_strcmp(str, "Orange") == 0)
		return (1);
	if (ft_strcmp(str, "Noir") == 0)
		return (1);
	return (0);
}

int				consigne(int ac, char **str)
{
	if (ac != 2 && ac != 4)
	{
		write_consigne();
		return (0);
	}
	if ((ft_strcmp(str[1], "Mandelbrot") != 0) && (ft_strcmp(str[1], "Julia") \
				!= 0) && (ft_strcmp(str[1], "Burningship") != 0))
	{
		write_consigne();
		return (0);
	}
	if (ac == 4)
	{
		while (--ac > 1)
		{
			if (if_color(str[ac]) == 0)
			{
				write_consigne();
				return (0);
			}
		}
	}
	return (1);
}
