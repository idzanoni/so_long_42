/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:45:30 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/13 16:39:13 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_line(int fd)
{
	int		count;
	char	*string;

	count = 0;
	string = get_next_line(fd);
	while (string != NULL)
	{
		count++;
		free(string);
		string = get_next_line(fd);
	}
	return (count);
}

int	ft_matrix_len(char **matrix)
{
	int	len;

	len = 0;
	if (matrix == NULL)
		return (0);
	while (matrix[len] != NULL)
	{
		len++;
	}
	return (len);
}

int	ft_key(int key, t_mlx *mlx)
{
	if (key == ESC)
	{
		ft_printf("Closing the window and ending the program...\n");
		exit (0);
	}
	else if (key == XK_d || key == XK_D || key == XK_Right)
		key_moves(mlx, 0, 1);
	else if (key == XK_w || key == XK_W || key == XK_Up)
		key_moves(mlx, -1, 0);
	else if (key == XK_s || key == XK_S || key == XK_Down)
		key_moves(mlx, 1, 0);
	else if (key == XK_a || key == XK_A || key == XK_Left)
		key_moves(mlx, 0, -1);
	else
		ft_printf("Key: %c\n", key);
	return (0);
}

void	key_moves(t_mlx *mlx, int sum_y, int sum_x)
{
	find_player(mlx);
	if (mlx->map[mlx->player_line + (sum_y)][mlx->player_col + (sum_x)] == '0')
	{
		mlx->map[mlx->player_line + (sum_y)][mlx->player_col + (sum_x)] = 'P';
		mlx->map[mlx->player_line][mlx->player_col] = '0';
		mlx->moves ++;
	}
	if (mlx->map[mlx->player_line + (sum_y)][mlx->player_col + (sum_x)] == 'C')
	{
		mlx->map[mlx->player_line + (sum_y)][mlx->player_col + (sum_x)] = 'P';
		mlx->map[mlx->player_line][mlx->player_col] = '0';
		mlx->collect --;
		mlx->moves ++;
	}
	if (mlx->map[mlx->player_line + (sum_y)][mlx->player_col + (sum_x)] == 'E' \
		&& mlx->collect == 0)
	{
		mlx->map[mlx->player_line][mlx->player_col] = '0';
		mlx->moves ++;
		ft_printf("\nNice park spot, Rita!\n");
	}
	draw_map(mlx);
}

void	find_player(t_mlx *mlx)
{
	int	height;
	int	width;

	height = 0;
	while (mlx->map[height] != NULL)
	{
		width = 0;
		while (mlx->map[height][width] != '\0')
		{
			if (mlx->map[height][width] == 'P')
			{
				mlx->player_col = width;
				mlx->player_line = height;
				return ;
			}	
			width++;
		}
		height++;
	}
}
