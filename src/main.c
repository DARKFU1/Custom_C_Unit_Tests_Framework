#include "general.h"

#define DEFINE_TESTS() void __define_tests__() {\
	int __tests_iterator = 0;
#define END_DEFINE_TESTS() }
#define ADD_TEST(name) __tests[__tests_iterator].test_function = __test_##name;\
								 __tests_iterator++;

#define MAX_TEST_COUNT 4000

typedef	struct 
{
	const int state;
	const char* name;
	int (*test_function)();
}_test_;

static _test_ __tests[MAX_TEST_COUNT];

#define TEST(name); int __test_##name()

#define CALL_TESTS() __define_tests__();\
	for(int i = 0; (__tests[i]).test_function != NULL; ++i)\
	{\
		__tests[i].test_function();\
	}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TEST(Hello)
{
	log_log("Hello");
	return 0;
}

TEST(Test1)
{
	log_log("This is test1");
	return 0;
}

TEST(Test2)
{
	log_log("This is test2");
	return 0;
}

DEFINE_TESTS()

	ADD_TEST(Hello);
	ADD_TEST(Test1);
	ADD_TEST(Test2);

END_DEFINE_TESTS()

int main(const int argc, const char** argv)
{
	if(argc > 1)
	{
		if(!strcmp(argv[1], "-t")) CALL_TESTS();
	}
	
	return 0;
}
