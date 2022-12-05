NAME 		=	so_long
CC			=	cc
# CC			=	clang
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
# FTNAME		=	$(MLXDIR)/libft.a
MLX			=	$(MLXNAME)
LMLX		=	-L$(MLXDIR) -lmlx -lXext -lX11

SRCS		= 	main.c	\
				utils.c	\
				check_arg.c	\
				make_map.c	\
				check_around_map.c \
				check_player.c	\
				check_exit.c	\
				check_collectible.c	\
				check_square.c	\
				check_useless_characters.c \
				dfs.c	\
				mlx.c


OBJDIR   = obj
OBJS  = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


all: $(NAME)

$(NAME):$(OBJS) $(GNL) $(FT) $(MLX)
		$(CC) $(INCLUDE) -o $(NAME) $^ $(CFLAGS) -L$(MLXDIR) $(LMLX)
#$(CC) $(INCLUDE) -o $(NAME) $< $(GNLNAME)  $(PRNAME) $(CFLAGS)

$(MLX):
		$(MAKE) -C $(MLXDIR)

gnl:
		$(MAKE) --no-print-directory -C $(GNLDIR)
$(GNL):
		$(MAKE) -C $(GNLDIR)

$(FT):
		$(MAKE) -C $(FTDIR)
libft:
		$(MAKE) --no-print-directory -C $(FTDIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<



clean:
		$(MAKE) --no-print-directory clean -C $(GNLDIR)
		$(MAKE) --no-print-directory clean -C $(FTDIR)
		$(RM) -r $(OBJDIR)

fclean: clean
		$(MAKE) --no-print-directory fclean -C $(GNLDIR)
		$(MAKE) --no-print-directory fclean -C $(FTDIR)
		$(RM) $(NAME)

re : fclean all

.PHONY:
		all clean fclean re gnl libft
