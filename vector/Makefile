# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 19:47:28 by bdetune           #+#    #+#              #
#    Updated: 2022/12/23 15:30:27 by bdetune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VECTOR_LOCATION = ../..

NAME = 01.constructor
SRC = 01.constructor.cpp 
TIMER = timer.cpp


INC =  $(INC_DIR)/itPrint.hpp $(INC_DIR)/ConstClass.hpp $(INC_DIR)/timer.hpp

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

DEP = $(OBJS:%.o=%.d)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -Wshadow -std=c++98 -g


$(BIN_DIR)/$(NAME)_$(NAMESPACE): $(OBJS) $(TIMER_OBJ) $(INC)
	$(CXX) $(CXXFLAGS) $(OBJS) $(TIMER_OBJ) -o $@

all: $(BIN_DIR)/$(NAME)_$(NAMESPACE)
.PHONY: all

-include $(DEP)

$(OBJ_DIR)/%_$(NAMESPACE).o: $(SRC_DIR)/%.cpp
				$(CXX) $(CXXFLAGS) -MMD -I$(VECTOR_LOCATION) -I$(INC_DIR) -D ISFT=$(ISFT) -c -o $@ $<

$(OBJ_DIR)/%.o: $(INC_DIR)/%.cpp
				$(CXX) $(CXXFLAGS)  -I$(VECTOR_LOCATION) -I$(INC_DIR) -D ISFT=$(ISFT) -c -o $@ $<

$(OBJS):	$(INC)

$(TIMER_OBJ):	$(INC_DIR)/timer.hpp

clean:
	rm -rf $(OBJS) $(DEP) $(TIMER_OBJ)
.PHONY: clean

fclean: clean
	rm -rf $(BIN_DIR)/$(NAME)_$(NAMESPACE)
.PHONY: fclean

re: fclean all
.PHONY: re
