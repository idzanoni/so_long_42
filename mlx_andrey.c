/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:34:11 by izanoni           #+#    #+#             */
/*   Updated: 2023/09/20 18:36:24 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>	
#include <mlx.h>

#define ESC 65307

typedef struct struct_ponteiros {
	void	*mlx;
	void	*janela;
}	tipo_ponteiros;

int	checa_teclas(int tecla, tipo_ponteiros *ponteiros) {
	if (tecla == ESC) {
		printf("Fechando a janela e encerrando o programa...\n");
		mlx_destroy_window(ponteiros->mlx, ponteiros->janela);
		mlx_destroy_display(ponteiros->mlx);
		free(ponteiros->mlx);
		exit(0);
	}
	else
		printf("Voce pressionou a tecla: %c\n", tecla);
	return (0);
}

int main()
{
	tipo_ponteiros	*ponteiros;
	void			*ponteiro_da_mlx;
	void			*ponteiro_da_janela;

	ponteiros = malloc (1 * sizeof (tipo_ponteiros));

	ponteiros.mlx = mlx_init();

	ponteiro_da_janela = mlx_new_window(ponteiro_da_mlx, 200, 200, "Janela");

	ponteiros.mlx = ponteiro_da_mlx;
	ponteiros.janela = ponteiro_da_janela;

	mlx_key_hook(ponteiros.janela, checa_teclas, &ponteiros);
	mlx_loop(ponteiro_da_mlx);
}