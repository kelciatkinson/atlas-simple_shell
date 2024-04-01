# Simple Shell

## This is a UNIX command line interpreter.

- Usage: `shell`

## How to compile:
````gcc *.c -o shell````

## This shell will:

- Display a prompt and wait for the user to type a command. A command line
always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- This doesn't handle semi-columns, pipes, redirections or any other advanced
features.
- It only handles command lines made of one word. No arguments will be passed
to programs.
- If an executable cannot be found, it will print an error message and display
the prompt again.
- It handles errors.
- It properly handles the "end of file" condition (`Ctrl+D`)

## It does not:

- use the `PATH`
- implement built-ins
- handle special characters : `"`, `'`, `` ` ``, `\`, `*`, `&`, `#`
- move the cursor
- handle commands with arguments

## Installation steps:

This program requires no installation. Just execute the file.

## How to run Simple Shell in interactive mode:

Execute the compiled file shell:

````
./shell
````
<img width="860" alt="Example of how to use echo command" src="https://github.com/kelciatkinson/atlas-simple_shell/assets/106333133/9493c8de-ae96-4125-881b-038f4b60a6e8">

<img width="860" alt="Example of how to use ls command" src="https://github.com/kelciatkinson/atlas-simple_shell/assets/106333133/68bf12e0-c1a9-455b-b480-9bb9d6144b33">


## How to run Simple Shell in non-interactive mode:

Pass commands to shell via standard input using a pipe:

````
echo "ls -l" | ./shell
echo "env" | ./shell
````

## Flowchart

<img width="860" alt="Flowchart of Simple Shell" src="https://github.com/kelciatkinson/atlas-simple_shell/assets/106333133/8ddb2211-dacc-4c00-838c-393f3cc002d0">


## Credits

See the [AUTHORS](AUTHORS) file for more information.
