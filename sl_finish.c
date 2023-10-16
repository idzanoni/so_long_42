/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:43:23 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/15 19:52:43 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_mlx *mlx)
{
	if (mlx->mlx_ptr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->bluey_d);
		mlx_destroy_image(mlx->mlx_ptr, mlx->bluey_l);
		mlx_destroy_image(mlx->mlx_ptr, mlx->bluey_r);
		mlx_destroy_image(mlx->mlx_ptr, mlx->bluey_u);
		mlx_destroy_image(mlx->mlx_ptr, mlx->exit_c);
		mlx_destroy_image(mlx->mlx_ptr, mlx->exit_o);
		mlx_destroy_image(mlx->mlx_ptr, mlx->tile);
		mlx_destroy_image(mlx->mlx_ptr, mlx->wall);
		mlx_destroy_image(mlx->mlx_ptr, mlx->cactus);
		mlx_destroy_image(mlx->mlx_ptr, mlx->balloon);
		mlx_destroy_image(mlx->mlx_ptr, mlx->win);
		mlx_destroy_window (mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
	}
	ft_free_matrix(mlx->map);
	free(mlx->mlx_ptr);
	exit (0);
	return (0);
}

void	ft_free_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free (matrix[i]);
		i++;
	}
	free(matrix);
}
