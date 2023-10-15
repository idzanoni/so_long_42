/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:36:20 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/15 16:34:07 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	int			check;

	valid_map_name(argc, argv);
	ft_struct_init(&mlx);
	mlx.map = read_map(argv);
	check = valid_map_size (&mlx);
	if (check == 1)
		return (0);
	check = check_border (&mlx);
	if (check == 1)
		return (0);
	check = valid_chars (&mlx);
	if (check == 1)
		return (0);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, (mlx.width * PIXEL),
			(mlx.height * PIXEL), "Bluey!");
	find_player(&mlx);
	ft_put_sprites(&mlx);
	draw_map (&mlx);
	mlx_hook (mlx.win_ptr, 17, (1L << 17), ft_close, NULL);
	mlx_hook (mlx.win_ptr, 2, (1L << 0), ft_key, &mlx);
	mlx_loop (mlx.mlx_ptr);
}

int	check_map_format(t_mlx *mlx)
{
	int	y;

	return (0);
}
