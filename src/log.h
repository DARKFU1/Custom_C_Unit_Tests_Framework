#ifndef LOG_H
#define LOG_H
#include <stdarg.h>
#include "general.h"


#define DEBUG_LEVEL 	0
#define SUCCESS_LEVEL	1
#define LOG_LEVEL 	2
#define WARN_LEVEL 	4
#define ERROR_LEVEL 	8
#define FATAL_LEVEL 	16

void PrintLogLayout(const int level, const char* file, const int line);
const char* GetLogLevel(const int level);

#define log_debug(...)	PrintLogLayout(DEBUG_LEVEL, __FILE__, __LINE__); 	printf(__VA_ARGS__); printf("\n");
#define log_success(...)PrintLogLayout(SUCCESS_LEVEL, __FILE__, __LINE__);	printf(__VA_ARGS__); printf("\n");
#define log_log(...)	PrintLogLayout(LOG_LEVEL ,  __FILE__, __LINE__);	printf(__VA_ARGS__); printf("\n");
#define log_warn(...)	PrintLogLayout(WARN_LEVEL,  __FILE__, __LINE__);	printf(__VA_ARGS__); printf("\n");
#define log_error(...)	PrintLogLayout(ERROR_LEVEL, __FILE__, __LINE__);	printf(__VA_ARGS__); printf("\n");
#define log_fatal(...)	PrintLogLayout(FATAL_LEVEL, __FILE__, __LINE__);	printf(__VA_ARGS__); printf("\n");

#endif
