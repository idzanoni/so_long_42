/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checks_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:41:18 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/18 16:52:47 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_format(t_mlx *mlx)
{
	int	y;

	y = 0;
	while (mlx->map[y] != NULL)
	{
		if ((int)ft_strlen(mlx->map[y]) != mlx->width)
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
		ft_printf("Error:\nInvalid number of Players\n");
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
		ft_printf("Error:\nInvalid number of Exits\n");
		ft_close(mlx);
	}
	return (0);
}

char	**ft_dup_map(t_mlx *mlx)
{
	int		y;
	char	**copy;

	copy = malloc((mlx->height + 1) * sizeof(char *));
	if (copy == NULL)
	{
		ft_printf("Error:\nMemory error\n");
		ft_close(mlx);
	}	
	y = 0;
	while (mlx->map[y] != NULL)
	{
		copy[y] = ft_strdup(mlx->map[y]);
		if (copy[y] == NULL)
		{
			ft_free_matrix(copy);
			ft_printf("Error:\nMemory error\n");
			ft_close(mlx);
		}
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

int	ft_check_all(t_mlx *mlx)
{
	char	**temp;

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
	temp = ft_dup_map(mlx);
	if (temp == NULL)
		return (1);
	ft_find_player(mlx);
	ft_flood_fill(temp, mlx->player_y, mlx->player_x);
	ft_flood_fill_check(temp, mlx);
	ft_free_matrix(temp);
	return (0);
}
