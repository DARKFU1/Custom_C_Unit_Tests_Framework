#include "general.h"
#include <unistd.h>


#include "tests.h"

TEST(Hello)
{
	sleep(2);

	ASSERT_TRUE_MSG(1, "Hello, world!");
}

TEST(Test1)
{
	sleep(1);

	ASSERT_TRUE_MSG(1, "Hello, world!");
}

TEST(Test2)
{
	sleep(4);

	ASSERT_TRUE_MSG(0, "Hello, world!");
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
