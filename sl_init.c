/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:37:52 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/13 16:40:25 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char **argv)
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
	mlx->col = 0;
	mlx->line = 0;
	mlx->player_line = 0;
	mlx->player_col = 0;
	mlx->bluey_d = NULL;
	mlx->bluey_l = NULL;
	mlx->bluey_r = NULL;
	mlx->bluey_u = NULL;
	mlx->exit_c = NULL;
	mlx->exit_o = NULL;
	mlx->tile = NULL;
	mlx->wall = NULL;
	mlx->cactus = NULL;
	mlx->balloon = NULL;
	mlx->win = NULL;
}

void	ft_put_pix(t_mlx *mlx, int width, int height)
{
	int	i;
	int	c;

	c = 0;
	while (c <= PIXEL)
	{
		i = 0;
		while (i <= PIXEL)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,
				(width + c), (height + i), 0xaa78AB02);
			i++;
		}
		c++;
	}
}
