/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:00:19 by anremiki          #+#    #+#             */
/*   Updated: 2022/05/15 20:57:14 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	horizontal_slide(char **exp, float x, float y, t_player *player)
{
	int	xo;
	int	yo;

	xo = 20;
	yo = 20;
	if (player->dx < 0)
		xo = -20;
	if (player->dy < 0)
		yo = -20;
	if (!check_valid(exp[(int)player->y][(int)player->x + xo], HITBOX))
		player->x = x;
	if (!check_valid(exp[(int)player->y + yo][(int)player->x + xo], HITBOX))
		player->y = y;
}

void	vertical_slide(char **exp, float x, float y, t_player *player)
{
	int	xo;
	int	yo;

	xo = 20;
	yo = 20;
	if (player->dx < 0)
		xo = -20;
	if (player->dy < 0)
		yo = -20;
	if (!check_valid(exp[(int)player->y + yo][(int)player->x], HITBOX))
		player->y = y;
	if (!check_valid(exp[(int)player->y + yo][(int)player->x + xo], HITBOX))
		player->x = x;
}

void	update_x_y(t_player *player, float x, float y, int check)
{
	if (check)
	{
		player->x = x;
		player->y = y;
	}
}

void	cross_doors(t_cub *cub, float x, float y, t_player *player)
{
	int	check;

	check = 0;
	if (cub->degree == 1)
	{
		if (((int)y % 64) - (int)cub->door < 0)
				check = 1;
	}
	else if (cub->degree == 2)
	{
		if ((64 - (int)x % 64) - (int)cub->door < 0)
				check = 1;
	}
	else if (cub->degree == 3)
	{
		if ((64 - (int)y % 64) - (int)cub->door < 0)
				check = 1;
	}
	else if (cub->degree == 4)
	{
		if (((int)x % 64) - (int)cub->door < 0) 
			check = 1;
	}
	update_x_y(player, x, y, check);
}

void	slide(t_cub *cub, float x, float y, char **exp)
{
	t_player	*player;
	float		ox;
	float		oy;

	player = cub->player;
	ox = player->x;
	oy = player->y;
	cub->degree = quadrant_direction(player->angle);
	horizontal_slide(exp, x, y, player);
	if (exp[(int)y][(int)x] == 'D')
		cross_doors(cub, x, y, player);
	if (player->x == ox && player->y == oy)
		vertical_slide(exp, x, y, player);
}
