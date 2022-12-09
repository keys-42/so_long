NAME 		=	so_long
CC			=	cc
# CC			=	clang
# CFLAGS		= -g -fsanitize=address -fsanitize=undefined
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined
# CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I ./include/

GNLDIR		=	get_next_line
GNLNAME		=	$(GNLDIR)/gnl.a
GNL			=	$(GNLNAME)

FTDIR		=	libft
FTNAME		=	$(FTDIR)/libft.a
FT			=	$(FTNAME)

MLXDIR		=	minilibx-linux
MLXNAME		= $(MLXDIR)/libmlx_Linux.a
MLX			=	$(MLXNAME)
MLX_FLAGS_LINUX	=	-L$(MLXDIR) -lmlx -lXext -lX11


SRCS		= 	srcs/main.c	\
				srcs/utils/get_struct.c \
				srcs/checks/checks.c	\
				srcs/checks/square.c	\
				srcs/checks/wall.c	\
				srcs/checks/player.c	\
				srcs/checks/exit.c	\
				srcs/checks/collectibles.c	\
				srcs/checks/use_characters.c	\
				srcs/checks/can_finish.c	\
				srcs/utils/free.c	\
				srcs/utils/utils.c	\
				srcs/make/make_map.c	\
				srcs/mlx/mlx.c	\
				srcs/mlx/init.c	\
				srcs/mlx/hook.c	\
				srcs/mlx/paint.c \
				srcs/mlx/map_swap.c


OBJDIR   = obj
OBJS  = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


all: $(NAME)

$(NAME):$(OBJS) $(GNL) $(FT) $(MLX)
		$(CC) $^ $(CFLAGS) $(MLX_FLAGS_LINUX) -o $@

$(MLX):
		$(MAKE) -C $(MLXDIR)

$(GNL):
		$(MAKE) --no-print-directory -C $(GNLDIR)

$(FT):
		$(MAKE) --no-print-directory -C $(FTDIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<



clean:
		$(MAKE) clean -C $(MLXDIR)
		$(MAKE) --no-print-directory clean -C $(GNLDIR)
		$(MAKE) --no-print-directory clean -C $(FTDIR)
		$(RM) -r $(OBJDIR)

fclean: clean
		$(MAKE) clean -C $(MLXDIR)
		$(MAKE) --no-print-directory fclean -C $(GNLDIR)
		$(MAKE) --no-print-directory fclean -C $(FTDIR)
		$(RM) $(NAME)

re : fclean all

.PHONY:
		all clean fclean re
