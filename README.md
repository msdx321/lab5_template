# Lab: Shell Design

## Intro

The current homework is to implement a shell, `msh`.
Lets play with the shell a little bit, and figure out what's going on.

```
$ ps aux | grep gparmer | wc -l
```

Replace your own user-name for `gparmer`.

## Pipeline

Before we jump into the actual exercies, how do you think the previous command got implemented?

- What `fork`s are being done?
- What `exec`s are being done?
- How is the `|` implemented?
- Where are `wait`s happening?

### Coding Exercise

Write code to do the following:

- Parent `fork`s a child process
- Use a `pipe` to redirect child's stdout to parent's stdin (note, in the shell this would be different)
- Use `execvp` to execute `echo Hello!` in the child process
- Do `wait` to wait for child to finish
- Use `scanf` in the parent process to read the child's output, and use `printf` to print it to the screen

Use `pipe.c` to begin.

### Extra Questions

- How does the shell implement *background* computations?
    For example, observe the difference between `$ sleep 2 ; ls` and `$ sleep 2 & ls` (`$ sleep 2 & ; ls` in `msh`'s syntax).

## Parsing

Module 0 of the shell requires parsing the input strings.

### Coding Exercise

See the `parsing.c` file for sample code that parsing a command and its argument using `strtok`.
Write code to print out the following:

- Print the commands in `ls -l ~ | grep msh | wc -l`.

Example outputs:

```bash
Parsing command: ls /bin/ /usr/bin/
    Arguments:
        ls
        /bin/
        /usr/bin/
Parsing command: ls -l ~ | grep msh | wc -l
    Sub-command: ls -l ~
        Arguments:
            ls
            -l
            ~
    Sub-command:  grep msh
        Arguments:
            grep
            msh
    Sub-command:  wc -l
        Arguments:
            wc
            -l
```
