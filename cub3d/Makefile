# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 19:12:12 by nifromon          #+#    #+#              #
#    Updated: 2025/05/06 13:31:12 by yseguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
MANDATORY =				mandatory
BONUS =					bonus

all:
						@make -s -C $(MANDATORY) all

bonus:
						@make -s -C $(BONUS) all

clean:
						@make -s -C $(MANDATORY) clean

clean_bonus:
						@make -s -C $(BONUS) clean

fclean:
						@make -s -C $(MANDATORY) fclean

fclean_bonus:
						@make -s -C $(BONUS) fclean

re:						fclean all

re_bonus:				fclean_bonus bonus


.PHONY:					all bonus \
						clean clean_bonus \
						fclean fclean_bonus \
						re re_bonus