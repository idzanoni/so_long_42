/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:41:45 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/02 12:11:19 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/keysym.h>
# include "libs/get_next_line/get_next_line.h"
# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"

# define MAP_CHARS "01CEP"
# define PIXEL 64
# define ESC 65307

# define BLUEY_D "textures/bluey_down.xpm"
# define BLUEY_U "textures/bluey_up.xpm"
# define BLUEY_L "textures/bluey_left.xpm"
# define BLUEY_R "textures/bluey_right.xpm"
# define EXIT_C "textures/exit_close.xpm"
# define EXIT_O "textures/exit_open.xpm"
# define TILE "textures/tile.xpm"
# define WALL "textures/wall.xpm"
# define CACTUS "textures/cactus.xpm"
# define BALLOON "textures/balloon.xpm"
# define WIN "textures/win.xpm"

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			width;
	int			height;
	void		*player;
	int			stars;
	int			movements;
	int			col;
	int			line;
	int			player_line;
	int			player_col;
}			t_mlx;

typedef struct s_map
{
	char	*file;
	int		fd;
	char	**map;
	int		size;
	int		player;
	int		exit;
	int		coin;
	int		coin_count;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		path_check;
	int		check_format;
}			t_map;

typedef struct s_sprite
{
	void	*bluey_d;
	void	*bluey_l;
	void	*bluey_r;
	void	*bluey_u;
	void	*exit_c;
	void	*exit_o;
	void	*tile;
	void	*wall;
	void	*cactus;
	void	*balloon;
	void	*win;
}			t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			img_width;
	int			img_height;
	int			moves;
	t_sprite	*spt;
	t_map		*map;
}			t_game;

#endif
