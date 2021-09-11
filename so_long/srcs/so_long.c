/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:17:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/10 20:31:37 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_init_struct(t_main *structs)
{
	structs->ptrs = malloc(sizeof(t_mlx));
	structs->map_data = malloc(sizeof(t_map));
	structs->tiles = malloc(sizeof(t_images));
	structs->link = malloc(sizeof(t_player));
	structs->bubble = malloc(sizeof(t_enemy));
	structs->bubble->state = 1;
	structs->link->state = 1;
	structs->time40 = 0;
	structs->time10 = 0;

}
int	main(int argc, char **argv)
{
	t_main	*structs;
	int	width_win;
	int	height_win;

	structs = malloc(sizeof(t_main));
	sl_init_struct(structs);
	sl_parse_map_main(structs->map_data, argv, argc);
	structs->ptrs->mlx = mlx_init();
	width_win = (structs->map_data->y + 1) * 75;
	height_win = (structs->map_data->x + 1) * 75;
	structs->ptrs->win = mlx_new_window(structs->ptrs->mlx, width_win, height_win, "Link to the so_long");
	sl_put_image_main(structs);
	sl_event_main(structs);
	mlx_loop(structs->ptrs->mlx);
	sl_exit(structs);
	return (0);
}
