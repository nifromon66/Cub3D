# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 19:12:12 by nifromon          #+#    #+#              #
#    Updated: 2025/05/09 19:04:51 by nifromon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Argument
NAME =					../cub3D_bonus

# Compilation
CC =					@cc
CFLAGS =				-Wall -Werror -Wextra
MFLAGS = 				-L $(MLX_DIR)/ -L /usr/include/X11/ \
						-L /usr/lib/x86_64-linux-gnu/ \
						-lmlx -lXext -lX11 -lXrandr -lm -lbsd -lXfixes

INCLUDE =				-I $(HEADER_DIR)/ -I $(LIBFT_DIR)/headers/ -I $(MLX_DIR)/ \
						-I /usr/include/X11/ -I /usr/include/X11/extensions/ \
						-I /usr/lib/x86_64-linux-gnu/

# Directories
SRC_DIR =				src
UTILS_DIR =				utils
HEADER_DIR =			includes

OBJ_DIR =				obj
OBJ_SRC_DIR =			$(OBJ_DIR)/$(SRC_DIR)
OBJ_UTILS_DIR =			$(OBJ_DIR)/$(UTILS_DIR)

MLX_DIR =				../mlx
MLX =					$(MLX_DIR)/libmlx.a

LIBFT_DIR =				../libft
LIBFT =					$(LIBFT_DIR)/libft_inc.a

# Sub_directories
RENDERER_DIR =			$(SRC_DIR)/renderer
PARSER_DIR =			$(SRC_DIR)/parser

# Sub_sub_directories
RENDERER_INIT_DIR = 	$(RENDERER_DIR)/init_manager
RENDERER_INTERACT_DIR = $(RENDERER_DIR)/interaction_manager
RENDERER_PIXEL_DIR = 	$(RENDERER_DIR)/pixel_manager
RENDERER_RAY_DIR = 		$(RENDERER_DIR)/raycasting_manager
RENDERER_GAME_DIR = 	$(RENDERER_DIR)/game_manager
RENDERER_FREE_DIR =		$(RENDERER_DIR)/free_manager

# Utils
RM =					@rm -rf

