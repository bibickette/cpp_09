# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <phwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 13:17:33 by phwang            #+#    #+#              #
#    Updated: 2025/04/02 23:51:13 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rpn

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -I$(INCLUDE_DIR) -I$(COLOR_DIR)

COLOR_DIR = ../include/
INCLUDE_DIR = include/
SRC_DIR = src/
OBJ_DIR = obj

SRC_FILES = \
	RPN.cpp \
	main.cpp
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

MANDATORY_SRCS = $(SRC)

PMANDATORY =  $(addprefix , $(MANDATORY_SRCS))
OBJS = $(PMANDATORY:$(SRC_DIR)%.cpp=$(OBJ_DIR)/%.o)


#PROGRESS BAR
TOTAL_SRCS := $(words $(MANDATORY_SRCS))
COMPILED_SRCS := 0
#COLOR SET
COLOR_RESET = \e[0m
COLOR_GREEN = \e[36m
COLOR_BLUE = \e[36m


all: $(NAME)

$(OBJ_DIR)/%.o :  $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

	@$(eval COMPILED_SRCS=$(shell echo $$(($(COMPILED_SRCS)+1))))
	@echo -n "$(COLOR_BLUE)Compiling Objects $(NAME) $(COLOR_RESET)[$(COLOR_GREEN)"
	@for i in $(shell seq 1 25); do \
		if [ $$i -le $$(($(COMPILED_SRCS)*25/$(TOTAL_SRCS))) ]; then \
			echo -n "♣"; \
		else \
			echo -n "."; \
		fi; \
	done
	@echo -n "$(COLOR_RESET)] $(COMPILED_SRCS)/$(TOTAL_SRCS)\r"

$(NAME) : $(OBJS)
	@echo "$(COLOR_BLUE)\nCompiling $(NAME)...$(COLOR_RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 
	@echo "$(COLOR_GREEN)$(NAME) Compilation complete !$(COLOR_RESET)        "

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(COLOR_BLUE)✘✘✘ Deleting $(NAME)... ✘✘✘$(COLOR_RESET)"
	@rm -f $(NAME)
	@echo "$(COLOR_GREEN)✘✘✘ $(NAME) fcleaned ! ✘✘✘$(COLOR_RESET)        "

re: fclean all

.PHONY: all clean fclean re