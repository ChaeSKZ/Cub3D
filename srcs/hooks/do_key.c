/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:20:32 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/06 13:44:38 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keycode.h"
#include "hooks.h"

void	init_keys(t_keys *keys)
{
	keys->w = false;
	keys->s = false;
	keys->a = false;
	keys->d = false;
	keys->arrow_left = false;
	keys->arrow_right = false;
	keys->tab = true;
	keys->shift = false;
	keys->r = false;
}

void	do_key_press(t_cub3D_data *data, int keycode)
{
	if (keycode == ALT_KEY_CODE)
		do_alt_key(data);
	if (keycode == W_KEY_CODE)
		data->key.w = true;
	if (keycode == S_KEY_CODE)
		data->key.s = true;
	if (keycode == A_KEY_CODE)
		data->key.a = true;
	if (keycode == D_KEY_CODE)
		data->key.d = true;
	if (keycode == ARROW_LEFT_CODE)
		data->key.arrow_left = true;
	if (keycode == ARROW_RIGHT_CODE)
		data->key.arrow_right = true;
	if (keycode == TAB_CODE)
		data->key.tab = !data->key.tab;
	if (keycode == SHIFT_CODE)
		data->key.shift = true;
	if (keycode == R_KEY_CODE)
		data->key.r = true;
}

void	do_key_release(t_cub3D_data *data, int keycode)
{
	if (keycode == W_KEY_CODE)
		data->key.w = false;
	if (keycode == S_KEY_CODE)
		data->key.s = false;
	if (keycode == A_KEY_CODE)
		data->key.a = false;
	if (keycode == D_KEY_CODE)
		data->key.d = false;
	if (keycode == ARROW_LEFT_CODE)
		data->key.arrow_left = false;
	if (keycode == ARROW_RIGHT_CODE)
		data->key.arrow_right = false;
	if (keycode == SHIFT_CODE)
		data->key.shift = false;
	if (keycode == R_KEY_CODE)
		data->key.r = false;
}
