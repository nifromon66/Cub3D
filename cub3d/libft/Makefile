# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 05:37:45 by nifromon          #+#    #+#              #
#    Updated: 2025/04/29 19:32:16 by nifromon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME_ALL =			libft_inc.a
NAME_LIBFT =		libft.a
NAME_FT_PRINTF =	ft_printf.a
NAME_GNL =			get_next_line.a

# Arguments
CC = 				@gcc
CFLAGS = 			-Wall -Wextra -Werror

# Repositories
# Sources
SRCS_DIR =			src
LIBFT_SRC =			$(SRCS_DIR)/libft_SRC
FT_PRINTF_SRC = 	$(SRCS_DIR)/ft_printf_SRC
GNL_SRC =			$(SRCS_DIR)/get_next_line_SRC

# Headers
HEADERS_DIR =		headers
LIBFT_H =			$(HEADERS_DIR)/libft_H/
FT_PRINTF_H =		$(HEADERS_DIR)/ft_printf_H/
GNL_H =				$(HEADERS_DIR)/get_next_line_H/
OBJS_DIR =			obj

# Utils
AR =				@ar -rcs
RM =				@rm -rf

# Colors
BLACK_ON_GREEN =	\033[30;42m
BLACK_ON_RED =		\033[30;41m
YELLOW =			\033[1;33m
GREEN =				\033[1;32m
RED =				\033[1;31m
RESET =				\033[1;0m

# Sources and Objects
LIBFT_SRCS = 		\
					$(LIBFT_SRC)/ft_isalpha.c $(LIBFT_SRC)/ft_isdigit.c \
					$(LIBFT_SRC)/ft_isalnum.c $(LIBFT_SRC)/ft_isascii.c \
					$(LIBFT_SRC)/ft_isprint.c $(LIBFT_SRC)/ft_strlen.c \
					$(LIBFT_SRC)/ft_memset.c $(LIBFT_SRC)/ft_bzero.c \
					$(LIBFT_SRC)/ft_memcpy.c $(LIBFT_SRC)/ft_memmove.c \
					$(LIBFT_SRC)/ft_strlcpy.c $(LIBFT_SRC)/ft_strlcat.c \
					$(LIBFT_SRC)/ft_toupper.c $(LIBFT_SRC)/ft_tolower.c \
					$(LIBFT_SRC)/ft_strchr.c $(LIBFT_SRC)/ft_strrchr.c \
					$(LIBFT_SRC)/ft_strncmp.c $(LIBFT_SRC)/ft_memchr.c \
					$(LIBFT_SRC)/ft_memcmp.c $(LIBFT_SRC)/ft_strnstr.c \
					$(LIBFT_SRC)/ft_atoi.c $(LIBFT_SRC)/ft_calloc.c \
					$(LIBFT_SRC)/ft_strdup.c $(LIBFT_SRC)/ft_substr.c \
					$(LIBFT_SRC)/ft_strjoin.c $(LIBFT_SRC)/ft_strtrim.c \
					$(LIBFT_SRC)/ft_split.c $(LIBFT_SRC)/ft_itoa.c \
					$(LIBFT_SRC)/ft_strmapi.c $(LIBFT_SRC)/ft_striteri.c \
					$(LIBFT_SRC)/ft_putchar_fd.c $(LIBFT_SRC)/ft_putstr_fd.c \
					$(LIBFT_SRC)/ft_putendl_fd.c $(LIBFT_SRC)/ft_putnbr_fd.c \
					$(LIBFT_SRC)/ft_lstnew.c $(LIBFT_SRC)/ft_lstadd_front.c \
					$(LIBFT_SRC)/ft_lstsize.c $(LIBFT_SRC)/ft_lstlast.c \
					$(LIBFT_SRC)/ft_lstadd_back.c $(LIBFT_SRC)/ft_lstdelone.c \
					$(LIBFT_SRC)/ft_lstclear.c $(LIBFT_SRC)/ft_lstiter.c \
					$(LIBFT_SRC)/ft_lstmap.c $(LIBFT_SRC)/ft_ptrlen.c \
					$(LIBFT_SRC)/ft_ulltoa.c $(LIBFT_SRC)/ft_strcmp.c

LIBFT_OBJS = 		$(LIBFT_SRCS:$(LIBFT_SRC)/%.c=$(OBJS_DIR)/$(LIBFT_SRC)/%.o)

FT_PRINTF_SRCS =	\
					$(FT_PRINTF_SRC)/ft_printf.c $(FT_PRINTF_SRC)/ftpf_init.c \
					$(FT_PRINTF_SRC)/ftpf_format_c.c $(FT_PRINTF_SRC)/ftpf_check.c \
					$(FT_PRINTF_SRC)/ftpf_format_d.c \
					$(FT_PRINTF_SRC)/ftpf_format_i.c \
					$(FT_PRINTF_SRC)/ftpf_format_p.c \
					$(FT_PRINTF_SRC)/ftpf_format_s.c \
					$(FT_PRINTF_SRC)/ftpf_format_u.c \
					$(FT_PRINTF_SRC)/ftpf_format_x_low.c \
					$(FT_PRINTF_SRC)/ftpf_format_x_upp.c

FT_PRINTF_OBJS = 	$(FT_PRINTF_SRCS:$(FT_PRINTF_SRC)/%.c=$(OBJS_DIR)/$(FT_PRINTF_SRC)/%.o)

GNL_SRCS =			\
					$(GNL_SRC)/get_next_line.c \
					$(GNL_SRC)/get_next_line_utils.c

GNL_OBJS = 			$(GNL_SRCS:$(GNL_SRC)/%.c=$(OBJS_DIR)/$(GNL_SRC)/%.o)

# Rules and Dependencies
all: 				$(NAME_ALL) print_end_all

print_start_all:
					@echo "$(YELLOW)Building $(NAME_ALL)...$(RESET)"

print_end_all:
					@echo "$(BLACK_ON_GREEN)\t\t\t\t\t*/ $(NAME_ALL) \*$(RESET)"

$(NAME_ALL):		print_start_all  $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)
					$(AR) $(NAME_ALL) $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)

libft:				$(NAME_LIBFT) print_end_libft

print_start_libft:
					@echo "$(YELLOW)Building $(NAME_LIBFT)...$(RESET)"

print_end_libft:
					@echo "$(BLACK_ON_GREEN)\t\t\t\t\t*/ $(NAME_LIBFT) \*$(RESET)"

$(NAME_LIBFT):		print_start_libft $(LIBFT_OBJS)
					$(AR) $(NAME_LIBFT) $(LIBFT_OBJS)

$(OBJS_DIR)/$(LIBFT_SRC)/%.o: $(LIBFT_SRC)/%.c
					@mkdir -p $(dir $@)
					$(CC) -c $(CFLAGS) -I $(LIBFT_H) $< -o $@

clean_libft:
					@echo "$(YELLOW)Cleaning $(NAME_LIBFT)...$(RESET)"
					$(RM) $(OBJS_DIR)/$(LIBFT_SRC)
					@echo "$(RED)Cleaned $(NAME_LIBFT)$(RESET)"

fclean_libft: 		clean_libft
					@echo "$(YELLOW)Forcefully cleaning $(NAME_LIBFT)...$(RESET)"
					$(RM) $(NAME_LIBFT)
					@echo "$(BLACK_ON_RED)\t\t\t\t\t*/ $(NAME_LIBFT) \*$(RESET)"

re_libft: 			fclean_libft libft

ft_printf:			libft $(NAME_FT_PRINTF) print_end_ft_printf

print_start_ft_printf:
					@echo "$(YELLOW)Building $(NAME_FT_PRINTF)...$(RESET)"

print_end_ft_printf:
					@echo "$(BLACK_ON_GREEN)\t\t\t\t\t*/ $(NAME_FT_PRINTF) \*$(RESET)"

$(NAME_FT_PRINTF):	print_start_ft_printf $(FT_PRINTF_OBJS)
					$(AR) $(NAME_FT_PRINTF) $(FT_PRINTF_OBJS)

$(OBJS_DIR)/$(FT_PRINTF_SRC)/%.o: $(FT_PRINTF_SRC)/%.c
					@mkdir -p $(dir $@)
					$(CC) -c $(CFLAGS) -I $(FT_PRINTF_H) $< -o $@

clean_ft_printf:
					@echo "$(YELLOW)Cleaning $(NAME_FT_PRINTF)...$(RESET)"
					$(RM) $(OBJS_DIR)/$(FT_PRINTF_SRC)
					@echo "$(RED)Cleaned $(NAME_FT_PRINTF)$(RESET)"

fclean_ft_printf: 	clean_ft_printf
					@echo "$(YELLOW)Forcefully cleaning $(NAME_FT_PRINTF)...$(RESET)"
					$(RM) $(NAME_FT_PRINTF)
					@echo "$(BLACK_ON_RED)\t\t\t\t\t*/ $(NAME_FT_PRINTF) \*$(RESET)"

re_ft_printf: 		fclean_ft_printf ft_printf

get_next_line:		$(NAME_GNL) print_end_gnl

print_start_gnl:
					@echo "$(YELLOW)Building $(NAME_GNL)...$(RESET)"

print_end_gnl:
					@echo "$(BLACK_ON_GREEN)\t\t\t\t\t*/ $(NAME_GNL) \*$(RESET)"

$(NAME_GNL):		print_start_gnl $(GNL_OBJS)
					$(AR) $(NAME_GNL) $(GNL_OBJS)

$(OBJS_DIR)/$(GNL_SRC)/%.o: $(GNL_SRC)/%.c
					@mkdir -p $(dir $@)
					$(CC) -c $(CFLAGS) -I $(GNL_H) $< -o $@

clean_gnl:
					@echo "$(YELLOW)Cleaning $(NAME_GNL)...$(RESET)"
					$(RM) $(OBJS_DIR)/$(GNL_SRC)
					@echo "$(RED)Cleaned $(NAME_GNL)$(RESET)"

fclean_gnl: 		clean_gnl
					@echo "$(YELLOW)Forcefully cleaning $(NAME_GNL)...$(RESET)"
					$(RM) $(NAME_GNL)
					@echo "$(BLACK_ON_RED)\t\t\t\t\t*/ $(NAME_GNL) \*$(RESET)"

re_gnl: 			fclean_gnl get_next_line

clean:				clean_libft clean_ft_printf clean_gnl
					@echo "$(YELLOW)Cleaning $(NAME_ALL)...$(RESET)"
					$(RM) $(OBJS_DIR)
					@echo "$(RED)Cleaned $(NAME_ALL)$(RESET)"

fclean: 			clean fclean_libft fclean_ft_printf fclean_gnl
					@echo "$(YELLOW)Forcefully cleaning $(NAME_ALL)...$(RESET)"
					$(RM) $(NAME_ALL)
					@echo "$(BLACK_ON_RED)\t\t\t\t\t*/ $(NAME_ALL) \*$(RESET)"

re: 				fclean all

.PHONY: 			all libft ft_printf get_next_line clean fclean re \
					clean_libft clean_ft_printf clean \
					fclean_libft fclean_ft_printf fclean_gnl \
					re_libft re_ft_printf re_gnl

#END
