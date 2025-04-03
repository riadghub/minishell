NAME = minishell

SRCS =	srcs/main.c								\
		srcs/built_in.c							\
		srcs/built_in2.c						\
		utils/utils.c							\
		utils/ft_strcmp.c						\
		utils/ft_strncmp.c						\
		utils/ft_strlen.c						\
		utils/ft_split.c						\
		

HEADERS = ./includes/

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -lreadline

# Couleurs ANSI
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

# Règle principale
all: ${NAME}

# Règle pour compiler les fichiers objets
%.o : %.c
	@echo "$(BLUE)Compiling $(YELLOW)$< $(RESET)..."
	@${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

# Règle pour lier le programme final
${NAME}: ${OBJS}
	@echo "$(GREEN)Linking objects into $(YELLOW)${NAME}$(RESET)..."
	@${CC} ${CFLAGS} -I ${HEADERS} ${OBJS} -o ${NAME}
	@echo "$(GREEN)Build complete!$(RESET)"

# Règle pour nettoyer les fichiers objets
clean :
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f ${OBJS}
	@echo "$(GREEN)Clean complete!$(RESET)"

# Règle pour nettoyer les fichiers objets et l'exécutable
fclean : clean
	@echo "$(RED)Removing $(YELLOW)${NAME}$(RESET)..."
	@rm -f ${NAME}
	@echo "$(GREEN)Full clean complete!$(RESET)"

# Règle pour recompiler entièrement le projet
re : fclean all
	@echo "$(GREEN)Rebuild complete!$(RESET)"

.PHONY: all clean fclean re run