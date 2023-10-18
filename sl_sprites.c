/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:26:24 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/18 16:01:41 by izanoni          ###   ########.fr       */
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
	ft_xpm_to_img(mlx, &mlx->balloon, BALLOON);
	ft_xpm_to_img(mlx, &mlx->background, BACKGROUND);
	mlx->player = mlx->bluey_d;
}

int	ft_xpm_to_img(t_mlx *mlx, void **image, char *path)
{
	int	x;
	int	y;

	*image = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &x, &y);
	if (*image == NULL)
	{
		ft_printf("Error:\nSprites error\n");
		ft_close (mlx);
	}
	return (0);
}

int	ft_draw_map(t_mlx *mlx)
{
	int	y;
	int	x;

	y = -1;
	while (mlx->map[++y] != NULL)
	{
		x = -1;
		while (mlx->map[y][++x] != '\0')
		{
			if (mlx->map[y][x] == 'P')
				ft_img_to_win(mlx, mlx->player, x, y);
			else if (mlx->map[y][x] == 'C')
				ft_img_to_win(mlx, mlx->balloon, x, y);
			else if (mlx->map[y][x] == 'E' && mlx->collect != 0)
				ft_img_to_win(mlx, mlx->exit_c, x, y);
			else if (mlx->map[y][x] == 'E' && mlx->collect == 0)
				ft_img_to_win(mlx, mlx->exit_o, x, y);
			else if (mlx->map[y][x] == '0')
				ft_img_to_win(mlx, mlx->tile, x, y);
			else if (mlx->map[y][x] == '1')
				ft_img_to_win(mlx, mlx->wall, x, y);
		}
	}
	ft_adjust_drawing(mlx);
	return (0);
}

void	ft_adjust_drawing(t_mlx *mlx)
{
	ft_img_to_win(mlx, mlx->background, 0, 0);
	ft_show_moves(mlx);
}

void	ft_img_to_win(t_mlx *mlx, void *image, int width, int height)
{
	if (image == mlx->wall && !width && !height)
		return ;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, image,
		width * PIXEL, height * PIXEL);
}
