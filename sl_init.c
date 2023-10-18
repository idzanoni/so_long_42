/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:37:52 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/17 20:54:27 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(t_mlx *mlx)
{
	ft_find_player(mlx);
	ft_put_sprites(mlx);
}

char	**ft_read_map(char **argv)
{
	int		fd;
	int		count_line;
	int		i;
	char	*line;
	char	**map;

	fd = open(argv[1], O_RDONLY);
	count_line = ft_count_line(fd);
	close (fd);
	map = (char **) malloc ((count_line + 1) * sizeof (char *));
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	ft_struct_init(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->map = NULL;
	mlx->width = 0;
	mlx->height = 0;
	mlx->player = NULL;
	mlx->collect = 0;
	mlx->moves = 0;
	mlx->player_y = 0;
	mlx->player_x = 0;
	mlx->bluey_d = NULL;
	mlx->bluey_l = NULL;
	mlx->bluey_r = NULL;
	mlx->bluey_u = NULL;
	mlx->exit_c = NULL;
	mlx->exit_o = NULL;
	mlx->tile = NULL;
	mlx->wall = NULL;
	mlx->balloon = NULL;
	mlx->background = NULL;
}

void	ft_swap_n_to_zero(t_mlx *mlx)
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
			if (mlx->map[y][x] == '\n' || mlx->map[y][x] == '\r')
				mlx->map[y][x] = '\0';
			x++;
		}
		y++;
	}
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
