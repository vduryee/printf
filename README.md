*This project has been created as part of the 42 curriculum by vduryee.*

# ft_printf

## Description

`ft_printf` is a from-scratch reimplementation of the C standard library's `printf`, built as part of the 42 common core. It is compiled into a static library, `libftprintf.a`, that can be linked into other projects.

The function prints formatted output to standard output and returns the number of characters written, like the original:

```c
int ft_printf(const char *format, ...);
```

### Supported conversions

| Specifier | Output                                       |
|-----------|----------------------------------------------|
| `%c`      | A single character                           |
| `%s`      | A string (`(null)` if the pointer is NULL)   |
| `%p`      | A pointer in hexadecimal                     |
| `%d`      | A signed decimal integer                     |
| `%i`      | A signed decimal integer                     |
| `%u`      | An unsigned decimal integer                  |
| `%x`      | An unsigned integer in lowercase hexadecimal |
| `%X`      | An unsigned integer in uppercase hexadecimal |
| `%%`      | A literal percent sign                       |

### Project structure

```
.
├── Makefile
├── ft_printf.h         # prototypes and includes
├── ft_printf.c         # ft_printf and conversion dispatch
└── ft_printf_utils.c   # printing helpers (char, string, numbers, hex)
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

## How it works

| Step | What happens |
|:---:|---|
| 1 | `va_start` opens the list of extra arguments. |
| 2 | The format string is read character by character. |
| 3 | Normal characters are written as they are. |
| 4 | When a `%` is found, the next character tells which conversion to apply. |
| 5 | The matching helper takes the next argument with `va_arg` and prints it. |
| 6 | Every printed character is counted along the way. |
| 7 | `va_end` closes the list, and the total count is returned. |

---

## Resources

- `man 3 printf`, `man 3 stdarg`
- [Variadic functions in C](https://www.ibm.com/docs/en/i/7.5.0?topic=v-access-function-arguments-va-arg)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)

### Use of AI

AI (Claude) was used as a learning aid for these tasks only:

- **Hexadecimal conversion:** explaining how it works (division by 16 versus bit shifting) and how to count the printed characters.
- **Code review:** pointing out bugs in my counting logic, the `-Wtype-limits` compile error and the missing prototype in the header. I fixed them myself.
- **Documentation:** helping to draft the `Makefile` and this README, which I then checked and edited.

The implementation of `ft_printf` and its helpers was written and tested by me.