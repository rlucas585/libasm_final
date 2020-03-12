# Libasm Project - Ryan Lucas

This is my completed libasm project for 42 network school
[Codam](https://www.codam.nl).

### List of functions

#### Mandatory

* ft_strlen
* ft_strcpy
* ft_strcmp
* ft_write
* ft_read
* ft_strdup

#### Bonus

* ft_atoi_base
* ft_list_push_front
* ft_list_size
* ft_list_sort
* ft_list_remove_if

#### Additional functions

* ft_atoi
* ft_strchr

## How to Run

Create the library 'libasm.a', containing all 6 mandatory functions. The obj
directory will also be populated with the relevant object files. 'make all' is
a synonymous command.

```bash
make 
```

Create the library 'libasm_bonus.a', with all mandatory functions, the 5
required bonus functions, and two additional functions (ft_atoi and ft_strchr).

```bash
make bonus
```

Compile the library 'libasm.a' and an executable 'testexec' that will test all
6 mandatory functions using 'nocrit_main.c' located in the 'tests/' directory.

```bash
make test
```

Compile the library 'libasm.a' and an excutable 'testexec' that will test all 6
mandatory functions using 'testmain.c' located in the 'tests/' directory. These
tests require criterion.

```bash
make crittest
```

Compile the library 'libasm_bonus.a' and an excutable 'testexec' that will test 
all 6 mandatory functions and bonus functions using 'testmain_bonus.c' located
in the 'tests/' directory. These tests require criterion.

```bash
make bonuscrittest
```

Remove all object files from the obj/ directory.

```bash
make clean
```

Remove all object files from the obj/ directory, the executable 'testexec', and
libraries 'libasm.a' and 'libasm_bonus.a'.

```bash
make fclean
```

Remove all object files from the obj/ directory, the executable 'testexec', and
libraries 'libasm.a' and 'libasm_bonus.a'. Then recompile the library
'libasm.a'.

```bash
make re
```
