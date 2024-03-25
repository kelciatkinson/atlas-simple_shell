# This is a UNIX command line interpreter.

- Usage: `shell`

## This shell will:

- Display a prompt and wait for the user to type a command. A command line
always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- This doesn't handle semi-columns, pipes, redirections or any other advanced
features.
- It onlh hanldes command lines made of one word. No arguments will be passed
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

This program requires no installation. Just exeute the file.

## Credits

See the [AUTHORS](AUTHORS) file for more information.
