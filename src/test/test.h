#ifndef TEST_H
#define TEST_H 

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "../utils/defs.h"
#include "../utils/util.h"
#include "../board.h"

class Test {
	public:
		static int mainTest();

	private:
		void testBoardIsAttacked();

};

#endif