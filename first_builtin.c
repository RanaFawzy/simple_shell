#include "shell.h"

/**
 * interactive - function return true
 * @info: add of structor
 * Return: 1 (success)
 */


int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 * _myexit - function to exit the shell
 * @info: Struct of potential argue which use to maintaining prototype
 *
 * Return: exits
 *        0  (info.argv[0] != "exit")
 */

int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* when an exit arguement is found*/
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}



/**
 * _mycd - function used to change directory of the process
 * @info: Stuct of potential argue used to maintain prototype
 *
 * Return: 0 (success)
 */

int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024))
	}
	return (0);
}
