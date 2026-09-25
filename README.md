*This project has been created as part of the 42 curriculum by kboonkos.*

# Description
This project aims to obtain programming skills from building `ft_printf` whose behavior is similar to `printf`. The function contains "specifier conversion" which is what makes printf "variadic function," one of learning goals. In this project, the concept of variadic function was introduced. The mandatory converions are as followed:
- `%c` : Prints a single character.
- `%s` : Prints a string (as defined by the common C convention).
- `%p` : The `void *` pointer argument has to be printed in hexadecimal format.
- `%d` : Prints a decimal (base 10) number.
- `%i` : Prints an integer in base 10.
- `%u` : Prints an unsigned decimal (base 10) number.
- `%x` : Prints an unsigned decimal (base 10) number.
- `%X` : Prints a number in hexadecimal (base 16) uppercase format.
- `%%` : Prints a percent sign.

# Instructions
To install, compile, and execute the project, complete the brief followings:
1. clone the project into your preferred directory.
2. `cd` into the directory.
3. `make`
4. `cc -Wall -Wextra -Werror libftprintf.a {YOUR_RUNNER.C}`

## commands
make or make all = compile all source codes and to create the static library.
make clean = remove all object files.
make fclean = remove all object files and `libftprintf.a` binary.
make re = recompile the whole prject = make fclean + make all.

# Resources
## References
- 42 Students at 42 Bangkok campus
- Google Search Engine
- Linux man page
- Claude (Anthropic), for debugging and code review
- `printfTester (2019+)` by Tripouille, for testing

## AI Usage

Claude (Anthropic) was used during this project for:

- Debugging specific reported failures (e.g. a Valgrind "invalid read of size 1 at address 0x0" traced to a NULL check placed after the operation it was meant to guard; a pointer-arithmetic bug in a `%%` handler caused by incrementing a `size_t *` instead of dereferencing it; a `Makefile` build failure traced to a source filename mismatch after modularizing conversion functions)
- Explaining underlying mechanisms rather than just fixing symptoms — how `va_start`/`va_arg` locate and read variadic arguments at the ABI level, why type information from the call site doesn't survive to `va_arg`, why duplicate function *definitions* (vs. duplicate *declarations*) are a linker-stage error rather than a compiler-stage one, and how to interpret Valgrind's memory-error output precisely
- Reviewing `Makefile` structure for correctness (default-goal resolution, recursive `make` delegation to a `libft` subdirectory, `.PHONY` usage) rather than writing it wholesale
- Design guidance for the bonus (flags/width/precision) given as directional hints — identifying the structural risk of duplicating padding/flag logic across each conversion function, and pointing toward separating format-spec parsing from content generation — without providing the implementation itself
- Pointing to further learning resources (`A Philosophy of Software Design`, Fowler's `Refactoring`, reading mature `printf` implementations) for the general design skill involved, distinct from `ft_printf`-specific help

All conversion-function logic, the dispatcher, and the `Makefile` itself were written and typed by the author. AI was used as a debugging aid, a reviewer, and a source of conceptual explanation and directional hints — not to generate the mandatory or bonus implementation.
