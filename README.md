## 0x19. C - Stacks, Queues - LIFO, FIFO

# Monty Interpreter 🖥️

This Monty interpreter processes Monty ByteCodes files and executes commands accordingly. It operates in both stack and queue modes, depending on the specified command.

## Overview

The project comprises several files and functionalities:

### Files
- `monty.h`: Header file containing structure definitions, function prototypes, and global variables.
- `monty.c`: Main file implementing the interpreter's entry point and file reading functionality.
- `processing_functions.c`: Contains core functions for parsing, executing, and managing the stack/queue.
- `add.c`, `div.c`, `mul.c`, `sub.c`: Operations to perform addition, division, multiplication, and subtraction.
- `printers.c`: Functions to print characters (`_pchar`) and strings (`_pstr`) from the stack.
- `circles.c`: Operations for stack rotation (`_rotl` and `_rotr`) and swapping elements (`_swap`).
- `pop.c`: Functionality to remove elements from the stack (`_pop`).
- `nop.c`: A function that does nothing (`_nop`).

### Functionality Highlights
- **📖 Reader**: Reads content from a file, tokenizes commands, and executes them.
- **🔍 Parser**: Tokenizes commands and prepares them for execution.
- **🚀 Executor**: Executes the specified command from a set of supported operations.
- **📚 Stack/Queue Handling**: Manages stack and queue modes based on commands.
- **➕ Arithmetic Operations**: Addition, subtraction, multiplication, division with error handling for stack size and division by zero.
- **🖨️ Printing Functions**: Printing characters and strings, checking range and stack status.
- **🔄 Stack Manipulation**: Rotating elements, swapping, and removing top elements from the stack.

### Logic and Flow 🧠
The Monty interpreter follows a logical sequence:

- **📖 Reader**: Reads file content, passes it to the parser.
- **🔍 Parser**: Tokenizes commands, prepares for execution, and calls the executor.
- **🚀 Executor**: Matches and executes the command with associated functions.

The logic ensures proper handling of stack operations, error checks, and execution based on the command provided.

> Explore each function for detailed logic and implementation.


## Usage

### Command Usage

| Command  | Description            |
|----------|------------------------|
| `monty file` | Execute Monty with a specified file (Replace `file` with your Monty ByteCode file) |
| `push <int>` | Push an integer onto the stack |
| `pall`       | Print all values on the stack |
| `pint`       | Print value at the top of the stack |
| `pop`        | Remove top element of the stack |
| `swap`       | Swap top two elements of the stack |
| `nop`        | Does nothing |
| `add`        | Add top two elements of the stack |
| `sub`        | Subtract top element from the second top element |
| `mul`        | Multiply top two elements of the stack |
| `div`        | Divide second top element by top element |
| `mod`        | Computes remainder of division of second top element by top element |
| `pchar`      | Print the character at the top of the stack |
| `pstr`       | Print the string starting at the top of the stack |
| `rotl`       | Rotate stack to the top |
| `rotr`       | Rotate stack to the bottom |
| `stack`      | Set format to stack (LIFO) |
| `queue`      | Set format to queue (FIFO) |


## Compilation & Execution

### Prerequisites
- **GCC** installed
- **Linux** or **Unix** system

### Compilation
To compile the Monty Interpreter, navigate to the project directory and use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

### Execution

Run the interpreter with a Monty ByteCode file:

```
./monty file.m
```

## Contributions and License 📝
created by: [Hiba A. Mohamed](https://github.com/hiba-emording). (⌐■_■)

*Happy coding!* 🌟
