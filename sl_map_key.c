/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:45:30 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/15 20:46:30 by izanoni          ###   ########.fr       */
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
	if (key == XK_Escape)
		ft_close (mlx + \
		ft_printf ("Closing the window and ending the program...\n") * 0);
	else if (key == XK_d || key == XK_D || key == XK_Right)
	{
		mlx->player = mlx->bluey_r;
		ft_key_moves (mlx, 0, 1);
	}	
	else if (key == XK_w || key == XK_W || key == XK_Up)
	{
		mlx->player = mlx->bluey_u;
		ft_key_moves (mlx, -1, 0);
	}
	else if (key == XK_s || key == XK_S || key == XK_Down)
	{
		mlx->player = mlx->bluey_d;
		ft_key_moves (mlx, 1, 0);
	}
	else if (key == XK_a || key == XK_A || key == XK_Left)
	{
		mlx->player = mlx->bluey_l;
		ft_key_moves (mlx, 0, -1);
	}
	return (0);
}

int	ft_key_moves(t_mlx *mlx, int sum_y, int sum_x)
{
	if (mlx->map[mlx->player_line + sum_y][mlx->player_col + sum_x] == '0'
		|| mlx->map[mlx->player_line + sum_y][mlx->player_col + sum_x] == 'C')
	{
		if (mlx->map[mlx->player_line + sum_y][mlx->player_col + sum_x] == 'C')
			mlx->collect --;
		mlx->map[mlx->player_line + sum_y][mlx->player_col + sum_x] = 'P';
		mlx->map[mlx->player_line][mlx->player_col] = '0';
		mlx->moves ++;
		mlx->player_line = mlx->player_line + sum_y;
		mlx->player_col = mlx->player_col + sum_x;
	}
	if (mlx->map[mlx->player_line + sum_y][mlx->player_col + sum_x] == 'E' \
		&& mlx->collect == 0)
	{
		mlx->map[mlx->player_line][mlx->player_col] = '0';
		mlx->moves ++;
		ft_printf("\nNice park spot, Rita!\n");
		ft_close(mlx);
	}
	ft_draw_map(mlx);
	return (1);
}

void	ft_find_player(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (mlx->map[y] != NULL)
	{
		x = 0;
		while (mlx->map[y][x] != '\0')
		{
			if (mlx->map[y][x] == 'P')
			{
				mlx->player_col = x;
				mlx->player_line = y;
				return ;
			}	
			x++;
		}
		y++;
	}
}
