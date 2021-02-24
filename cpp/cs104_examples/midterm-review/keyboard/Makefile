CC = g++
CPPFLAGS = -g -Wall -std=c++11
GTEST_LL = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread

test: keyboardTest
	 ./keyboardTest

keyboardTest: keyboardTest.o keyboard.o
	$(CC) $(CPPFLAGS) $^ $(GTEST_LL) -o $@

keyboardTest.o: keyboardTest.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

keyboard.o: keyboard.cpp keyboard.h
	$(CC) $(CPPFLAGS) -c $< -o $@

.phony: clean test

clean:
	-@rm -rf *.o keyboardTest

