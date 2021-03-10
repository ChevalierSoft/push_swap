CC		= gcc
FLAGS	= -g
CH_OBJS = $(CH_SRCS:.c=.o)

CH_SRCS	= $(addprefix srcs/, \
checker.c \
delete_game.c \
display.c \
)

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
	rm 
