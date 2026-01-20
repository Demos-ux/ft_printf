*This project has been created as part of the 42 curriculum by dsisli.*

# ft_printf

## Description
The goal of this project is to recreate the `printf` function from the C standard library. `ft_printf` is a function that formats and prints data to the standard output. This project provides a deep understanding of variadic functions in C (`stdarg.h`), parsing algorithms, and string formatting, which are essential skills for future C programming tasks within the 42 curriculum.

## Instructions

### Compilation
The project follows the standard 42 Makefile structure. To compile the library `ft_printf.a`, simply run:

```sh
make
```

To remove object files:
```sh
make clean
```

To remove object files and the library:
```sh
make fclean
```

To recompile everything:
```sh
make re
```

### Execution
To use the library in your project, include the header `ft_printf.h` and link against `ft_printf.a`.

**Example `main.c`:**
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "42");
    ft_printf("Hexadecimal: %x\n", 255);
    return (0);
}
```

**Compiling with your main:**
```sh
cc main.c ft_printf.a -o my_program
./my_program
```

## Algorithm and Data Structure

### Data Structure
The project uses a custom structure `t_format` to manage the state of the printing operation.

```c
typedef struct s_format
{
	va_list ap;      // Variadic argument list
	char    *format; // The format string
	int     i;       // Current index in the format string
	int     total;   // Total number of characters printed
} t_format;
```

**Justification**: This specific structure avoids passing multiple individual parameters (like the current index or total count) recursively or to every helper function. It centralizes the state, making the code cleaner, more modular, and easier to maintain.

### Algorithm
The main `ft_printf` function iterates through the format string character by character.

1.  **State Initialization**: The `t_format` structure is initialized with the variable argument list and the format string.
2.  **Parsing Loop**: The function iterates through the string:
    *   **Standard Characters**: If the current character is not `%`, it is printed immediately to the output using `write`, and the total character count is incremented.
    *   **Conversion Specifications**: If a `%` is encountered, the function delegates processing to `ft_formatchecker`.
3.  **Dispatch Logic**: `ft_formatchecker` analyzes the character immediately following the `%` (the specifier) and calls the appropriate helper function (e.g., `ft_putstr`, `ft_putnbr`, `ft_puthex`).
4.  **Error Handling**: If an invalid specifier is encountered, the behavior fails gracefully (returning 0 or ignoring it).
5.  **Return**: Finally, the function returns the total number of characters printed, complying with the standard `printf` behavior.

## Resources

### References
*   [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html) - Official documentation of the standard printf function.
*   [stdarg.h documentation](https://en.cppreference.com/w/c/variadic) - Reference for C variadic functions.
*   [42 Norm](https://github.com/42School/norminette) - The coding standard followed for this project.

### AI Usage
Artificial Intelligence tools were used in this project for the following tasks:
*   **Code Compliance**: Checking code against the 42 Norm and suggesting formatting fixes (e.g., indentation, line breaks).
*   **Refactoring**: Optimizing control flow structures, specifically moving from array-based function dispatch to `if/else` logic to meet Norm requirements.
*   **Documentation**: Generating the initial structure and content of this `README.md` file based on specific project requirements.

