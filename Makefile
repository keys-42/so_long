NAME 		=	so_long
CC			=	cc
# CC			=	clang
# CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined -fsanitize=integer
CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I ./include
PRINTFDIR	=	ft_printf
PRINTFNAME		=	$(PRINTFDIR)/libftprintf.a
PRINTF		=	$(PRINTFNAME)
GNLDIR	=get_next_line
GNLNAME		=	$(GNLDIR)/get_next_line.a
GNL		=	$(GNLNAME)

SRCS		=



OBJDIR   = obj
OBJS  = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


all: $(NAME)

$(NAME): $(OBJS) $(PRINTFNAME) $(GNLNAME)
		$(CC) $(INCLUDE) -o $(NAME) $^ $(CFLAGS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

$(PRINTFNAME):
		$(MAKE) -C $(PRINTFDIR)
printf:
		$(MAKE) -C $(PRINTFDIR)
$(GNLNAME):
		$(MAKE) -C $(GNLDIR)
gnl:
		$(MAKE) -C $(GNLDIR)

clean:
		$(MAKE) clean -C $(PRINTFDIR)
		$(RM) -r $(OBJDIR)

fclean: clean
		$(MAKE) fclean -C $(PRINTFDIR)
		$(RM) $(NAME)

re : fclean all

.PHONY:
		all clean fclean re printf gnl
