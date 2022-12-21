# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 19:47:28 by bdetune           #+#    #+#              #
#    Updated: 2022/12/13 19:45:03 by bdetune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#**********************************   Build  **********************************#

all :		vector map set

vector :
		cd vector && ./start_tests.sh build

map:
		cd map && ./start_tests.sh build

set:
		cd set && ./start_tests.sh build


#**********************************   Clean  **********************************#

clean:		clean-vector clean-map clean-set

clean-vector:
		cd vector && ./start_tests.sh clean

clean-map:
		cd map && ./start_tests.sh clean

clean-set:
		cd set && ./start_tests.sh clean


#**********************************  Fclean  **********************************#

fclean:			fclean-vector fclean-map fclean-set

fclean-vector:
			cd vector && ./start_tests.sh fclean

fclean-map:
			cd map && ./start_tests.sh fclean

fclean-set:
			cd set && ./start_tests.sh fclean


#************************************  Re  ************************************#

re:		re-vector re-map re-set

re-vector:
		cd vector && ./start_tests.sh re

re-map:
		cd map && ./start_tests.sh re

re-set:
		cd set && ./start_tests.sh re


#***********************************  Test  ***********************************#

test:		test-vector test-map test-set

test-vector:
		cd vector && ./start_tests.sh

test-map:
		cd map && ./start_tests.sh

test-set:
		cd set && ./start_tests.sh


#********************************   Benchmark  ********************************#

benchmark:		benchmark-vector benchmark-map benchmark-set

benchmark-vector:
			cd vector && ./start_tests.sh benchmark

benchmark-map:
			cd map && ./start_tests.sh benchmark

benchmark-set:
			cd set && ./start_tests.sh benchmark


#**********************************   Phony  **********************************#

.PHONY: all vector map set clean clean-vector clean-map clean-set fclean fclean-vector fclean-map fclean-set re re-vector re-map re-set test test-vector test-vector test-set benchmark benchmark-vector benchmark-map benchmark-set
