##############################################
############|---------------------|###########
############| COMPILER & FLAGS    |###########
############|---------------------|###########
##############################################
CC      = cc
CFLAGS  = -Wall  -Wextra -Werror  -I/usr/include   -Icode/inc -Icode/libft -Icode/printf -Icode/mlx -g

LDFLAGS   =  -lmlx  -lXext -lX11
GREEN   = \033[0;32m
RED     = \033[0;31m
YELLOW  = \033[0;33m
NC      = \033[0m

##############################################
############|---------------------|###########
############| CONFIGURATION       |###########
############|---------------------|###########
##############################################
NAME    = so_long
OBJDIR  = code/obj
#SRCS    = $(wildcard code/*.c)
SRCS    = code/errors2.c              code/init_game_obj.c        code/map_related_shit.c \
		code/errors.c               code/init_game_obj_utils.c  code/mlx_init.c \
		code/flood_fill.c           code/key_handler.c          code/render_map.c \
		code/get_next_line.c        code/main.c                 code/utils.c \
		code/get_next_line_utils.c  code/map_parsing.c \

OBJS    = $(patsubst code/%.c,$(OBJDIR)/%.o,$(SRCS))

LIBS    = code/mlx/libmlx.a  code/mlx/libmlx_Linux.a  code/libft/libft.a code/printf/libftprintf.a

##############################################
############|---------------------|###########
############|   MAP DIRECTORIES   |###########
############|for reference/testing|###########
############|---------------------|###########
##############################################
VALID_MAPS = maps/valid/one.ber maps/valid/tree.ber maps/valid/two.ber
INVALID_MAPS = maps/invalid/duplicate_exit.ber maps/invalid/duplicate_player.ber maps/invalid/forbidden_character.ber maps/invalid/no_collectible.ber maps/invalid/no_exit.ber maps/invalid/no_path_to_all_collectibles.ber maps/invalid/no_path_to_exit.ber maps/invalid/no_player.ber maps/invalid/not_enclosed_middle_edge.ber maps/invalid/not_enclosed_top_left.ber maps/invalid/not_rectangular.ber maps/invalid/one.b maps/invalid/tree.berrr maps/invalid/two.shit
ALL_MAPS = $(VALID_MAPS) $(INVALID_MAPS)


##############################################
############|---------------------|###########
############|   PRIMARY TARGETS   |###########
############|---------------------|###########
##############################################


all: libs $(OBJDIR) $(NAME)


$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS)  $(LDFLAGS) -o $@ $(OBJS) $(LIBS) && echo "$(GREEN)✓ $(NAME) linked successfully!$(NC)" || echo "$(RED)✗ Failed to link $(NAME).$(NC)"

##############################################
############|---------------------|###########
############| LIBRARY COMPILATION |###########
############|---------------------|###########
##############################################


libs:
	@echo "$(YELLOW)Compiling external libraries...$(NC)"
	@$(MAKE) -s -C code/mlx && echo "$(GREEN)✓ MinilibX compiled. $(NC)" || echo "$(RED)✗ MinilibX compilation failed. $(NC)"
	@$(MAKE) -s -C code/printf && echo "$(GREEN)✓ Printf library compiled. $(NC)" || echo "$(RED)✗ Printf library compilation failed. $(NC)"
	@$(MAKE) -s -C code/libft && echo "$(GREEN)✓ Libft compiled. $(nc)" || echo "$(RED)✗ Printf library compilation failed. $(NC)"



$(OBJDIR):
	@echo "$(YELLOW)Creating object directory: $(OBJDIR)/$(NC)"
	@mkdir -p $(OBJDIR)


$(OBJDIR)/%.o: code/%.c
	@echo "$(YELLOW)Compiling source file: $<...$(NC)"
	@echo "$(YELLOW)Processing: $<$(NC)"
	@echo "$(YELLOW)Compiling $< into $@...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@ && echo "$(GREEN)✓ Compiled $@$(NC)" || echo "$(RED)✗ Failed to compile $@$(NC)"



##############################################
############|---------------------|###########
############|    CLEANING RULES   |###########
############|---------------------|###########
##############################################


.PHONY: all clean fclean re libs $(OBJDIR) leak list_maps


clean:
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	@rm -rf $(OBJDIR) && echo "$(GREEN)✓ Object directory cleaned.$(NC)" || echo "$(RED)✗ Failed to clean object directory.$(NC)"

	@echo "$(YELLOW)Cleaning library objects...$(NC)"
	@for d in code/libft code/mlx code/printf; do \
		$(MAKE) -s -C $$d clean && echo "$(GREEN)✓ Cleaned $$d objects.$(NC)" || echo "$(RED)✗ Failed to clean $$d objects.$(NC)"; \
	done


fclean: clean
	@echo "$(YELLOW)Cleaning executable: $(NAME)...$(NC)"
	@rm -f $(NAME) && echo "$(GREEN)✓ Executable cleaned.$(NC)" || echo "$(RED)✗ Failed to clean executable.$(NC)"

	@echo "$(YELLOW)Cleaning library final products...$(NC)"
	@for d in code/mlx code/printf; do \
		$(MAKE) -s -C $$d fclean && echo "$(GREEN)✓ Cleaned $$d final products.$(NC)" || echo "$(RED)✗ Failed to clean $$d final products.$(NC)"; \
	done


re: fclean all
	@echo "$(GREEN)Project rebuilt successfully!$(NC)"

##############################################
############|---------------------|###########
############| HELPER & DEBUGGING RULES |######
############|---------------------|###########
##############################################


leak: $(NAME)
	@echo "$(YELLOW)Running Valgrind memory leak check...$(NC)"
# TODO: FIX THIS AI BULLSHIT BELOW
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)
mr: all
	./$(NAME)
test_maps:
	@for map in $(ALL_MAPS); do \
		echo "Testing $$map:"; \
		./so_long $$map || echo "FAILED on $$map"; \
		echo ""; \
	done