# Colors
BLACK_ON_GREEN =		\033[30;42m
BLACK_ON_RED =			\033[30;41m
YELLOW =				\033[1;33m
GREEN =					\033[1;32m
RED =					\033[1;31m
RESET =					\033[1;0m

# Sources and Objects
SRC =					\
						$(SRC_DIR)/main.c \
						\
						$(RENDERER_INIT_DIR)/init_game_manager.c \
						$(RENDERER_INIT_DIR)/init_graphics_manager.c \
						$(RENDERER_INIT_DIR)/init_mapping_manager.c \
						$(RENDERER_PIXEL_DIR)/pixel_manager.c \
						$(RENDERER_PIXEL_DIR)/pixel_line_manager.c \
						$(RENDERER_PIXEL_DIR)/pixel_circle_manager.c \
						$(RENDERER_RAY_DIR)/raycasting_manager.c \
						$(RENDERER_RAY_DIR)/raycasting_draw_manager.c \
						$(RENDERER_RAY_DIR)/raycasting_joists_manager.c \
						$(RENDERER_RAY_DIR)/raycasting_vertical_manager.c \
						$(RENDERER_RAY_DIR)/raycasting_horizontal_manager.c \
						$(RENDERER_RAY_DIR)/raycasting_floors_manager.c \
						$(RENDERER_RAY_DIR)/raycasting_ceilings_manager.c \
						$(RENDERER_RAY_DIR)/raycasting_walls_manager.c \
						$(RENDERER_GAME_DIR)/game_manager.c \
						$(RENDERER_GAME_DIR)/game_foe_manager.c \
						$(RENDERER_GAME_DIR)/game_fullscreens_manager.c \
						$(RENDERER_GAME_DIR)/game_minimap_manager.c \
						$(RENDERER_GAME_DIR)/game_sprites_manager.c \
						$(RENDERER_GAME_DIR)/game_sky_manager.c \
						$(RENDERER_GAME_DIR)/game_weapons_manager.c \
						$(RENDERER_INTERACT_DIR)/interaction_manager.c \
						$(RENDERER_INTERACT_DIR)/mouse_manager.c \
						$(RENDERER_INTERACT_DIR)/key_manager.c \
						$(RENDERER_INTERACT_DIR)/automatics_manager.c \
						$(RENDERER_INTERACT_DIR)/movement_manager.c \
						$(RENDERER_INTERACT_DIR)/rotation_manager.c \
						$(RENDERER_INTERACT_DIR)/action_manager.c \
						$(RENDERER_FREE_DIR)/free_manager.c \
						\
						$(PARSER_DIR)/check_cub.c \
						$(PARSER_DIR)/check_map.c \
						$(PARSER_DIR)/file_manager.c \
						$(PARSER_DIR)/fix_args.c

OBJ_SRC =				$(SRC:$(SRC_DIR)/%.c=$(OBJ_SRC_DIR)/%.o)

UTILS =					\
						$(UTILS_DIR)/time_manager.c \
						$(UTILS_DIR)/calculation_manager.c \
						\
						$(UTILS_DIR)/map_manager.c \
						$(UTILS_DIR)/map_manager2.c \
						$(UTILS_DIR)/lib_ext.c \
						$(UTILS_DIR)/str_utils.c

OBJ_UTILS =				$(UTILS:$(UTILS_DIR)/%.c=$(OBJ_UTILS_DIR)/%.o)

# Rules and dependencies
all:					$(LIBFT) $(MLX) $(NAME)

$(LIBFT):
						@make -s -C $(LIBFT_DIR) all

$(MLX):
						@echo "$(YELLOW)Building $(MLX)...$(RESET)"
						@make -s -C $(MLX_DIR) all >/dev/null 2>&1
						@echo "$(BLACK_ON_GREEN)\t\t\t\t\t*/ $(MLX) \*$(RESET)"

$(NAME):				$(LIBFT) $(MLX) $(OBJ_SRC) $(OBJ_UTILS)
						@echo "$(YELLOW)Building $(NAME)...$(RESET)"
						$(CC) $(OBJ_SRC) $(OBJ_UTILS) $(LIBFT) $(MLX) $(CFLAGS) $(MFLAGS) $(INCLUDE) -o $(NAME)
						@echo "$(BLACK_ON_GREEN)\t\t\t\t\t*/ $(NAME) \*$(RESET)"

$(OBJ_SRC_DIR)/%.o: $(SRC_DIR)/%.c
						@mkdir -p $(OBJ_DIR)
						@mkdir -p $(OBJ_SRC_DIR)
						@mkdir -p $(OBJ_SRC_DIR)/parser/
						@mkdir -p $(OBJ_SRC_DIR)/renderer/
						@mkdir -p $(OBJ_SRC_DIR)/renderer/init_manager/
						@mkdir -p $(OBJ_SRC_DIR)/renderer/game_manager/
						@mkdir -p $(OBJ_SRC_DIR)/renderer/interaction_manager/
						@mkdir -p $(OBJ_SRC_DIR)/renderer/pixel_manager/
						@mkdir -p $(OBJ_SRC_DIR)/renderer/raycasting_manager/
						@mkdir -p $(OBJ_SRC_DIR)/renderer/free_manager/
						$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
						@mkdir -p $(OBJ_DIR)
						@mkdir -p $(OBJ_UTILS_DIR)
						$(CC) -c $(CFLAGS) $< -o $@

clean:
						@make -s -C $(LIBFT_DIR) clean
						@echo "$(YELLOW)Cleaning $(MLX_DIR)...$(RESET)"
						@make -s -C $(MLX_DIR) clean >/dev/null 2>&1
						@echo "$(RED)Cleaned $(MLX_DIR)$(RESET)"
						@echo "$(YELLOW)Cleaning $(OBJ_DIR)...$(RESET)"
						$(RM) $(OBJ_DIR)
						@echo "$(RED)Cleaned $(OBJ_DIR)$(RESET)"

fclean:
						@make -s -C $(LIBFT_DIR) fclean
						@make -s -C $(LIBFT_DIR) clean >/dev/null 2>&1
						@echo "$(YELLOW)Cleaning $(MLX_DIR)...$(RESET)"
						@make -s -C $(MLX_DIR) clean >/dev/null 2>&1
						@echo "$(RED)Cleaned $(MLX_DIR)$(RESET)"
						@echo "$(YELLOW)Forcefully cleaning $(MLX)...$(RESET)"
						@echo "$(BLACK_ON_RED)\t\t\t\t\t*/ $(MLX) \*$(RESET)"
						@echo "$(YELLOW)Cleaning $(OBJ_DIR)...$(RESET)"
						$(RM) $(OBJ_DIR)
						@echo "$(RED)Cleaned $(OBJ_DIR)$(RESET)"
						@echo "$(YELLOW)Forcefully cleaning $(NAME)...$(RESET)"
						$(RM) $(NAME)
						@echo "$(BLACK_ON_RED)\t\t\t\t\t*/ $(NAME) \*$(RESET)"

re:						fclean all

.PHONY:					all clean fclean re