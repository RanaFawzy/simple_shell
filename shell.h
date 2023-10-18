#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for command is chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for read/write bufferr */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
/* 1 if using system getlines() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;
/* for convert_numb() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
/**
 * struct passinfo - contains pseudo-arguements to pass into function,.
 * allowing uniform prototype for function pointerr structt..
 * @arg: string generated from getline containing arguement,.
 * @argv:array of strings generated from argg..
 * @path:string path for the current command,..
 * @argc:argument counts..
 * @line_count:error counts..
 * @err_num:error code for exit()s..
 * @linecount_flag: if on count this line of input,.
 * @fname:program file name,..
 * @env: linked list local copy of environn,..
 * @environ: custom modified copy of environ from LL env,.
 * @history:history nodee.
 * @alias:alias nodee.
 * @env_changed:if environ was changed,.
 * @readfd:fd from which to read line input,.
 * @histcount:history line number county,..
 * @status:return status of last exec'd command.
 * @cmd_buf: address of pointer cmd_buf, on if chaining.
 * @cmd_buf_type: CMD_type ||, &&, ;
 */
typedef struct passinfo
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;
int err_num;
int linecount_flag;
char *fname;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
int status;
char **cmd_buf; /* pointer cmd ; chain bufferr, for memorry mangement */
int cmd_buf_type; /* CMD_type ||, &&, ; */
int readfd;
int histcount;
} info_t;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

