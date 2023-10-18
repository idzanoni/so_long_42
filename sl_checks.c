/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:41:18 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/18 16:31:32 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_map_name(int arg_c, char **arg_v)
{
	int	size;

	if (arg_c != 2)
	{
		if (arg_c < 2)
			ft_printf("Error:\nMissing map\n");
		if (arg_c > 2)
			ft_printf("Error:\nToo many arguments\n");
		return (1);
	}
	size = ft_strlen(arg_v[1]);
	if (size < 5 || ft_strncmp(".ber", arg_v[1] + size - 4, 5))
	{
		ft_printf("Error:\nWrong extension\n");
		return (1);
	}
	return (0);
}

int	ft_valid_map_size(t_mlx *mlx)
{
	mlx->height = ft_matrix_len (mlx->map);
	mlx->width = ft_strlen (mlx->map[0]);
	if (mlx->width > 30 || mlx->height > 15)
	{
		ft_printf ("Error:\nThe map is too big.");
		ft_close(mlx);
	}
	else if (mlx->width < 5 || mlx->height < 3)
	{
		ft_printf ("Error:\nThe map is too small");
		ft_close(mlx);
	}
	else if (mlx->width == mlx->height)
	{
		ft_printf ("Error:\nThe map must be rectangular");
		ft_close(mlx);
	}
	return (0);
}

int	ft_check_border(t_mlx *mlx)
{
	int	i;
	int	max;

	i = 0;
	max = mlx->width;
	if (mlx->width < mlx->height)
		max = mlx->height;
	while (i < max)
	{
		if (mlx->width - i > 0)
			if (mlx->map[0][i] != '1' || \
				mlx->map[mlx->height - 1][i] != '1')
				break ;
		if (mlx->height - i > 0)
			if (mlx->map[i][0] != '1' || \
				mlx->map[i][mlx->width - 1] != '1')
				break ;
		i++;
	}
	if (i != max)
	{
		ft_printf("Error:\nInvalid wall\n");
		ft_close(mlx);
	}
	return (0);
}

int	ft_valid_chars(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (mlx->map[y] != NULL)
	{
		x = 0;
		while (mlx->map[y][x] != '\0')
		{
			if (mlx->map[y][x] != '0' && mlx->map[y][x] != 'E'
				&& mlx->map[y][x] != 'P' && mlx->map[y][x] != 'C'
				&& mlx->map[y][x] != '1')
			{
				ft_printf("Error:\nInvalid char on map\n");
				ft_close(mlx);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_count_collectibles(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map[y] != NULL)
	{
		x = 0;
		while (mlx->map[y][x] != '\0')
		{
			if (mlx->map[y][x] == 'C')
			{
				mlx->collect = mlx->collect + 1;
			}
			x++;
		}
		y++;
	}
	if (mlx->collect == 0)
	{
		ft_printf("Error:\nMissing collectibles\n");
		ft_close(mlx);
	}
	return (0);
}
