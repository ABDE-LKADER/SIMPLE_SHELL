#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define LINE_LEN 80
#define MAX_ARGS 64
#define MAX_ARG_LEN 16
#define MAX_PATHS 64
#define MAX_PATH_LEN 96
#define WHITESPACE " ,\t\n"