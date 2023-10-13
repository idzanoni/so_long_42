/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:26:24 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/13 15:28:38 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_sprites(t_mlx *mlx)
{
	ft_xpm_to_img(mlx, &mlx->bluey_d, BLUEY_D);
	ft_xpm_to_img(mlx, &mlx->bluey_l, BLUEY_L);
	ft_xpm_to_img(mlx, &mlx->bluey_r, BLUEY_R);
	ft_xpm_to_img(mlx, &mlx->bluey_u, BLUEY_U);
	ft_xpm_to_img(mlx, &mlx->exit_c, EXIT_C);
	ft_xpm_to_img(mlx, &mlx->exit_o, EXIT_O);
	ft_xpm_to_img(mlx, &mlx->tile, TILE);
	ft_xpm_to_img(mlx, &mlx->wall, WALL);
	ft_xpm_to_img(mlx, &mlx->cactus, CACTUS);
	ft_xpm_to_img(mlx, &mlx->balloon, BALLOON);
	ft_xpm_to_img(mlx, &mlx->win, WIN);
}

int	ft_xpm_to_img(t_mlx *mlx, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{
		ft_printf("Error:\nSprites error\n");
		exit (0);
	}
	return (0);
}

void	draw_map(t_mlx *mlx)
{
	int	y;
	int	x;

	y = -1;
	while (mlx->map[++y] != NULL)
	{
		x = 0;
		while (mlx->map[y][x] != '\0')
		{
			if (mlx->map[y][x] == 'P')
				ft_img_to_win(mlx, mlx->bluey_d, x, y);
			else if (mlx->map[y][x] == 'C')
				ft_img_to_win(mlx, mlx->balloon, x, y);
			else if (mlx->map[y][x] == 'E')
				ft_img_to_win(mlx, mlx->exit_o, x, y);
			else if (mlx->map[y][x] == '0')
				ft_img_to_win(mlx, mlx->tile, x, y);
			else if (mlx->map[y][x] == '1')
				ft_img_to_win(mlx, mlx->wall, x, y);
			x++;
		}
	}
	ft_put_pix(mlx, 0, 0);
	ft_show_moves(mlx);
}

void	ft_img_to_win(t_mlx *mlx, void *image, int width, int height)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, image,
		width * PIXEL, height * PIXEL);
}

int	ft_show_moves(t_mlx *mlx)
{
	char	*moves;

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 5, 37, 0x01000000, "Moves: ");
	moves = ft_itoa(mlx->moves);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 37, 0x01000000, moves);
	free(moves);
	return (0);
}