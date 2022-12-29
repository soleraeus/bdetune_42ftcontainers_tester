# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 19:47:28 by bdetune           #+#    #+#              #
#    Updated: 2022/12/23 15:29:15 by bdetune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STACK_LOCATION = ../..

NAME = 01.constructor
SRC = 01.constructor.cpp 


INC =  $(INC_DIR)/ConstClass.hpp

SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = objs
BIN_DIR = bin

ISFT = 0

ifeq ($(ISFT), 0)
	NAMESPACE = std
else
	NAMESPACE = ft
endif

OBJS := $(SRC:%.cpp=$(OBJ_DIR)/%_$(NAMESPACE).o)

DEP = $(OBJS:%.o=%.d)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -Wshadow -std=c++98 -g


$(BIN_DIR)/$(NAME)_$(NAMESPACE): $(OBJS) $(INC)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

all: $(BIN_DIR)/$(NAME)_$(NAMESPACE)
.PHONY: all

-include $(DEP)

$(OBJ_DIR)/%_$(NAMESPACE).o: $(SRC_DIR)/%.cpp
				$(CXX) $(CXXFLAGS) -MMD -I$(STACK_LOCATION) -I$(INC_DIR) -D ISFT=$(ISFT) -c -o $@ $<

$(OBJS):	$(INC)

clean:
	rm -rf $(OBJS) $(DEP)
.PHONY: clean

fclean: clean
	rm -rf $(BIN_DIR)/$(NAME)_$(NAMESPACE)
.PHONY: fclean

re: fclean all
.PHONY: re
