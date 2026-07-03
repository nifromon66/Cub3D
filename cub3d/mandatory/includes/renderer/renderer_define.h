/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_define.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:09:41 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/09 17:06:40 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_DEFINE_H
# define RENDERER_DEFINE_H

// Macros
	// MATH DATA
# ifndef M_PI
#  define M_PI					3.14159265358979323846
# endif
# define DR						0.01745329 // one degree to radian
# define FOV					960
	// Minimap
# define MINI_BLOCK				12
# define MINI_PLAYER			6
# define MINI_RADIUS			100

# define SCALING				640

# define RAYS_STARTING_ANGLE	30
# define RAYS_SPACING			0.0625

# define SPEED					0.125
	// WINDOW DATA
# define SCREEN_WIDTH			960
# define SCREEN_HEIGHT			640

// Printf Colors
# define BLACK					"\033[0;30m"
# define RED					"\033[0;31m"
# define GREEN					"\033[0;32m"
# define YELLOW					"\033[0;33m"
# define BLUE					"\033[0;34m"
# define PURPLE					"\033[0;35m"
# define CYAN					"\033[0;36m"
# define WHITE					"\033[0;37m"
# define RESET					"\033[0;0m"

// Keycodes
# define KEY_ESC				65307
# define KEY_W					119
// # define KEY_W					122
# define KEY_ARROW_LEFT			65361
# define KEY_S					115
# define KEY_ARROW_RIGHT		65363
# define KEY_E					101
# define KEY_A					97
// # define KEY_A					113
# define KEY_D					100

// Textures
# define TEX_SIZE				3072 // 32 * 32 * 3
	// DOORS
# define DOOR					"./textures/Doors/Door.ppm"
	// LEAVE
# define LEAVE					"./textures/Leave/Leave_1.ppm"
# define LEAVE_WALL				"./textures/Leave/Leave_wall.ppm"
	// SKY
# define SKY					"./textures/Sky/Sky.ppm"
# define SKY_MOON				"./textures/Sky/Sky_Moon.ppm"
# define SKY_CLOUDS				"./textures/Sky/Sky_Clouds.ppm"
# define SKY_BACKGROUND			"./textures/Sky/Sky_Background.ppm"
	// SKY MATH
# define SKY_LAYERS				3
# define SKY_WIDTH				576
# define SKY_HEIGHT				324
# define SKY_SIZE				559872 // 576 * 324 * 3
# define SKY_OFFSET				2 // offset
# define SKY_OFFSET_PLUS		1 // offset / 2
# define SKY_OFFSET_SCREEN		8 // offset screen 4 * offset
	// SCREENS
# define SCREEN_START			"./textures/Screens/Start.ppm"
# define SCREEN_LOSE			"./textures/Screens/Lose.ppm"
# define SCREEN_WIN				"./textures/Screens/Win.ppm"
# define SCREEN_TEX_WIDTH		576
# define SCREEN_TEX_HEIGHT		324
# define SCREEN_TEX_SIZE		559872 // 576 * 324 * 3
	// FOE
# define FOE_SPEED				0.05
# define CLOWN_RUN				"./textures/Foe/Clown_run.ppm"
	// COLLECTIBLES
# define KEY					"./textures/Collect/Key.ppm"
	// WEAPONS
# define GLOCK					"./textures/Weapons/Glock.ppm"
# define WEAPON_SIZE			49152 // 128 * 128 * 3

#endif