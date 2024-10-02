# ft_printf

## Project Description

The ft_printf project aims to recreate the functionality of the standard C printf function. This exercise will enhance your understanding of variadic functions in C and require you to manage memory efficiently.

## Table of Contents

- [Introduction](#introduction)
- [Common Instructions](#common-instructions)
- [Mandatory Part](#mandatory-part)
- [Compilation](#compilation)
- [Usage](#usage)

## Introduction

In this project, you will implement ft_printf, a function that behaves similarly to printf but with certain limitations and additional features as specified in the requirements. This exercise is of moderate difficulty and serves as a practical application of variadic functions and string manipulation in C.

## Common Instructions

- Your project must be written in C.
- Ensure compliance with the Norm.
- Functions should handle edge cases gracefully to avoid unexpected crashes.
- Manage memory carefully to prevent leaks.
- Include a Makefile with necessary rules.
- Create and use test programs for validation.

## Mandatory Part

### Program Name

libftprintf.a

### Turn in Files

Makefile, *.h, */*.h, *.c, */*.c

### External Functions

malloc, free, write, va_start, va_arg, va_copy, va_end

### Description

Create a library containing ft_printf(), which mimics printf() without implementing its buffer management. It should handle conversions: cspdiuxX%.

## Compilation

- `make`: Compiles the library and creates `libftprintf.a`.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the library `libftprintf.a`.
- `make re`: Cleans and recompiles the library.

## Usage

- Various format specifiers are supported, such as %c, %s, %d, %i, %u, %x, %X, and %%, similar to the standard printf.
- Make sure to include "libftprintf.h" in your source files where you intend to use ft_printf.
- Compile your program with libftprintf.a linked using the provided Makefile commands

#include "libftprintf.h"

int ft_printf(const char *format, ...);

### Example

#include "libftprintf.h"

int main() {
    ft_printf("Hello, %s!\n", "world");
    return 0;
}

```c
