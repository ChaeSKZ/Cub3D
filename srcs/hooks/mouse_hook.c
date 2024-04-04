/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:43:43 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/05 00:11:26 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_includes.h"
#include "cub3d_useful_values.h"
#include "hooks.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>

int	mouse_handler(int x, int y, t_cub3D_data *data)
{
	double delta_x;

	(void)y;
	printf("mouse movement captured./n");
	mlx_string_put(data->window.mlx, data->window.address, x, y, 0, " ");
	delta_x = x - (WIDTH / 2);
	data->player.angle += delta_x * ROTATION_SPEED;
	if (data->player.angle >= 2 * M_PI)
		data->player.angle -= 2 * M_PI;
	else if (data->player.angle  < 0)
		data->player.angle += 2 * M_PI;
	return (0);
}

bool	mouse_hook(t_cub3D_data *data)
{
	mlx_hook(data->window.address, 6, 0, mouse_handler, data);
	return (true);
}
