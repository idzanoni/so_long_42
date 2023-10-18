/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:43:23 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/17 20:26:41 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_mlx *mlx)
{
	if (mlx->mlx_ptr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->bluey_d);
		mlx_destroy_image(mlx->mlx_ptr, mlx->bluey_l);
		mlx_destroy_image(mlx->mlx_ptr, mlx->bluey_r);
		mlx_destroy_image(mlx->mlx_ptr, mlx->bluey_u);
		mlx_destroy_image(mlx->mlx_ptr, mlx->exit_c);
		mlx_destroy_image(mlx->mlx_ptr, mlx->exit_o);
		mlx_destroy_image(mlx->mlx_ptr, mlx->tile);
		mlx_destroy_image(mlx->mlx_ptr, mlx->wall);
		mlx_destroy_image(mlx->mlx_ptr, mlx->balloon);
		mlx_destroy_image(mlx->mlx_ptr, mlx->background);
		mlx_destroy_window (mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
	}
	ft_free_matrix(mlx->map);
	free(mlx->mlx_ptr);
	exit (0);
	return (0);
}

void	ft_free_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free (matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_flood_fill(char **copy, int y, int x)
{
	if (copy[y][x] == '1' || copy[y][x] == 'X' || copy[y][x] == 'x')
		return ;
	if (copy[y][x] == 'E')
	{
		copy[y][x] = 'x';
		return ;
	}
	copy[y][x] = 'X';
	ft_flood_fill(copy, y + 1, x);
	ft_flood_fill(copy, y - 1, x);
	ft_flood_fill(copy, y, x + 1);
	ft_flood_fill(copy, y, x - 1);
}

void	ft_flood_fill_check(char **copy, t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (copy[y] != NULL)
	{
		x = 0;
		while (copy[y][x] != '\0')
		{
			if (copy[y][x] == 'E')
			{
				ft_printf ("Error:\nImpossible to access exit\n");
				ft_free_matrix (copy);
				ft_close (mlx);
			}
			if (copy[y][x] == 'C')
			{
				ft_printf ("Error:\nImpossible to access collectible\n");
				ft_free_matrix (copy);
				ft_close (mlx);
			}
			x++;
		}
		y++;
	}
}
