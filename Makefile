#***** Name *****#

NAME			=		pipex

#***** Makeflags *****#

MAKEFLAGS += --no-print-directory

#***** Sources / Objs *****#

SRC				=		pipex.c \
						init/check_arg.c \
						init/path.c \
						init/pipe.c \
						utils/fd_close.c \
						utils/free_and_exit.c \
						utils/is_valid_cmd.c \
						utils/error.c \
						utils/time_to_fork.c \
						utils/child_process.c \
						utils/child2_process.c \

OBJS			=		$(SRC:.c=.o)

#***** Libft *****#

LIBFT			=		./libft/libft.a
MLIBFT			=		@$(MAKE) -C libft

#***** Couleurs *****#

GREEN			=		\033[1;32m
BG_GREEN		=		\033[42m
BLUE			=		\033[0;94m
RED				=		\033[1;31m
GREY			=		\033[0;37m
ENDCOLOR		=		\033[0m

#***** Textes *****#

START_TXT		=		echo "$(GREEN)Compilation of $(NAME) just started$(ENDCOLOR)"
TEST_TXT		=		echo "$(GREY)Running some test$(ENDCOLOR)\n"
END_COMP_TXT	=		echo "$(GREEN)Compilation is done$(ENDCOLOR)"
CLEAN_TXT		=		echo "$(RED)Deleting objects$(ENDCOLOR)"
FCLEAN_TXT		=		echo "$(RED)Deleting program$(ENDCOLOR)"
CHARG_LINE_TXT	=		echo "$(BG_GREEN)    $(ENDCOLOR)\c"
BS_N_TXT			=		echo "\n"

#***** Flags *****#

CC				=		gcc
CFLAGS			=		-Wall -Wextra -Werror -g
L				=		$(CFLAGS) -fsanitize=address
RM				=		rm -f

#***** Compilation *****#

all : logo lib start $(NAME)

lib:
			@$(MLIBFT) all
			@$(END_COMP_LIB_TXT)

logo :
			@tput setaf 2; cat ascii_art/hibou; tput setaf default
			@$(BS_N_TXT)

start:
			@tput setaf 2; cat ascii_art/pipex; tput setaf default
			@$(BS_N_TXT)
			@$(START_TXT)

%.o:		%.c ./libft/libft.h Makefile
			@$(CC) $(CFLAGS) -c $< -o $@
			@$(CHARG_LINE_TXT)

$(NAME) :	${OBJS}
			@$(BS_N_TXT)
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}
			@$(END_COMP_TXT)
			@tput setaf 2; cat ascii_art/small_hibou1; tput setaf default

l :			${OBJS}
			${MLIBFT} all
			${CC} ${L} -o ${NAME} ${OBJS} ${LIBFT}
			@$(END_COMP_TXT)

leaks :		all
			leaks --atExit -- ./${NAME}

test :		
			make re
			@tput setaf 1
			@rm -rf output.txt
			./pipex input.txt "ls -l" "wc -l" output.txt
			@echo "pipex res ="
			@cat output.txt
			@rm -rf output.txt
			< input.txt ls -l | wc -l > output.txt
			@echo "shell res ="
			@cat output.txt

test2 :		
			make re
			@tput setaf 1
			@rm -rf output.txt
			./pipex input.txt "grep a1" "wc -w" output.txt
			@echo "pipex res ="
			@cat output.txt
			@rm -rf output.txt
			< input.txt grep a1 | wc -w > output.txt
			@echo "shell res ="
			@cat output.txt

#***** Clean *****#

clean:
			@$(CLEAN_TXT)
			@${RM} ${OBJS}
			@${MLIBFT} clean
			@tput setaf 1; cat ascii_art/trash; tput setaf default

fclean:		clean
			@$(FCLEAN_TXT)	
			@${RM} ${NAME}
			@${MLIBFT} fclean
			@echo "$(GREEN)Cleaning succes$(ENDCOLOR)"

re:			fclean all

.PHONY:		all clean fclean 
