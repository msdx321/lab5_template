#include <stdio.h>
#include <string.h>

/**
 * This is a simple example of how to parse a command string.
 */
void parse_command_example()
{
    char command[] = "ls /bin/ /usr/bin/";
    printf("Parsing command: %s\n", command);

    printf("    Arguments: \n");

    char *token;
    for (token = strtok(command, " "); token != NULL; token = strtok(NULL, " "))
    {
        printf("        %s\n", token);
    }
}

void parse_command_exercise()
{
    char command[] = "ls -l ~ | grep msh | wc -l";
    printf("Parsing command: %s\n", command);

    /**
     * Do code here to parse the command string.
     */
}

int main()
{
    parse_command_example();
    parse_command_exercise();

    return 0;
}