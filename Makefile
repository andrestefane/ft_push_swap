CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft
LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a

SRCS = ft_create_stack.c ft_my_fuctions.c ft_parses.c push_swap.c

SRCS_MOVEMENTS = movements/pa_push_a.c movements/pb_push_b.c movements/ra_rotate_a.c movements/rb_rotate_b.c movements/rr_ra_rb.c movements/rra_reverse_rotate_a.c \
                 movements/rrb_reverse_rotate_b.c movements/rrr_rra_rrb.c movements/sa_swap_a.c movements/sb_swap_b.c movements/ss_swap_ab.c

SRCS_TURKSORT = turksort/turksort.c turksort/Big_turksort.c turksort/count_numbs.c turksort/sort_stack.c

OBJS = $(SRCS:.c=.o) $(SRCS_MOVEMENTS:.c=.o) $(SRCS_TURKSORT:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
