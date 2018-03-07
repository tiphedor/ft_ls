# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    999_runtest.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/02 12:27:11 by msteffen          #+#    #+#              #
#    Updated: 2018/03/05 12:26:39 by msteffen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

##### COLORS
red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`
count=0


###### Ensuring project is compiled
echo "== ft_ls unit tests"
echo -n "== Building ft_ls... "
make &> /dev/null
if [ $? -eq 0 ]; then
    echo -e "${green}[OK]${reset}\n"
else
    echo -e "${red}[FAIL]${reset}"
	exit
fi


cd unit_tests

###### Cleaning up
rm -rf ft_ls
rm -rf ../unit_tests_tmp
mkdir ../unit_tests_tmp
cp ../ft_ls .

###### Columns headers

echo -ne "\t\ttest_name\tstderr\tstdout\treturn value\n"

##
## literal_unit_test	runs a unit test on ft_ls
##
## literal_unit_test will run both the system's ls and the supplied ft_ls functions,
## and then compare their stdout, stderr and return value.
## The first argument of literal_unit_test is is passed to both functions, such as:
##
##		literal_unit_test "-rt test_path"
##	Will run ./ft_ls -rt test_path and ls -rt test_path
##
function literal_unit_test {
	echo -ne "\t$1\t\t"

	rm -rf ../unit_tests_tmp/*

	ls $2 2>> ../unit_tests_tmp/og_error 1>> ../unit_tests_tmp/og_out
	lsret=$?
	./ft_ls $2 2>> ../unit_tests_tmp/ft_error 1>> ../unit_tests_tmp/ft_out
	ftret=$?

	# Replacing `ft_ls` with `ls`
	sed -i '.bk' 's/ft_ls/ls/g' ../unit_tests_tmp/ft_error && rm ../unit_tests_tmp/ft_error.bk

	# Replacing ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1 with lRart
	sed -i '.bk' 's/ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1/lRart/g' ../unit_tests_tmp/og_error && rm ../unit_tests_tmp/og_error.bk

	diff ../unit_tests_tmp/ft_error ../unit_tests_tmp/og_error &> /dev/null
	if [ $? -eq 0 ]; then
	    echo -ne "${green} [OK]${reset}\t"
	else
	    echo -ne "${red} [KO]${reset}\t"
	fi

	diff ../unit_tests_tmp/ft_out ../unit_tests_tmp/og_out &> /dev/null
	if [ $? -eq 0 ]; then
	    echo -ne "${green} [OK]${reset}\t"
	else
	    echo -ne "${red} [KO]${reset}\t"
	fi

	if [ $lsret -eq $ftret ]; then
		echo -ne "${green}    [OK]${reset}"
	else
		echo -ne "${red}    [KO]${reset}"
	fi


	echo -ne "\n"
}

##
## xargs_unit_test	runs a unit test on ft_ls
##
## xargs_unit_test will run both the system's ls and the supplied ft_ls functions,
## apply xargs to both output, and then compare their stdout, stderr and return value.
## The first argument of xargs_unit_test is is passed to both functions, such as:
##
##		xargs_unit_test "-rt test_path"
##	Will run ./ft_ls -rt test_path | xargs and ls -rt test_path | xargs
##
function xargs_unit_test {
	echo -ne "\t$1\t\t"

	rm -rf ../unit_tests_tmp/*

	ls $2 2>> ../unit_tests_tmp/og_error 1>> ../unit_tests_tmp/og_out
	lsret=$?
	./ft_ls $2 2>> ../unit_tests_tmp/ft_error 1>> ../unit_tests_tmp/ft_out
	ftret=$?

	cat ../unit_tests_tmp/og_out | xargs >> ../unit_tests_tmp/og_out_x && rm ../unit_tests_tmp/og_out && mv ../unit_tests_tmp/og_out_x ../unit_tests_tmp/og_out
	cat ../unit_tests_tmp/ft_out | xargs >> ../unit_tests_tmp/ft_out_x && rm ../unit_tests_tmp/ft_out && mv ../unit_tests_tmp/ft_out_x ../unit_tests_tmp/ft_out

	# Replacing `ft_ls` with `ls`
	sed -i '.bk' 's/ft_ls/ls/g' ../unit_tests_tmp/ft_error && rm ../unit_tests_tmp/ft_error.bk

	# Replacing ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1 with lRart
	sed -i '.bk' 's/ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1/lRart/g' ../unit_tests_tmp/og_error && rm ../unit_tests_tmp/og_error.bk

	diff ../unit_tests_tmp/ft_error ../unit_tests_tmp/og_error &> /dev/null
	if [ $? -eq 0 ]; then
	    echo -ne "${green} [OK]${reset}\t"
	else
	    echo -ne "${red} [KO]${reset}\t"
	fi

	diff ../unit_tests_tmp/ft_out ../unit_tests_tmp/og_out &> /dev/null
	if [ $? -eq 0 ]; then
	    echo -ne "${green} [OK]${reset}\t"
	else
	    echo -ne "${red} [KO]${reset}\t"
	fi

	if [ $lsret -eq $ftret ]; then
		echo -ne "${green}    [OK]${reset}"
	else
		echo -ne "${red}    [KO]${reset}"
	fi


	echo -ne "\n"
}


##### TEST SPECS


literal_unit_test "invalid_args_0" "-K"
literal_unit_test "invalid_args_1" "-lRart -K"
literal_unit_test "invalid_args_2" "-lRart -llllll -lrlrlrlrarlar -K"
literal_unit_test "invalid_args_3" "------Q"
literal_unit_test "invalid_args_4" "---R"
literal_unit_test "invalid_args_5" "--R"

literal_unit_test "valid_l_0" "-l"
literal_unit_test "valid_l_1" "-llllllllllllllllll"


xargs_unit_test "valid_1folder_0" "tests_0"
xargs_unit_test "valid_1folder_1" "tests_1"
xargs_unit_test "valid_1folder_2" "tests_2"

xargs_unit_test "valid_2folder_0" "tests_0 tests_1"
xargs_unit_test "valid_2folder_1" "tests_1 tests_2"

xargs_unit_test "valid_3folder_0" "tests_0 tests_1 tests_2"

xargs_unit_test "valid_1file_0" "tests_0/a"
xargs_unit_test "valid_2files_0" "tests_0/a tests_0/b"
xargs_unit_test "valid_26files_0" "tests_0/a tests_0/b tests_0/c tests_0/d tests_0/e tests_0/f tests_0/g tests_0/h tests_0/i tests_0/j tests_0/k tests_0/l tests_0/m tests_0/n tests_0/o tests_0/p tests_0/q tests_0/r tests_0/s tests_0/t tests_0/u tests_0/v tests_0/w tests_0/x tests_0/y tests_0/z"
xargs_unit_test "valid_wildcard0" "tests_0/*"
xargs_unit_test "valid_wildcard1" "tests_1/*"
xargs_unit_test "valid_wildcard2" "tests_2/*"
xargs_unit_test "valid_wildcard3" "tests_0/* tests_1/* tests_2/*"
xargs_unit_test "valid_wildcard4" "*"

xargs_unit_test "valid_mixed0" "tests_0 tests_0/a tests_0/b tests_0/*"

xargs_unit_test "valid_folders_0" "tests_3"
xargs_unit_test "valid_folders_0" "tests_3/*"











#rm -rf ../unit_tests_tmp
