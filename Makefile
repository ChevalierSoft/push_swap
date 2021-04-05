CC			= gcc
FLAGS		= -g
PS_OBJS		= $(PS_SRCS:.c=.o)
CH_OBJS 	= $(CH_SRCS:.c=.o)
PT_OBJS 	= $(PT_SRCS:.c=.o)

PT_SRCS		= ./ps_tester/ps_tester.c

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
)

CH_SRCS		= $(addprefix srcs/, \
checker.c \
is_sorted.c \
listen.c \
)

PS_SRCS		= $(addprefix srcs/, \
dumb_sort.c \
dumb_sort2.c \
dumb_sort_100.c \
insert_sort.c \
find_lowest.c \
push_swap.c \
sort_2.c \
sort_3.c \
sort_4.c \
sort_5.c \
sort_100.c \
sort_stack.c \
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

all : push_swap checker

pt : $(PT_OBJS)
	@gcc -O3 -o pt $(PT_OBJS)
	@echo "paf c'est pret"

push_swap : _libft $(PS_OBJS)
	@$(CC) $(FLAGS) -o push_swap $(PS_OBJS) -DPOSIX=$(POSIX) ./libft/libft.a

checker : _libft $(CH_OBJS)
	@$(CC) $(FLAGS) -o checker $(CH_OBJS) -DPOSIX=$(POSIX) ./libft/libft.a

_libft :
	@make --silent -C ./libft/

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@ -DPOSIX=$(POSIX)

clean :
	@/bin/rm -f $(PS_OBJS) 
	@/bin/rm -f $(CH_OBJS) 

fclean : clean
	@/bin/rm -f push_swap
	@/bin/rm -f checker
#	make fclean --silent -C ./libft

re : fclean all

.PHONY : all re clean fclean checker push_swap _libft

