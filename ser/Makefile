SRCS =	main.c \
	init_env.c \
	clean_fd.c \
	get_opt.c \
	x.c \
	main_loop.c \
	init_fd.c \
	do_select.c \
	check_fd.c \
	srv_create.c \
	srv_accept.c \
	client_read.c \
	client_write.c \
	input.c \
	input_action.c \
	send.c

NAME = server
GCC_FLAGS = -Wall -Werror -Wextra
CC = gcc $(GCC_FLAGS)
SRCDIR = ./
OBJDIR = ./objs
AR = ar -cq
RM = rm -rf
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIBFTDIR = ../libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR)
	@echo $(SRC_LIB_O)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -lft -L../libft/

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $^ -I../libft/

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all
