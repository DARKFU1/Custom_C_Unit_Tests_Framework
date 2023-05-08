This is a simple framework for writing your unit tests in C++.

How to add it to a project?

You have to copy only one file: `src/tests.h' and paste it in the file where you will define your tests.

---

NOTE: You should define tests in the same file, where you will call them, for example:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "tests.h"

...

void CallUnitTests()
{
	CALL_TESTS();
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

---

How to define tests?

It's simple you have to write TEST(name), where name of test is written without `"`, and cannot contain ONLY symbols, numbers and underscore.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
...

TEST(Test1)
{
	// test body
}

TEST(Test2)
{
	// test body
}

...
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Then you have to define it in a special block `DEFINE TESTS()` like this

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DEFINTE_TESTS()
	ADD_TEST(Test1)
	ADD_TEST(Test2)
END_DEFINE_TESTS()

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

That's it! You can call your tests now anywhere in this file using CALL_TESTS()

---

Now let's talk about how you check if everything's alright

there are some macroses:

`ASSERT_TRUE(value)` - if value isn's true, unit test is failed.
`ASSERT_TRUE_MSG(value)` - same as `ASSERT_TRUE` but if failed prints message
`ASSERT_FALSE(value)` - if value isn't false, unit test is failed.
`ASSERT_FALSE(value, msg)` - same as `ASSERT_FALSE` but if failed prints message
`COMPARE(value, expect)` - compares two values using '==', if false - fails.
`COMPARE_STRING(value, expect)` - compares two strings using `strcmp()`, if different - fails.
`COMPARE_FUNC(func, value, expect)` - compares two values using func(value, expect), if false - fails.

---

And, finally, full example of how should it look

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#include "general.h"

#include "tests.h"

TEST(Hello)
{
	// ...

	ASSERT_TRUE_MSG(smth, "Error message");
}

TEST(Test1)
{
	// ...

	ASSERT_TRUE_MSG(smth, "Error message");
}

TEST(Test2)
{
	// ...

	ASSERT_FALSE_MSG(smth, "Error_message");
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

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

this program calls tests if passsed '-t' when launched.
