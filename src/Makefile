CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -Werror -O3 -march=native
TEST_LIBS = -lgtest
TEST_FLAGS = -std=c++17 -O3 -march=native
TEST_SRC = test/test.cc app/model/model.cc app/controller/controller.cc app/model/trainer/trainer.cc app/model/tester/tester.cc app/model/parser/parserWeights.cc app/model/neural_network/matrix/matrix_net.cc app/model/parser/parserData.cc app/model/neural_network/graph/graph_layer.cc app/model/neural_network/graph/graph_net.cc
OBJECTS = test.o

all: install open

install:
	rm -rf release;
	mkdir release;
	cp -r app/ release
	cd release; qmake s21_MLP.pro
	make -C release
	cd release; rm -rf *.o *.cpp *.cc *.h *.pro Makefile Model View Controller *.user

open:
	./release/s21_MLP.app/Contents/MacOS/s21_MLP

uninstall:
	rm -rf release

dvi:
	open dox/dox.md

dist: install
	mkdir archive; cd archive;
	[ -d release ] && cp -r release archive || true
	tar czf s21_MLP.tgz archive/
	rm -rf archive

test: $(TESTS)
	$(CC) $(TEST_FLAGS) $(TEST_SRC) $(TEST_LIBS) -o $(OBJECTS) -L.  --coverage
	./test.o

check:
	# find . -name "*.h" -o -name "*.cc" -o -name "*.ccp" | xargs clang-format --style=google -i
	find . -name "*.h" -o -name "*.cc" -o -name "*.ccp" | xargs clang-format --style=google -n

gcov_report:
	$(CC) --coverage $(TEST_SRC) $(TEST_FLAGS) $(TEST_LIBS) -o gсov_report.o
	./gсov_report.o
	lcov --ignore-errors mismatch -t $(OBJECTS) -o s21_MLP_tests.info --no-external -c -d .
	genhtml -o report s21_MLP_tests.info
	open ./report/index.html

leaks:
	leaks -atExit -- ./release/s21_MLP.app/Contents/MacOS/s21_MLP
clean:
	rm -rf test.o test_weights.txt *.gcda  *.gcno *.o *.info *.tgz report qmake.stash release archive build* *.user

rebuild: clean all

.PHONY: test