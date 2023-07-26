<h1 align="center">
	Libft
</h1>

<p align="center">
    <img src="https://github.com/riceset/riceset/blob/main/42_badges/libftm.png" />
</p>

## Summary
> 42 school's first project, libft, is about learning how
> the standard functions of C programming work, by coding
> them from scratch and creating our very own library.

## Getting started
First, clone this repository and `cd` into it:

```zsh
$ git clone https://github.com/riceset/libft; cd libft
```

Compile the library with:

```zsh
$ make
```

Or use the following command to compile it with the bonus files:

```zsh
$ make bonus
```

## Usage
After running `make` a file called `libft.a` will be generated.
To use it, create a main function somewhere and include the `libft.h` header file into it.

```c
#include "libft.h"

int main(void)
{
    ft_putstr_fd("Hello World!\n", 1);
    return (0);
}
```

When compiling it, include the `libft.a` library with it.

```sh
cc main.c libft.a -I ./includes -o main
```

#### Output:

```sh
Hello World!
```

## Mandatory Functions
The mandatory functions of libft are either functions from the standard C library or other useful functions.
They are mostly useful for character, string and memory manipulation. These 34 mandatory functions must be done correctly to get a 100% grade.

Functions to check and manipulate characters:

- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint
- ft_toupper
- ft_tolower

Functions to manipulate strings:

- ft_strlen
- ft_strlcpy
- ft_strlcat
- ft_strchr
- ft_strrchr
- ft_strncmp
- ft_strnstr
- ft_substr
- ft_strjoin
- ft_strtrim
- ft_split
- ft_strmapi
- ft_striteri

Functions to manipulate memory:

- ft_calloc
- ft_memset
- ft_bzero
- ft_memcpy
- ft_memmove
- ft_memchr
- ft_memcmp
- ft_strdup

Functions for numbers:

- ft_atoi
- ft_itoa

Functions to write to a file descriptor

- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

## Bonus Functions
The bonus functions of libft deal with list manipulation. This part is worth an extra 25% to the final grade.

- ft_lstnew
- ft_lstadd_front
- ft_lstsize
- ft_lstlast
- ft_lstadd_back
- ft_lstdelone
- ft_lstclear
- ft_lstiter
- ft_lstmap

## Observations
Some functions weren't mentioned above.
