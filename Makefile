NAME = minitalk.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	client.c server.c minitalk_utils.c \

OBJ = $(SRC:%.c=%.o)
BONUSSRC = client_bonus.c server_bonus.c minitalk_utils_bonus.c \
OBJ = $(SRC:%.c=%.o)

OBJBONUS = $(BONUSSRC:%.c=%.o)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ)

all : $(NAME) bonus

bonus : $(OBJBONUS)
		ar rc $(NAME) $(OBJBONUS)

clean :
		@rm -rf $(OBJBONUS) $(OBJ)

fclean :
		@rm -f $(NAME) $(OBJBONUS) $(OBJ)

re : fclean all