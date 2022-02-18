
# BunnySH

  BunnySH is an complete shell created in C. It's an Ecole 89's project.

## Project goal

  My job will be to make a command line software.

  To do this work, I needed to use what is called the environment. The environment is a set of keys associated with values. You can observe this environment in your shell by typing the "env" command. To get this environment into your program… you will need to have the full definition of main. That definition is here:

`int main(int argc, char *argv[], char **env);`

  The third parameter is the environment. It is a NULL pointer terminated string array. The environment strings look like this:

`NAME_OF_VALUE=VALUE`

  Why did I need the environment? Because it contains the PATH variable, consisting of a series of folders separated by the ':' character. These folders are the ones used when you type a command to find the program that matches it. Example: when you type “ls”, your shell looks in the path and finds… /bin/ which contains the program “ls”, and therefore it executes “/bin/ls”. In addition, it will pass it the parameters that you have typed.

  I know how to use fork. To be able to call another program, however, I need another additional system call: execve. This system call transforms the current process, it becomes the program you want to call.

  The program is called bsh. It prints a "&> " prompt before attempting to read from standard input.

  If what it reads starts with '.' or '/', your command line should attempt to run the program whose address is written. For example "./a.out" will run the program a.out.

  If what it reads starts with something else, then your program will look in the PATH variable for which folder contains the command, and it executes the command.

  Each time, the parameters will be passed. The user can exit by typing the command "exit", which is in your shell directly, it is "built-in", "nested". It is not an external program. The program also exits on CTRL-C or CTRL-D.

  The user should also be able to enter the "cd" command which is also part of the shell itself. You can use the chdir function to implement it. Don't forget to update the PWD environment variable if it exists.

  Typing the $ symbol followed by a name instructs the shell to replace the set with the value of the environment variable whose name was specified.
