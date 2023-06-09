#include "log.h"

void PrintLogLayout(const int level, const char* file, const int line)
{
#ifdef COLOR_LOGS
	printf("%s %s%s:%i %s", GetLogLevel(level), "\x1B[1;30m", file, line, "\x1B[0m");
#else
	printf("%s %s:%i ", GetLogLevel(level), file, line);
#endif
}

const char* GetLogLevel(const int level)
{
#ifdef COLOR_LOGS
	switch(level)
	{
		case 0:
			return "\x1B[1;30mDEBUG  "; // space so it looks symmetric
		case 1:
			return "\x1B[0;32mSUCCESS"; // same
		case 2:
			return "\x1B[0;34mINFO   "; // same
		case 4:
			return "\x1B[0;33mWARN   "; // same
		case 8:
			return "\x1B[0;31mERROR  "; // same
		case 16:
			return "\x1B[0;35mFATAL  "; // same
		default:
			return "";
	}
#else
	switch(level)
	{
		case 0:
			return "DEBUG  "; // space so it looks symetric
		case 1:
			return "SUCCESS"; // same
		case 2:
			return "INFO   "; // same
		case 4:
			return "WARN   "; // same
		case 8:
			return "ERROR  "; // same
		case 16:
			return "FATAL  "; // same
		default:
			return "";
	}
#endif
}
