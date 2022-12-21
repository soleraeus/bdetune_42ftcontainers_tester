# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 19:47:28 by bdetune           #+#    #+#              #
#    Updated: 2022/12/13 19:43:17 by bdetune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAP_LOCATION = ../..

NAME = 01.constructor
SRC = 01.constructor.cpp 
TIMER = timer.cpp

DEP = $(MAP_LOCATION)/map.hpp
INC =  $(INC_DIR)/ConstClass.hpp $(INC_DIR)/timer.hpp $(INC_DIR)/customCompare.hpp

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
TIMER_OBJ :=  $(TIMER:%.cpp=$(OBJ_DIR)/%.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -Wshadow -std=c++98 -g


$(BIN_DIR)/$(NAME)_$(NAMESPACE): $(OBJS) $(TIMER_OBJ) $(INC) $(DEP)
	$(CXX) $(CXXFLAGS) $(OBJS) $(TIMER_OBJ) -o $@

all: $(BIN_DIR)/$(NAME)_$(NAMESPACE)
.PHONY: all

$(OBJ_DIR)/%_$(NAMESPACE).o: $(SRC_DIR)/%.cpp
				$(CXX) $(CXXFLAGS)  -I$(MAP_LOCATION) -I$(INC_DIR) -D ISFT=$(ISFT) -c -o $@ $<

$(OBJ_DIR)/%.o: $(INC_DIR)/%.cpp
				$(CXX) $(CXXFLAGS)  -I$(MAP_LOCATION) -I$(INC_DIR) -D ISFT=$(ISFT) -c -o $@ $<


$(OBJS):	$(INC) $(DEP)

$(TIMER_OBJ):	$(INC_DIR)/timer.hpp

clean:
	rm -rf $(OBJS) $(TIMER_OBJ)
.PHONY: clean

fclean: clean
	rm -rf $(BIN_DIR)/$(NAME)_$(NAMESPACE)

.PHONY: fclean

re: fclean all
.PHONY: re

.SECONDARY : $(OBJS) $(TIMER_OBJ)
