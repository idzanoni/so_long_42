/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:36:20 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/15 21:28:20 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	int			check;

	if (ft_valid_map_name (argc, argv) == 1)
		return (0);
	ft_struct_init (&mlx);
	mlx.map = ft_read_map (argv);
	check = ft_check_all (&mlx);
	if (check == 1)
		return (0);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, (mlx.width * PIXEL),
			(mlx.height * PIXEL), "Bluey!");
	ft_init_game (&mlx);
	mlx_hook (mlx.win_ptr, 17, (1L << 17), ft_close, NULL);
	mlx_hook (mlx.win_ptr, 2, (1L << 0), ft_key, &mlx);
	mlx_loop (mlx.mlx_ptr);
}

void	ft_init_game(t_mlx *mlx)
{
	ft_find_player(mlx);
	ft_put_sprites(mlx);
	ft_draw_map (mlx);
}
