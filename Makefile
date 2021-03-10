CC		= gcc
FLAGS	= -g

CH_SRCS	= srcs/checker.c

CH_OBJS = $(CH_SRCS:.c=.o)

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
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm 