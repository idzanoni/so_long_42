/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:36:20 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/18 20:09:39 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	if (ft_valid_map_name (argc, argv) == 1)
		return (0);
	ft_struct_init (&mlx);
	mlx.map = ft_read_map (argv);
	ft_check_all (&mlx);
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
	{
		ft_printf("Error:\nMlx error\n");
		ft_close(&mlx);
	}
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, (mlx.width * PIXEL),
			(mlx.height * PIXEL), "Bluey!");
	if (mlx.win_ptr == NULL)
	{
		ft_printf("Error:\nMlx error\n");
		ft_close(&mlx);
	}
	ft_init_game (&mlx);
	mlx_hook (mlx.win_ptr, 17, (1L << 17), ft_close, &mlx);
	mlx_hook (mlx.win_ptr, 2, (1L << 0), ft_key, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, ft_draw_map, &mlx);
	mlx_loop (mlx.mlx_ptr);
}
