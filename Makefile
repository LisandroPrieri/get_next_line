NAME		=get_next_line.a
CC			=cc
FC			=-Wall -Werror -Wextra -fsanitize=address,undefined,leak
RM			=rm -f
SRC			=get_next_line.c\
			get_next_line_utils.c
OBJ			=$(SRC:%.c=obj/%.o)
FAR			=ar -crs

all:		$(NAME)

bonus:		$(NAME)

clean:
				@$(RM) -r obj
				@printf "\e[1;35mCleaned Object Files\n\e[0;00m"

fclean:		clean
				@$(RM) $(NAME)
				@printf "\e[1;31mCleaned Executables\n\e[0;00m"

re:			fclean all

$(OBJ):		$(SRC) get_next_line.h Makefile
				@mkdir -p $(dir $@)
				@printf "\e[1;34mBuilding $@\n\e[0;00m"
				@$(CC) $(CFLAGS) -c $(@:obj/%.o=%.c) -o $@

$(NAME):	$(OBJ)
				@printf "\e[1;36mCompiling get next line\e[0;00m\n"
				@$(FAR) $(NAME) $^ > /dev/null 2>&1
				@printf "\e[1;32mDone\e[0;00m\n"
