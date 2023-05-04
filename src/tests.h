#ifndef __TESTS_H
#define __TESTS_H

#define MAX_TEST_COUNT 4000

/*------------------------------------------------------------------------------
 * 			USER CONFIG AREA ABOVE THIS LINE
 *----------------------------------------------------------------------------*/

#ifdef COLOR_TESTS
	#define __RED_CL "\033[0;31m"
	#define __GRN_CL "\033[0;32m"
	#define __BLU_CL "\033[0;34m"
	#define __CYN_CL "\033[0;36m"
	#define __RES_CL "\033[0m"
	
	#define __B_RED_CL "\033[1;31m"
	#define __B_GRN_CL "\033[1;32m"
	#define __B_BLU_CL "\033[1;34m"
	#define __B_CYN_CL "\033[1;36m"

	#define __BR_BLK_CL "\033[0;90m"
#else
	#define __RED_CL ""
	#define __GRN_CL ""
	#define __BLU_CL ""
	#define __CYN_CL ""
	#define __RES_CL ""
	
	#define __B_RED_CL ""
	#define __B_GRN_CL ""
	#define __B_BLU_CL ""
	#define __B_CYN_CL ""

	#define __BR_BLK_CL ""

#endif // COLOR_TESTS


/* defining tests */

#define DEFINE_TESTS() void __define_tests__() {\
	int __tests_iterator = 0;
#define END_DEFINE_TESTS() }
#define ADD_TEST(name) __tests[__tests_iterator].test_function = __test_##name;\
			__tests[__tests_iterator].__name = #name; \
			 __tests_iterator++;
#define TEST(name); void __test_##name() // in the end we have __test_name()

// tests struct
typedef	struct 
{
	int state;
	const char* __name;
	void (*test_function)();
}_test_;

// main tests data
static _test_ __tests[MAX_TEST_COUNT];
static _test_* _current_test;
static const char* __error_msg;

// calling tests
#define CALL_TESTS() __define_tests__(); \
	for(int i = 0; (__tests[i]).test_function != NULL; ++i) \
	{ \
		__error_msg = NULL;\
		printf("\r");\
		_current_test = &__tests[i]; \
		__tests[i].state = 1; \
		\
		printf("%sRunning test:%s %s... ",__B_BLU_CL, __RES_CL, _current_test->__name); \
		fflush(stdout); \
		__tests[i].test_function(); \
		if(!__tests[i].state) /* if failed */ \
		{ \
			if(__error_msg != NULL ) {printf("%s[ FAIL ]%s %s%s%s\n",\
					__B_RED_CL,\
					__RES_CL,\
					__BR_BLK_CL,\
				       	__error_msg,\
					__RES_CL);}\
			else { printf("%s[ FAIL ]%s \n", __B_RED_CL, __RES_CL); } \
		} \
		else\
		{\
			printf("%s[ PASS ]%s\n", __B_GRN_CL, __RES_CL); \
		}\
	} 

/* check methods ( assertion methods ) */

#define ASSERT_TRUE_MSG(value, msg) if(!value) { _current_test->state = 0;\
					__error_msg = msg; \
					return; }
#define ASSERT_TRUE(value) if(!value) { _current_test->state = 0; return; }

#define ASSERT_FALSE_MSG(value, msg) ASSERT_TRUE_MSG(!value, msg)
#define ASSERT_FALSE(value) ASSERT_TRUE(!value)

#define COMPARE_FUNC(func, value, expect) ASSERT_TRUE( func( value, expect ) )
#define COMPARE_STRING(value, expect) ASSERT_TRUE(!strcmp(value, expect))
#define COMPARE(value, expect) ASSERT_TRUE(value == expect)

#endif // __TESTS_H
