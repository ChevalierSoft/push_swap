CC			= gcc
FLAGS		= -g
CH_OBJS 	= $(CH_SRCS:.c=.o)

SHARED_SRCS	= $(addprefix srcs/, \
sa.c \
sb.c \
ss.c \
pa.c \
pb.c \
ra.c \
rb.c \
rr.c \
rra.c \
rrb.c \
rrr.c \
check_args.c \
check_occ.c \
delete_game.c \
fill_stack.c \
quit.c \
)

CH_SRCS		= $(addprefix srcs/, \
checker.c \
display.c \
is_sorted.c \
listen.c \
)

CH_SRCS 	+= $(SHARED_SRCS)

ifeq ($(OS),Windows_NT)
	POSIX = 0
else
	POSIX = 1
endif

all: _libft $(CH_OBJS)
	@$(CC) $(FLAGS) -o checker $(CH_OBJS) -DPOSIX=$(POSIX) ./libft/libft.a

_libft:
	@make --silent -C ./libft/

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@ -DPOSIX=$(POSIX)

clean:
	@/bin/rm -f $(CH_OBJS) 

fclean: clean
	@/bin/rm -f checker
#	make fclean --silent -C ./libft

re : fclean all

.PHONY : all re clean fclean checker push_swap _libft

