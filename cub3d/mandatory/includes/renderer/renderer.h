/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:08 by yseguin           #+#    #+#             */
/*   Updated: 2025/05/10 00:52:37 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "renderer_typedef.h"
# include "renderer_define.h"
# include "../cub.h"

// Functions
		// init_manager
	// init_game_manager.c
void	cub_init_game_manager(t_game *game, t_cubval *cubval);
void	cub_init_game_values(t_game *game, t_cubval *cubval);
void	cub_init_game_zero(t_game *game, t_cubval *cubval);
void	cub_print_map(t_map *map);
	// init_graphics_manager.c
void	cub_init_graphics_manager(t_game *game, t_cubval *cubval);
int		*cub_create_textures(const char *file, int size);
int		*cub_join_textures(int **textures, int size, int nbr);
t_rgb	cub_init_colors(char *source);
	// init_mapping_manager.c
void	cub_init_minimap(t_minimap *minimap);
t_map	cub_init_map(char *source, t_point max, t_player *player,
			t_sprite **sprite);
void	cub_init_player_position(int pos, int width, char orientation,
			t_player *player);
void	cub_init_sprites(int pos, int width, int type, t_sprite **sprite);
		// game_manager
	// game_manager.c
int		cub_game_manager(t_game *game);
void	cub_game_running(t_game *game);
void	cub_game_fps(t_fps *fps);
	// game_fullscreens_manager.c
void	cub_render_fullscreens(t_game *game, t_screen *screen, int status);
void	cub_render_fullscreens_loop(t_img_data *img, t_screen *screen);
	// game_minimap_manager.c
void	cub_render_minimap_player(t_game *game, t_pos center, int radius,
			int color);
void	cub_render_minimap(t_game *game, t_map *map, t_minimap *minimap,
			int color);
void	cub_render_minimap_loop(t_game *game, t_minimap *minimap, t_map *map,
			int color);
void	cub_render_setup_minimap(t_game *game, t_minimap *minimap, t_map *map);
	// game_sky_manager.c
void	cub_render_sky(t_img_data *img, t_sky *sky, t_player *player);
void	cub_render_sky_layers(t_img_data *img, t_sky *sky, t_pos pos);
	// game_sprites_manager.c
void	cub_sprites_manager(t_game *game, t_sprite **sprite, t_player *player);
void	cub_update_sprites(t_game *game, t_sprite *sprite, t_player *player);
void	cub_setup_sprites(t_sprite *sprite, t_player *player);
void	cub_render_sprites(t_game *game, t_sprite *sprite);
void	cub_render_sprites_loop(t_game *game, t_sprite *sprite);
	// game_foe_manager.c
void	cub_foe_setup_pursuit(t_sprite *sprite, t_point *pos,
			t_point *offset_add, t_point *offset_sub);
void	cub_foe_setup_animations(t_sprite *sprite);
void	cub_foe_perform_pursuit(t_game *game, t_sprite *sprite,
			t_player *player);
void	cub_foe_pursuit(t_game *game, t_sprite *sprite, t_player *player);
	// game_weapons_manager.c
void	cub_weapons_manager(t_game *game, t_weapons *glock);
void	cub_render_weapons(t_game *game, t_weapons *glock);
void	cub_setup_weapons(t_game *game, t_weapons *glock);
void	cub_fire(t_game *game, t_weapons *glock, t_sprite **sprites);
		// raycasting_manager
	// raycasting_manager.c
void	cub_raycasting_manager(t_game *game, t_rays *rays, t_player *player);
	// raycasting_horizontal_manager.c
void	cub_rays_cast_horizontal(t_rays *rays, t_player *player);
void	cub_rays_detect_horizontal(t_rays *rays, t_player *player,
			t_distance *dist, t_map *map);
void	cub_rays_setup_draw_h(t_game *game, t_rays *rays);
	// raycasting_vertical_manager.c
void	cub_rays_cast_vertical(t_rays *rays, t_player *player);
void	cub_rays_detect_vertical(t_rays *rays, t_player *player,
			t_distance *dist, t_map *map);
void	cub_rays_setup_draw_v(t_game *game, t_rays *rays);
	// raycasting_walls_manager.c
void	cub_rays_draw_walls(t_img_data *img, t_rays *rays, t_walls *walls,
			int *texture);
	// raycasting_joists_manager.c
void	cub_rays_draw_joists(t_game *game, t_rays *rays, t_joists *joists);
void	cub_rays_setup_joists(t_rays *rays, t_player *player, t_joists *joists);
	// raycasting_floors_manager.c
void	cub_rays_draw_floors_rgb(t_img_data *img, t_rays *rays, t_rgb color);
void	cub_rays_draw_floors_tex(t_game *game, t_rays *rays, t_joists *joists,
			int *texture);
	// raycasting_ceilings_manager.c
void	cub_rays_draw_ceilings_rgb(t_img_data *img, t_rays *rays, t_rgb color);
void	cub_rays_draw_ceilings_tex(t_game *game, t_rays *rays, t_joists *joists,
			int *texture);
	// raycasting_draw_manager.c
void	cub_rays_setup_draw(t_game *game, t_rays *rays, t_player *player);
void	cub_rays_draw(t_game *game, t_rays *rays);
void	cub_rays_draw_h(t_game *game, t_rays *rays);
void	cub_rays_draw_v(t_game *game, t_rays *rays);
		// pixel_manager
	// pixel_manager.c
void	cub_draw_pixel(t_img_data *img, int x, int y, int color);
void	cub_draw_point(t_img_data *img, t_pos pos, int size, int color);
void	cub_draw_empty_square(t_img_data *img, t_pos pos, int size, int color);
void	cub_draw_filled_square(t_img_data *img, t_pos pos, int size, int color);
	// pixel_line_manager.c
void	cub_draw_line(t_img_data *img, t_pos start, t_pos end, int color);
void	cub_draw_thick_line(t_img_data *img, t_segment *segment, int size,
			int color);
	// pixel_circle_manager.c
void	cub_draw_empty_circle(t_img_data *img, t_pos center, int radius,
			int color);
		// interaction_manager
	// interaction_manager.c
void	cub_interaction_manager(t_game *game);
void	cub_movement_update(t_keys *keys, t_player *player, t_map *map);
	// key_manager.c
int		cub_handle_key_press(int key, t_game *game);
int		cub_handle_key_release(int key, t_game *game);
	// mouse_manager.c
int		cub_handle_cross(t_game *game);
int		cub_handle_mouse(int x, int y, t_game *game);
int		cub_handle_mouse_clicking(int button, int x, int y, t_game *game);
	// automatics_manager.c
void	cub_automatics_close_door(t_game *game, t_map *map, t_map *minimap);
int		cub_automatics_close_door_loop(t_game *game, t_map *map, t_map *minimap,
			t_point *pos_map);
int		cub_automatics_detect_player(t_player *player, t_map *map,
			t_point *pos_map);
int		cub_automatics_detect_foe(t_sprite *sprite, t_map *map,
			t_point *pos_map);
	// action_manager.c
void	cub_action_manager(int action, t_player *player, t_map *map);
void	cub_action_open_door(t_player *player, t_map *map);
	// movement_manager.c
void	cub_movement_manager(t_player *player, int move, float speed,
			t_map *map);
void	cub_move_forward(t_player *player, float speed, t_map *map);
void	cub_move_backward(t_player *player, float speed, t_map *map);
void	cub_move_left(t_player *player, float speed, t_map *map);
void	cub_move_right(t_player *player, float speed, t_map *map);
	// rotation_manager.c
void	cub_rotate_manager(t_player *player, int move, float speed);
void	cub_rotate_right(t_player *player, float speed);
void	cub_rotate_left(t_player *player, float speed);
		// free_manager
	// free_manager.c
void	cub_free_manager(t_game *game);
void	cub_free_graphics(t_game *game);
void	cub_free_sprites(t_sprite **sprites, int nbr_sprites);
		// utils
	// time_manager.c
int		cub_get_time_ms(void);
	// calculation_manager.c
float	cub_degtorad(float degree);
float	cub_fixang(float angle);
float	cub_calc_dist(t_pos a, t_pos b, float angle);
int		cub_convert_glrgb(float red, float green, float blue, int mode);
int		cub_is_transparent(float red, float green, float blue);

#endif