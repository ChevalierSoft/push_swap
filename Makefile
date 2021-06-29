CC			= gcc
FLAGS		= -g -Wall -Wextra -Werror
PS_OBJS		= $(PS_SRCS:.c=.o)
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
game_init.c \
quit.c \
\
display.c \
is_sorted.c \
)

CH_SRCS		= $(addprefix srcs/, \
checker.c \
listen.c \
)

PS_SRCS		= $(addprefix srcs/, \
dumb_sort_100.c \
find_first_chunk.c \
find_lowest.c \
get_n_limits.c \
push_chunk.c \
push_swap.c \
sort_2.c \
sort_3.c \
sort_4.c \
sort_5.c \
straff_to.c \
sanic_sort.c \
)

CH_SRCS 	+= $(SHARED_SRCS)
PS_SRCS 	+= $(SHARED_SRCS)

ifeq ($(OS),Windows_NT)
	POSIX = 0
else
	POSIX = 1
endif

CYN			= \033[36m
RST			= \033[0m

all : push_swap # checker

push_swap : _libft $(PS_OBJS)
	@$(CC) $(FLAGS) -o push_swap $(PS_OBJS) -DPOSIX=$(POSIX) ./libft/libft.a
	@echo "$(CYN)done push_swap $(RST)"

checker : _libft $(CH_OBJS)
	@$(CC) $(FLAGS) -o checker $(CH_OBJS) -DPOSIX=$(POSIX) ./libft/libft.a
	@echo "$(CYN)done checker $(RST)"

bonus : checker

_libft :
	@make --silent -C ./libft/

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@ -DPOSIX=$(POSIX)

clean :
	@/bin/rm -f $(PS_OBJS) 
	@/bin/rm -f $(CH_OBJS) 
	@make fclean --silent -C ./libft

fclean : clean
	@/bin/rm -f push_swap
	@/bin/rm -f checker

re : fclean all

.PHONY : all re clean fclean checker push_swap _libft
