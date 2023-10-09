/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:36:20 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/09 20:40:34 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char **argv);
int		ft_key(int tecla, t_mlx *mlx);
void	ft_put_pix(t_mlx *mlx, int width, int height);
int		ft_matrix_len(char **matrix);
void	draw_map(t_mlx *mlx);
int		valid_map_size(t_mlx *mlx);
void	find_player(t_mlx *mlx);
int		valid_map_name(int arg_c, char **arg_v);
int		ft_xpm_to_img(t_mlx *mlx, void **image, char *path);
void	ft_put_sprites(t_mlx *mlx);
int		ft_show_moves(t_mlx *mlx);
void	ft_struct_init(t_mlx *mlx);
int		ft_close(t_mlx *mlx);
void	key_moves(t_mlx *mlx, int sum_y, int sum_x);
void	ft_img_to_win(t_mlx *mlx, void *image, int width, int height);
int		ft_count_line(int fd);

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	int			width;
	int			check;

	valid_map_name(argc, argv);
	ft_struct_init(&mlx);
	mlx.map = read_map(argv);
	check = valid_map_size (&mlx);
	if (check == 1)
		return (0);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, (mlx.width * PIXEL),
			(mlx.height * PIXEL), "Bluey!");
	find_player(&mlx);
	ft_put_sprites(&mlx);
	draw_map (&mlx);
	mlx_hook (mlx.win_ptr, 17, (1L << 17), ft_close, NULL);
	mlx_hook (mlx.win_ptr, 2, (1L << 0), ft_key, &mlx);
	mlx_loop (mlx.mlx_ptr);
}

void	ft_struct_init(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->map = NULL;
	mlx->width = 0;
	mlx->height = 0;
	mlx->player = NULL;
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

int	ft_show_moves(t_mlx *mlx)
{
	char	*moves;

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 5, 37, 0x01000000, "Moves: ");
	moves = ft_itoa(mlx->moves);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 37, 0x01000000, moves);
	free(moves);
	return (0);
}

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
		exit (0);
	}
	return (0);
}

int	valid_map_name(int arg_c, char **arg_v)
{
	int	size;

	if (arg_c != 2)
	{
		ft_printf("Missing map\n");
		return (1);
	}
	size = ft_strlen(arg_v[1]);
	if (size < 5 || ft_strncmp(".ber", arg_v[1] + size - 4, 5))
	{
		ft_printf("Wrong extension\n");
		return (1);
	}
	return (0);
}

int	valid_map_size(t_mlx *mlx)
{
	mlx->height = ft_matrix_len (mlx->map);
	mlx->width = ft_strlen (mlx->map[0]) - 1;
	if (mlx->width > 30 || mlx->height > 15)
	{
		ft_printf ("The map is too big.");
		exit(0);
		return (1);
	}
	else if (mlx->width < 5 || mlx->height < 3)
	{
		ft_printf ("The map is too small");
		exit(0);
		return (2);
	}
	return (0);
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

int	ft_close(t_mlx *mlx)
{
	// mlx_destroy_image(mlx->mlx_ptr, mlx->spt);
	// mlx_destroy_image(mlx->mlx_ptr, spt->bluey_l);
	// mlx_destroy_image(mlx->mlx_ptr, spt->bluey_r);
	// mlx_destroy_image(mlx->mlx_ptr, spt->bluey_u);
	// mlx_destroy_image(mlx->mlx_ptr, spt->exit_c);
	// mlx_destroy_image(mlx->mlx_ptr, spt->exit_o);
	// mlx_destroy_image(mlx->mlx_ptr, spt->tile);
	// mlx_destroy_image(mlx->mlx_ptr, spt->wall);
	// mlx_destroy_image(mlx->mlx_ptr, spt->cactus);
	// mlx_destroy_image(mlx->mlx_ptr, spt->balloon);
	// mlx_destroy_image(mlx->mlx_ptr, spt->win);
	// ft_free_matrix(mlx->map);
	// mlx_destroy_window (mlx->mlx_ptr, mlx->win_ptr);
	// mlx_destroy_display(mlx->mlx_ptr);
	// free(mlx->mlx_ptr);
	exit (0);
	return (0);
}

int	ft_key(int tecla, t_mlx *mlx)
{
	if (tecla == ESC)
	{
		ft_printf("Closing the window and ending the program...\n");
		exit (0);
	}
	else if (tecla == XK_Right)
		key_moves(mlx, 0, 1);
	else if (tecla == XK_Up)
		key_moves(mlx, -1, 0);
	else if (tecla == XK_Down)
		key_moves(mlx, 1, 0);
	else if (tecla == XK_Left)
		key_moves(mlx, 0, -1);
	else
		ft_printf("Voce pressionou a tecla: %c\n", tecla);
	return (0);
}

void	key_moves(t_mlx *mlx, int sum_y, int sum_x)
{
	if ((mlx->map[mlx->player_line + (sum_y)][mlx->player_col + (sum_x)]) == '1'
	|| (mlx->map[mlx->player_line + (sum_y)][mlx->player_col + (sum_x)]) == 'E')
		return ;
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

char **read_map(char **argv)
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
