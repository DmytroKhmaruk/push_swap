*This project has been created as part of the 42 curriculum by zorwa.*

# Libft

## Description

**Libft** is a custom C static library created as part of the 42 Common Core curriculum.

The goal of this project is to reimplement useful standard C library functions, understand how they work internally, and build a personal library that can be reused in future 42 projects.

The final output of the project is:

```text
libft.a
```

---

## Library Content

### Part 1 — Libc Functions

| Function     | Description                                |
|--------------|--------------------------------------------|
| `ft_isalpha` | Checks if a character is alphabetic        |
| `ft_isdigit` | Checks if a character is a digit           |
| `ft_isalnum` | Checks if a character is alphanumeric      |
| `ft_isascii` | Checks if a character is ASCII             |
| `ft_isprint` | Checks if a character is printable         |
| `ft_strlen`  | Returns the length of a string             |
| `ft_memset`  | Fills memory with a byte                   |
| `ft_bzero`   | Zeroes memory                              |
| `ft_memcpy`  | Copies memory without overlap handling     |
| `ft_memmove` | Copies memory safely, including overlap    |
| `ft_strlcpy` | Copies a string with size limit            |
| `ft_strlcat` | Concatenates a string with size limit      |
| `ft_toupper` | Converts a character to uppercase          |
| `ft_tolower` | Converts a character to lowercase          |
| `ft_strchr`  | Finds the first occurrence of a character  |
| `ft_strrchr` | Finds the last occurrence of a character   |
| `ft_strncmp` | Compares strings up to `n` characters      |
| `ft_memchr`  | Searches memory for a byte                 |
| `ft_memcmp`  | Compares two memory areas                  |
| `ft_strnstr` | Searches for a substring with length limit |
| `ft_atoi`    | Converts a string to an integer            |
| `ft_calloc`  | Allocates zero-initialized memory          |
| `ft_strdup`  | Duplicates a string using `malloc`         |

### Part 2 — Additional Functions

| Function        | Description                                                   |
|-----------------|---------------------------------------------------------------|
| `ft_substr`     | Creates a substring from a string                             |
| `ft_strjoin`    | Joins two strings into a new string                           |
| `ft_strtrim`    | Trims characters from the start and end                       |
| `ft_split`      | Splits a string by a delimiter                                |
| `ft_itoa`       | Converts an integer to a string                               |
| `ft_strmapi`    | Applies a function to each character and returns a new string |
| `ft_striteri`   | Applies a function to each character in place                 |
| `ft_putchar_fd` | Writes a character to a file descriptor                       |
| `ft_putstr_fd`  | Writes a string to a file descriptor                          |
| `ft_putendl_fd` | Writes a string followed by a newline                         |
| `ft_putnbr_fd`  | Writes an integer to a file descriptor                        |

### Part 3 — Linked List Functions

The linked list functions use this structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function          | Description                     |
|-------------------|---------------------------------|
| `ft_lstnew`       | Creates a new list node         |
| `ft_lstadd_front` | Adds a node at the front        |
| `ft_lstsize`      | Counts the number of nodes      |
| `ft_lstlast`      | Returns the last node           |
| `ft_lstadd_back`  | Adds a node at the back         |
| `ft_lstdelone`    | Deletes one node                |
| `ft_lstclear`     | Deletes an entire list          |
| `ft_lstiter`      | Applies a function to each node |
| `ft_lstmap`       | Creates a new mapped list       |

---

## Compilation

To compile the library:

```bash
make
```

This creates:

```text
libft.a
```

Common Makefile rules:

|  Rule               | Effect                            |
|---------------------|-----------------------------------|
| `make` / `make all` | Builds `libft.a`                  |
| `make clean`        | Removes object files              |
| `make fclean`       | Removes object files and `libft.a`|
| `make re`           | Rebuilds the library from scratch |

---
## Usage Example

Create a `main.c` file:

```c
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	printf("%zu\n", ft_strlen("Hello"));
	return (0);
}
```

Compile with:

```bash
cc -Wall -Wextra -Werror main.c libft.a
```

Run:

```bash
./a.out
```

Expected output:

```text
5
```

---

## Testing

During development, the project was checked with:

```bash
cc -Wall -Wextra -Werror
norminette -R CheckForbiddenSourceHeader *.c *.h
```

For allocation-failure testing:

```bash
valgrind --leak-check=full --show-leak-kind=all ./a.out
```

The project was reviewed for:

- 42 Norm compliance.
- Correct function prototypes in `libft.h`.
- Matching file names and function names.
- Correct handling of edge cases.
- Safe memory allocation and freeing.
- Avoiding unused includes.
- Correct behavior compared with standard C library functions where applicable.

---

## Technical Notes

- `ft_memcpy` does not handle overlapping memory, matching standard behavior.
- `ft_memmove` handles overlapping memory safely.
- Raw memory functions use `unsigned char *` when needed.
- `ft_split` frees previously allocated memory if allocation fails.
- `ft_calloc` checks for multiplication overflow before allocation.
- Linked list deletion functions correctly free node content and node memory.
- Helper functions are declared `static` when only used inside one source file.

---

## Resources

Useful references during the project:

- 42 Libft subject.
- 42 Norm version 4.1.
- Linux and BSD man pages.
- `norminette`.
- `valgrind`.
- Community Libft testers.

---

## AI Usage

AI was used as a learning and review assistant, not to blindly generate the final project.

It helped with:

- Reviewing functions step by step if it's worng it gives me a hint.
- Explaining edge cases and undefined behavior.
- Drafting and improving this README.
- wrote my personal notes.md for this project.

All code was reviewed, tested, and adjusted manually before submission.
