#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    struct stat buf;

    /**
     * Do codes here to setup the pipe
     */

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        // Child

        /**
         * Do codes here to redirect STDOUT to writer side of the pipe we just created.
         */

        // DON"T TOUCH
        if (fstat(STDOUT_FILENO, &buf) == -1)
        {
            perror("fstat");
            return 1;
        }

        // DON"T TOUCH
        if (!S_ISFIFO(buf.st_mode))
        {
            return 1;
        }

        /**
         * Do `execvp` here to execute `echo Hello!`
         */
    }
    else
    {
        // Parent

        /**
         * Do codes here to redirect STDIN to reader side of the pipe we just created.
         */


        /**
         * Do codes here to wait for the child process to finish.
         */

        // DON"T TOUCH
        if (fstat(STDIN_FILENO, &buf) == -1)
        {
            perror("fstat");
            return 1;
        }

        // DON"T TOUCH
        if (!S_ISFIFO(buf.st_mode))
        {
            return 1;
        }

        /**
         * Do `scanf` and `printf` here to read and write.
         */
    }

    return 0;
}