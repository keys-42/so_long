NAME 		=	so_long
CC			=	cc
# CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined
# CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I ./include/

GNLDIR		=	get_next_line
GNLNAME		=	$(GNLDIR)/gnl.a
GNL			=	$(GNLNAME)

SRCS		= 	main.c	\
				utils.c	\
				check_arg.c	\
				make_map.c	\
				check_around_map.c \
				check_person.c	\
				check_exit.c



OBJDIR   = obj
OBJS  = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


all: $(NAME)

$(NAME): $(OBJS) $(GNL)
		$(CC) $(INCLUDE) -o $(NAME) $^ $(CFLAGS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<


$(GNL):
		$(MAKE) -C $(GNLDIR)
gnl:
		$(MAKE) --no-print-directory -C $(GNLDIR)

clean:
		$(MAKE) --no-print-directory clean -C $(GNLDIR)
		$(RM) -r $(OBJDIR)

fclean: clean
		$(MAKE) --no-print-directory fclean -C $(GNLDIR)
		$(RM) $(NAME)

re : fclean all

.PHONY:
		all clean fclean re gnl
