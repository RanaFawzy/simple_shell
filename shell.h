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
/**
 * @num: the numb field..
 * struct liststr - singly linked lists,..
 * @next: points to the next nodes..
 * @str: string
 */
typedef struct liststr
{
int num;
char *str;
struct liststr *next;
} list_t;
/**
 * @type:builtin command flagg,,.
 * struct builtin - containss  builtin string and related function,.
 * @func:functionn,.
 */
typedef struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_table;
/* toem_first_builtin.c */
int interactive(info_t *);
int _myexit(info_t *);
int _mycd(info_t *);
/* toem_environ_func.c */
int _putsfd(char *str, int fd);
int _myunsetenv(info_t *);
int _myenv(info_t *);
char *_getenv(info_t *, const char *);
/* toem_err2_function.c */
void print_error(info_t *, char *);
int _erratoi(char *);
char *convert_number(long int, int, int);
int print_d(int, int);
/*toem_getline_function.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
/* toem_getinfo_function.c */
void set_info(info_t *, char **);
void clear_info(info_t *);
void free_info(info_t *, int);
/* toem_simple_atoi.c */
int _isalpha(int);
int is_delim(char, char *);
int _atoi(char *);
int _myhelp(info_t *);
/* toem_second_builtin.c */
int _myhistory(info_t *);
int _myalias(info_t *);
/* toem_err_function.c */
int _mysetenv(info_t *);
int populate_env_list(info_t *);
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
/* toem_simple_exits.c */
void remove_comments(char *);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char *_strncpy(char *, char *, int);
/* toem_getenviron.c */
int _setenv(info_t *, char *, char *);
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
/* toem_history_function.c */
int write_history(info_t *info);
char *get_history_file(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

