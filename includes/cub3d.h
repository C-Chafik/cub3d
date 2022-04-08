/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:35:18 by anremiki          #+#    #+#             */
/*   Updated: 2022/04/08 02:35:06 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "/usr/include/X11/X.h"
# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
//# include "struct3d.h"

# define PI 3.1415926535
# define NVALUE 0.017452925
# define RAD 0.017452925

enum	e_fd
{
	STDIN,
	STDOUT,
	STDERR,
	GATHER
};

typedef struct s_parse
{
	char	**map;
	char	**data;
	char	*tmpdata;
	char	*total;
	char	*line;
	int		fd;
	int		arg;
	int		checker;
	int		map_start;
	int		x;
}				t_parse;

typedef struct s_text
{
	void	*texture;
	void	*addr;
	int		bpp;
	int		size;
	int		end;
	int		a;
	int		b;
}				t_text;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*imap;
	char	*addr;
	char	**map;
	char	**pixmap;
	int		color;
	int		bpp;
	int		bbpp;
	int		size_line;
	int		bsize_line;
	int		endian;
	int		bendian;
	void	*iplayer;
	void	*texture;
	char	*textaddr;
	char	**rtext;
	int		i;
	int		j;
	int		bg_r;
	int		bg_g;
	int		bg_b;
	int		mx;
	int		my;
	float	px;
	float	pdx;
	float	py;
	float	pdy;
	double	pa;
	double	pz;
	int		released;
	int		last_pressed;
	int		press_start;
	double	sprint;
	int		end;
	float	lx;
	float	la;
	float	ly;
	float	lz;
	float	pi2;
	float	dpi;
	float	pi3;
	t_text	*text;
	//t_ray	*ray;

}			t_mlx;

/*	Parsing data	*/

/*int		init_data(char **av, t_cub *cub);
int		gather_data(char *av, t_parse *data, int fd, t_cub *cub);
int		split_data(t_parse *data, t_cub *cub);*/
int		check_valid(char c, char *sep);
int		check_comma(char *line);
int		check_rgb(char *line);
int		check_path(char *line, int arg);
int		parse_line(char *line, int arg);
char	*ft_strndup(char *str, int limit);
char	*skip_line(char *line);
char	**parse_data(char **av);
char	**parse_map(char **map);
#endif
