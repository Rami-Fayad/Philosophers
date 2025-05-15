NAME            := mandatory_philo
EXECUTABLE      := philo
CC              := cc
CYAN            := \33[1;36m
RESET           := \033[0m
BLINK           := \33[5m
BOLD            := \33[1m
LOG             := printf "[$(CYAN)INFO$(RESET)] %s\n"


OBJ_DIR         := obj
INC_DIRS        := include
SRC_DIRS        := $(addprefix philo/, $(SRC_DIRS))
SRC_DIRS        += src

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

HEADERS         := philo.h

SOURCES         := main.c \
                   dinner.c \
                   utils.c \
                   init.c \
                   monitor.c \
                   validation.c \
                   status.c

OBJS            := $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

CFLAGS          := -Wall -Werror -Wextra -g $(addprefix -I,$(INC_DIRS))

all: $(NAME) no_relink

$(NAME): $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	@echo "=============================="
	@echo "🚀 Building $(EXECUTABLE) for Rami... 🚀"
	@echo "=============================="
	@$(LOG) "Linking objects to $@"
	$(CC) $^ -lrt -lpthread -o $@
	@echo "=================================="
	@echo "🎉 Build complete for $(EXECUTABLE)! 🎉"
	@echo "=================================="
	@echo "	     _____          ____        ______  _______    ____ "
	@echo "	 ___|\    \    ____|\   \      |      \/       \  |    |"
	@echo "	|    |\    \  /    /\    \    /          /\     \ |    |"
	@echo "	|    | |    ||    |  |    |  /     /\   / /\     ||    |"
	@echo "	|    |/____/ |    |__|    | /     /\ \_/ / /    /||    |"
	@echo "	|    |\    \ |    .--.    ||     |  \|_|/ /    / ||    |"
	@echo "	|    | |    ||    |  |    ||     |       |    |  ||    |"
	@echo "	|____| |____||____|  |____||\____\       |____|  /|____|"
	@echo "	|    | |    ||    |  |    || |    |      |    | / |    |"
	@echo "	|____| |____||____|  |____| \|____|      |____|/  |____|"
	@echo "	  \(     )/    \(      )/      \(          )/       \(  "
	@echo "	   '     '      '      '        '          '         '  "
	@echo "=================================="
	@echo "🎉 Congratulations, Rami! 🎉"
	@echo "=================================="
$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@echo "=============================="
	@echo "🔨 Compiling $< for Rami... 🔨"
	@echo "=============================="
	@$(LOG) "Compiling $@"
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	@$(LOG) "Creating objects directory"
	@mkdir $@

no_relink:
	@echo "                                                     "
	@echo "$(BOLD)$(BLINK)😊 Don't worry, Mr. Walid! 😊$(RESET)"
	@echo "    My Makefile doesn't relink. 🌟"
	@echo "=================================="
	@echo "        ~ Rami Al Fayad ~"
drd: $(NAME)
	@echo "=============================="
	@echo "🔍 Running Valgrind DRD for Rami... 🔍"
	@echo "=============================="
	valgrind --tool=drd ./$(EXECUTABLE) 5 800 200 200 5

hell: $(NAME)
	@echo "=============================="
	@echo "🔍 Running Valgrind Helgrind for Rami... 🔍"
	@echo "=============================="
	valgrind --tool=helgrind ./$(EXECUTABLE) 5 800 200 200 5

check: $(NAME)
	@echo "=============================="
	@echo "🔍 Running Valgrind Check for Rami... 🔍"
	@echo "=============================="
	valgrind -q --leak-check=full --show-leak-kinds=all \
		--track-origins=yes ./$(EXECUTABLE) 5 800 200 200 5

clean:
	@echo "=============================="
	@echo "🧹 Cleaning up object files for Rami... 🧹"
	@echo "=============================="
	@$(RM) -r $(OBJS)
	@$(LOG) "Removing objects"
	@$(RM) -r $(OBJ_DIR)
	@$(LOG) "Removing objects directory"

fclean: clean
	@echo "=============================="
	@echo "🧽 Performing full cleanup for Rami... 🧽"
	@echo "=============================="
	@$(RM) -r $(EXECUTABLE)
	@$(LOG) "Removing $(EXECUTABLE)"

re: fclean all

.PHONY: all clean fclean re drd hell check
