/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checks_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:41:18 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/15 21:28:13 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_format(t_mlx *mlx)
{
	int	y;

	y = 0;
	while (mlx->map[y] != NULL)
	{
		if (ft_strlen(mlx->map[y]) != mlx->width)
		{
			ft_printf ("Error:\nThe map must be rectangular\n");
			ft_close (mlx);
		}
		y++;
	}
	return (0);
}

int	ft_count_player(t_mlx *mlx)
{
	int	x;
	int	y;
	int	player;

	player = 0;
	y = 0;
	while (mlx->map[y] != NULL)
	{
		x = 0;
		while (mlx->map[y][x] != '\0')
		{
			if (mlx->map[y][x] == 'P')
			{
				player = player + 1;
			}
			x++;
		}
		y++;
	}
	if (player != 1)
	{
		ft_printf("Error:\nWrong number of players\n");
		ft_close(mlx);
	}
	return (0);
}

int	ft_count_exit(t_mlx *mlx)
{
	int	x;
	int	y;
	int	exit;

	exit = 0;
	y = 0;
	while (mlx->map[y] != NULL)
	{
		x = 0;
		while (mlx->map[y][x] != '\0')
		{
			if (mlx->map[y][x] == 'E')
			{
				exit = exit + 1;
			}
			x++;
		}
		y++;
	}
	if (exit != 1)
	{
		ft_printf("Error:\nWrong number of exits\n");
		ft_close(mlx);
	}
	return (0);
}

int	ft_check_all(t_mlx *mlx)
{
	ft_swap_n_to_zero(mlx);
	if (ft_valid_map_size (mlx) == 1)
		return (1);
	if (ft_check_map_format (mlx) == 1)
		return (1);
	if (ft_check_border (mlx) == 1)
		return (1);
	if (ft_valid_chars (mlx) == 1)
		return (1);
	if (ft_count_collectibles (mlx) == 1)
		return (1);
	if (ft_count_player (mlx) == 1)
		return (1);
	if (ft_count_exit (mlx) == 1)
		return (1);
	return (0);
}
