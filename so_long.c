/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:36:20 by izanoni           #+#    #+#             */
/*   Updated: 2023/09/20 20:50:15 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char 	**read_map(char **argv);
int		ft_close(void *v);
int		ft_key(int tecla, void *k);
void	ft_put_pix(t_mlx *mlx, int width, int height);

int	main(int argc, char **argv)
{
	t_mlx 	mlx;
	int		width;
	int		height;
	
	read_map(argv);
	
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 600, 300, "janelinha");
	height = 0;
	while (height <= 300)
	{
		width = height % 100;
		// width = 0;
		// if (height %100 == 50)
		// 	width = 50;
		while(width <= 600)
		{
			ft_put_pix (&mlx, width, height);
			width = width + 100;
		}
		height = height + 50;
	}
	// height = 50;
	// while (height <= 300)
	// {
	// 	width = 50;
	// 	while(width <= 600)
	// 	{
	// 		ft_put_pix (&mlx, width, height);
	// 		width = width + 100;
	// 	}
	// 	height = height + 100;
	// }
	
	mlx_hook(mlx.win_ptr, 17, (1L<<17), ft_close, NULL);
	mlx_hook(mlx.win_ptr, 2, (1L<<0), ft_key, NULL);
	mlx_loop(mlx.mlx_ptr);
}

void	ft_put_pix(t_mlx *mlx, int width, int height)
{
	int i;
	int c;
	
	c = 0;
	while (c <= 50)
	{
		i = 0;
		while (i <= 50)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (width + c), (height + i) , 0xaaFF0000);
			// mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (width + 100), (height + i) , 0xaaFF0000);
			// mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (width + i), height , 0xaaFF0000);
			// mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (width + i), (height + 100) , 0xaaFF0000);
			i++;
		}
		c++;
	}
	
}

int ft_close(void *v)
{
	exit(2);
}

int	ft_key(int tecla, void *k)
{
	if (tecla == ESC)
	{
		printf("Fechando a janela e encerrando o programa...\n");
		exit(0);
	}
	else
		printf("Voce pressionou a tecla: %c\n", tecla);
	return (0);
}
char ** read_map(char **argv)
{
	int fd;
	int count_line;
	int i;
	char *line;
	char **map;
	
	fd = open(argv[1], O_RDONLY);
	count_line = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
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
			break;
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	while (map[0] != NULL)
	{
		printf("%s", map[0]);
		map++;
	}
	return (0);
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
