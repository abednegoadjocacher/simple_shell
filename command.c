#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
/**
 * exe_command - To execute commands
 * @command: A pointer
 * Return: nothing
 */
void exe_command(char *command)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	if (execlp(command, command, NULL) == -1)
	{
	perror("simple_shell");
	exit(EXIT_FAILURE);
	}
	}
	else if (pid < 0)
	{
	perror("simple_shell");
	}
	else
	{
	do {
	wpid = waitpid(pid, &status, WUNTRACED);
	}
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
/**
 * main - Entry point
 * Return: 0
 */
int main(void)
	{
	char input[MAX_COMMAND_LENGTH];

	while (1)
	{
	printf("simple_shell> ");
	if (fgets(input, sizeof(input), stdin) == NULL)
	{
	printf("\n");
	break;
	input[strcspn(input, "\n")] = '\0';
	if (strlen(input) > 0)
	{
	exe_command(input);
	}
	}
	return (0);
	}
	}
