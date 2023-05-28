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

TEST(System_test)
{
#ifdef _WIN32
	ASSERT_FALSE_MSG(1, "NOOOO!! IT IS WINDOWS");
#else
	ASSERT_TRUE(1);
#endif
}

TEST(Filework_test)
{
	FILE* file = fopen(".test.txt", "w");

	ASSERT_TRUE(file);

	fprintf(file, "Hello_there!");
	fclose(file);

	char buffer[256];
	file = fopen(".test.txt", "r");

	ASSERT_TRUE(file);

	fscanf(file, "%s", buffer);
	fclose(file);

	COMPARE_STRING(buffer, "Hello_there!");	
}

DEFINE_TESTS()

	ADD_TEST(Hello);
	ADD_TEST(Test1);
	ADD_TEST(Test2);
	ADD_TEST(Filework_test);
	ADD_TEST(System_test);

END_DEFINE_TESTS()

int main(const int argc, const char** argv)
{
	if(argc > 1)
	{
		if(!strcmp(argv[1], "-t")) CallTests();
	}
	
	return 0;
}

#undef _WIN32
