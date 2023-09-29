/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:36:20 by izanoni           #+#    #+#             */
/*   Updated: 2023/09/29 18:45:49 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char **argv);
int		ft_close(void *v);
int		ft_key(int tecla, t_mlx *mlx);
void	ft_put_pix(t_mlx *mlx, int width, int height, int color);
int		ft_matrix_len(char **matrix);
void	draw_map(t_mlx *mlx);
int		valid_map_size(t_mlx *mlx);
void	find_player(t_mlx *mlx);
int		valid_map_name(int arg_c, char **arg_v);
int		xpm_to_img(t_mlx *mlx);

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		width;
	int		check;

	valid_map_name(argc, argv);
	mlx.map = read_map(argv);
	check = valid_map_size (&mlx);
	if (check == 1)
		return (0);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, (mlx.width * PIXEL), (mlx.height * PIXEL), "so_long");
	find_player(&mlx);
	xpm_to_img(&mlx);
	draw_map (&mlx);
	mlx_hook (mlx.win_ptr, 17, (1L << 17), ft_close, NULL);
	mlx_hook (mlx.win_ptr, 2, (1L << 0), ft_key, &mlx);
	mlx_loop (mlx.mlx_ptr);
}

int	xpm_to_img(t_mlx *mlx)
{
	int	width;
	int	height;

	mlx->bluey_d = mlx_xpm_file_to_image(mlx->mlx_ptr, BLUEY_D, &width, &height);
	if (!mlx->bluey_d)
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
		ft_printf("Missing map\nMust be: 'so_long.a ./so_long <filename>.ber'");
		return (1);
	}
	size = ft_strlen(arg_v[1]);
	if (size < 5 || ft_strncmp(".ber", arg_v[1] + size - 4, 5))
	{
		ft_printf("Wrong extension\nMust be: ./so_long <filename>.ber\n");
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

void	draw_map(t_mlx *mlx)
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
				// ft_put_pix (mlx, width * PIXEL, height * PIXEL, 0xaaFFFF00);
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->bluey_d, width * PIXEL, height * PIXEL);
			if (mlx->map[height][width] == 'C')
				ft_put_pix (mlx, width * PIXEL, height * PIXEL, 0xaaFF00FF);
			if (mlx->map[height][width] == 'E')
				ft_put_pix (mlx, width * PIXEL, height * PIXEL, 0xaaFF0000);
			if (mlx->map[height][width] == '0')
				ft_put_pix (mlx, width * PIXEL, height * PIXEL, 0xaa0000FF);
			else if (mlx->map[height][width] == '1')
				ft_put_pix (mlx, width * PIXEL, height * PIXEL, 0xaa00FF00);
			width++;
		}
		height++;
	}
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

void	ft_put_pix(t_mlx *mlx, int width, int height, int color)
{
	int	i;
	int	c;

	c = 0;
	while (c <= PIXEL)
	{
		i = 0;
		while (i <= PIXEL)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (width + c), (height + i) , color);
			i++;
		}
		c++;
	}
}

int ft_close(void *v)
{
	exit(2);
}

int	ft_key(int tecla, t_mlx *mlx)
{
	if (tecla == ESC)
	{
		ft_printf("Fechando a janela e encerrando o programa...\n");
		exit(0);
	}
	else if (tecla == XK_Right)
	{
		if ((mlx->map[mlx->player_line][mlx->player_col + 1]) == '1')
			return (0);
		mlx->map[mlx->player_line][mlx->player_col + 1] = 'P';
		mlx->map[mlx->player_line][mlx->player_col] = '0';
		draw_map(mlx);
		find_player(mlx);
	}	
	else if (tecla == XK_Up)
	{
		if ((mlx->map[mlx->player_line - 1][mlx->player_col]) == '1')
			return (0);
		mlx->map[mlx->player_line - 1][mlx->player_col] = 'P';
		mlx->map[mlx->player_line][mlx->player_col] = '0';
		draw_map(mlx);
		find_player(mlx);
	}
	else if (tecla == XK_Down)
	{
		if ((mlx->map[mlx->player_line + 1][mlx->player_col]) == '1')
			return (0);
		mlx->map[mlx->player_line + 1][mlx->player_col] = 'P';
		mlx->map[mlx->player_line][mlx->player_col] = '0';
		draw_map(mlx);
		find_player(mlx);
	}
	else if (tecla == XK_Left)
	{
		if ((mlx->map[mlx->player_line][mlx->player_col - 1]) == '1')
			return (0);
		mlx->map[mlx->player_line][mlx->player_col - 1] = 'P';
		mlx->map[mlx->player_line][mlx->player_col] = '0';
		draw_map(mlx);
		find_player(mlx);
	}
	else
		ft_printf("Voce pressionou a tecla: %c\n", tecla);
	return (0);
}

char **read_map(char **argv)
{
	int		fd;
	int		count_line;
	int		i;
	char	*line;
	char	**map;

	fd = open(argv[1], O_RDONLY);
	count_line = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count_line++;
	}
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

// 	if (argc != 2)
// 	{
// 		printf("numero de argumentos invalido\n");
// 		return (1);
// 	}
// 	len = ft_strlen(argv[1]);
// 	if ((ft_strncmp(&argv[1][len - 4], ".ber", 4) != 0))
// 		printf("Error\nInvalid map name!\n");
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Erroooou");
// 		return (2);
// 	}
// }
