GCC=gcc
STD_FLAGS=-Wall -Werror -Wextra -std=c11
LIB=-lcheck
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

TEST_FOLDER=tests/
FUNCTIONS_FOLDER=functions/

LIB_NAME = s21_math.a

UNIT_TEST=-o unit_test
GCOV_TEST=-o gcov_test

ifeq ($(shell uname), Linux)
 LIB +=-lpthread -lrt -lsubunit -lm
endif


all: s21_math.a test

s21_math.a:
	${GCC} ${STD_FLAGS} -c ${wildcard ${FUNCTIONS_FOLDER}*.c} 
	ar rc ${LIB_NAME} *.o
	ranlib ${LIB_NAME}
	rm *.o

clean: 
	rm -rf report a.out unit_test gcov_test *.gcda *.gcno *.info s21_math.a

test: s21_math.a
	${GCC} ${STD_FLAGS} ${LIB_NAME} ${UNIT_TEST} ${wildcard ${TEST_FOLDER}*.c} ${LIB}
	./unit_test
	rm s21_math.a
	rm unit_test
	
gcov_report: s21_math.a
	${GCC} ${STD_FLAGS} ${GCOV_FLAGS} --coverage ${LIB_NAME} ${GCOV_TEST} ${wildcard ${TEST_FOLDER}*.c} ${LIB}
	./gcov_test
	lcov -t "stest" -o s21_test.info -c -d . -no-external
	genhtml -o report s21_test.info
	open ./report/index.html
	rm gcov_test


check_clang_format:
	mv ../materials/linters/.clang-format .
	clang-format -n functions/*.c
	clang-format -n tests/*.c
	clang-format -n tests/*.h
	clang-format -n s21_math.h
	mv .clang-format ../materials/linters/

fix_clang_format:
	mv ../materials/linters/.clang-format .
	clang-format -i functions/*.c
	clang-format -i tests/*.c
	clang-format -i tests/*.h
	clang-format -i s21_math.h
	mv .clang-format ../materials/linters/