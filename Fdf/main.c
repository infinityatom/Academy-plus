/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:57:48 by rbodnare          #+#    #+#             */
/*   Updated: 2016/05/27 18:57:54 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_funct(int keycode)
{
	printf("Key event presed %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_vertex(char ** argv)
{
	int		**matrix;

	matrix = NULL;
	if (!(matrix = ft_read_file(argv[1], matrix)))
	{
		perror("Error: ");
		return (-1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;

	if (argc != 2)
		return (-1);
	if (ft_vertex(argv) == -1)
		return (-1);
	//node camera = node_default;
	//vector3_print(&camera.coord);
	//vector3_print(&camera.rotation);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");

	mlx_pixel_put(mlx, win, 10, 10, 0x00FFFFFF);
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return (0);
}
