#! /bin/bash

# Loading shell colors definition
source shellColors.sh

# Loading test list
source testList.sh

echo -e "\n${WHITE}*************************  SET *************************${OFF}\n"

SET_LOC=""

# Loading configuration file
source ../config.sh

# Verifying set location has been provided
if [ -z ${SET_LOC} ]
then
	echo -e "${RED}Map location not provided in config.sh${OFF}\n"
	exit 1
elif [ ${SET_LOC::1} == "." ]
then
	SET_LOC="../${SET_LOC}"
fi

# Verifying set location is valid
if ! test -f "${SET_LOC}/set.hpp" ;
then
	echo -e "${RED}set.hpp not found at ${SET_LOC}/set.hpp${OFF}\n";
	exit 1;
fi


FORMAT='%-20s %-20s %-20s\n'
FIELD_SIZE='%-20s'
RET=0

if [ $# -ne 0 ]
then
	if [ "$1" == "clean" ]
	then
		for f in ${testList[@]}; \
		do
			make --no-print-directory SRC="${f}" NAME="${f::-4}" clean
			make --no-print-directory SRC="${f}" NAME="${f::-4}" ISFT=1 clean
		done
	elif [ "$1" == "fclean" ]
	then
		for f in ${testList[@]}; \
		do
			make --no-print-directory SRC="${f}" NAME="${f::-4}" fclean
			make --no-print-directory SRC="${f}" NAME="${f::-4}" ISFT=1 fclean
		done
		rm -rf logs/*; rm -rf diff/*
	elif [ "$1" == "re" ]
	then
		rm -rf logs/*; rm -rf diff/*
		for f in ${testList[@]}; \
		do
			make --no-print-directory SRC="${f}" NAME="${f::-4}" re
			make --no-print-directory SRC="${f}" NAME="${f::-4}" ISFT=1 re
		done
		rm -rf logs/*; rm -rf diff/*
	elif [ "$1" == "build" ]
	then
		rm -rf logs/*; rm -rf diff/* ; \
		mkdir -p bin; mkdir -p logs; mkdir -p diff; mkdir -p objs ; \
		for f in ${testList[@]}; \
		do
			make --no-print-directory SRC="${f}" NAME="${f::-4}" SET_LOCATION="${SET_LOC}"
			make --no-print-directory SRC="${f}" NAME="${f::-4}" ISFT=1 SET_LOCATION="${SET_LOC}"
		done
		rm -rf logs/*; rm -rf diff/*
	elif [ "$1" == "benchmark" ]
	then
		rm -rf logs/*; rm -rf diff/* ; \
		mkdir -p bin; mkdir -p logs; mkdir -p diff; mkdir -p objs ; \
		printf "%-35s   ${FORMAT}" "TEST" "STD" "FT" "RATIO";
		for f in ${testList[@]}; \
		do
			printf '%-35s   ' $f;
			if ! make --no-print-directory SRC="${f}" NAME="${f::-4}" SET_LOCATION="${SET_LOC}" &>/dev/null;
			then
				printf "${FORMAT}" "-" "-" "-"; continue;
			else
				if ! make --no-print-directory SRC="${f}" NAME="${f::-4}" ISFT=1 SET_LOCATION="${SET_LOC}" &>/dev/null;
				then
					printf "${RED}${FORMAT}${OFF}" "-" "Does not compile" "-"; continue;
				fi
			fi
			STD_TIME=$("bin/${f::-4}_std" benchmark 2>/dev/null | tail -1)
			FT_TIME=$("bin/${f::-4}_ft" benchmark 2>/dev/null | tail -1)
			RATIO=$(echo "scale=2;(${FT_TIME} * 100)/${STD_TIME}" | bc)
			if (( $(echo "$RATIO < 100" | bc -l) )); then
				printf "${FIELD_SIZE} ${FIELD_SIZE} ${GREEN}${FIELD_SIZE}${OFF}\n" "${STD_TIME}ms" "${FT_TIME}ms" "${RATIO}%";
			elif (( $(echo "$RATIO < 1000" | bc -l) )); then
				printf "${FIELD_SIZE} ${FIELD_SIZE} ${YELLOW}${FIELD_SIZE}${OFF}\n" "${STD_TIME}ms" "${FT_TIME}ms" "${RATIO}%";
			elif (( $(echo "$RATIO < 2000" | bc -l) )); then
				printf "${FIELD_SIZE} ${FIELD_SIZE} ${RED}${FIELD_SIZE}${OFF}\n" "${STD_TIME}ms" "${FT_TIME}ms" "${RATIO}%";
			else
				printf "${FIELD_SIZE} ${FIELD_SIZE} ${HIGHLIGHTRED}${FIELD_SIZE}${OFF}\n" "${STD_TIME}ms" "${FT_TIME}ms" "${RATIO}%";
			fi
		done;
	else
		echo -e "${RED}Unrecognized argument${OFF}";
	fi
	echo -e "\n"
	exit 0
fi

rm -rf logs/*; rm -rf diff/* ; \
mkdir -p bin; mkdir -p logs; mkdir -p diff; mkdir -p objs ; \
printf "%-35s   ${FORMAT}" "TEST" "COMPILATION" "VALGRIND" "DIFF";
for f in ${testList[@]}; \
do
	printf '%-35s   ' $f;
	if ! make --no-print-directory SRC="${f}" NAME="${f::-4}" SET_LOCATION="${SET_LOC}" &>/dev/null;
	then
		if make --no-print-directory SRC="${f}" NAME="${f::-4}" ISFT=1 SET_LOCATION="${SET_LOC}" &>/dev/null;
		then
			printf "${RED}${FORMAT}${OFF}" "Should not compile" "?" "KO"; continue;
		else
			printf "${GREEN}${FORMAT}${OFF}" "OK" "OK" "OK"; continue;
		fi
	else
		if ! make --no-print-directory SRC="${f}" NAME="${f::-4}" ISFT=1 SET_LOCATION="${SET_LOC}" &>/dev/null;
		then
			printf "${RED}${FORMAT}${OFF}" "Does not compile" "?" "KO"; continue;
		else
			printf "${GREEN}${FIELD_SIZE}${OFF} " "OK";
		fi
	fi
	"bin/${f::-4}_std" 2>/dev/null >"logs/${f::-4}_std.log" | :
	(trap 'RET=1;' CHLD;
	if ! valgrind --leak-check=full --error-exitcode=1 "bin/${f::-4}_ft" &>/dev/null >"logs/${f::-4}_ft.log"  ;
	then
		if [ $RET -eq 1 ]
		then
			printf "${RED}${FIELD_SIZE}${OFF} " "KO"; RET=0;
		else
			printf "${RED}${FIELD_SIZE}${OFF} " "KO";
		fi
	else
		printf "${GREEN}${FIELD_SIZE}${OFF} " "OK";
	fi) 2>/dev/null
	if ! diff "logs/${f::-4}_std.log" "logs/${f::-4}_ft.log" >"diff/${f::-4}.log";
	then
		printf "${RED}${FIELD_SIZE}${OFF}\n" "KO";
	else
		printf "${GREEN}${FIELD_SIZE}${OFF}\n" "OK";
		rm -rf "diff/${f::-4}.log";
	fi
done;
echo -e "\n"
