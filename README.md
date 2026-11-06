*This project has been created as part of the 42 curriculum by vduryee.*

# ft_printf

## Description

`ft_printf` is a from-scratch reimplementation of the C standard library's `printf`, built as part of the 42 common core. It is compiled into a static library, `libftprintf.a`, that can be linked into other projects.

The function prints formatted output to standard output and returns the number of characters written, like the original:

```c
int ft_printf(const char *format, ...);
```

### Supported conversions

| Specifier | Output                                      |
|-----------|---------------------------------------------|
| `%c`      | A single character                          |
| `%s`      | A string (`(null)` if the pointer is NULL)  |
| `%p`      | A pointer in hexadecimal                    |
| `%d`      | A signed decimal integer                    |
| `%i`      | A signed decimal integer                    |
| `%u`      | An unsigned decimal integer                 |
| `%x`      | An unsigned integer in lowercase hexadecimal |
| `%X`      | An unsigned integer in uppercase hexadecimal |
| `%%`      | A literal percent sign                      |

### How it works

- `ft_printf` walks through the format string with `va_list` (`<stdarg.h>`). Normal characters are written as they are; when a `%` is found, the next character selects a conversion.
- Every helper returns the number of characters it printed, and `ft_printf` adds them up for its return value.

### Project structure

```
.
├── Makefile
├── ft_printf.h        # prototypes and includes
├── ft_printf.c        # ft_printf and conversion dispatch
└── ft_print_utils.c   # printing helpers (char, string, numbers, hex)
```

## Instructions

### Build

```sh
make        # builds libftprintf.a
```
```sh
make clean  # removes object files
```
```sh
make fclean # removes object files and libftprintf.a
```
```sh
make re     # fclean + all
```

The library is compiled with `cc -Wall -Wextra -Werror`.

### Use it in your own code

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, you are %d years old\n", "world", 42);
	ft_printf("Hex: %x / %X, pointer: %p\n", 255, 255, &main);
	return (0);
}
```

Compile and link against the library:

```sh
cc main.c libftprintf.a -o test
./test
```

A good way to test is to compare the output and the return value of `ft_printf` against the real `printf` for the same format string.

## Resources

- `man 3 printf`, `man 3 stdarg`
- [Variadic functions in C](https://www.ibm.com/docs/en/i/7.5.0?topic=v-access-function-arguments-va-arg)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)

### Use of AI

AI was used as a learning aid, to explain how hexadecimal conversion works (with and without bit shifting), to help review the character-counting logic, and to help write the Makefile and this README. All the code was written and tested by me.
