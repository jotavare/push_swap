<p align="center">
  <img src="https://github.com/jotavare/jotavare/blob/main/42/banners/piscine_and_common_core/github_piscine_and_common_core_banner_push_swap.png">
</p>

<p align="center">
	<img src="https://img.shields.io/badge/status-finished-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/badge/evaluated-03%20%2F%2004%20%2F%202023-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/badge/score-84%20%2F%20100-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/github/languages/top/jotavare/push_swap?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/github/last-commit/jotavare/push_swap?color=%2312bab9&style=flat-square" />
	<a href='https://www.linkedin.com/in/jotavare' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-blue?style=flat-square'/></a>
	<a href='https://profile.intra.42.fr/users/jotavare' target="_blank"><img alt='42' src='https://img.shields.io/badge/Porto-100000?style=flat-square&logo=42&logoColor=white&labelColor=000000&color=000000'/></a>
</p>

<p align="center">
	<a href="#about">About</a> •
	<a href="#how-to-use">How to use</a> •
	<a href="#mandatory">Mandatory</a> •
	<a href="#bonus">Bonus</a> •
	<a href="#norminette">Norminette</a> •
	<a href="#debugging">Debugging</a> •
	<a href="#contributing">Contributing</a> •
	<a href="#license">License</a>
</p>

## ABOUT
In this project, I developed a sorting algorithm for a specific problem using two stacks. The goal of the project is to efficiently sort a stack of integers using a set of predefined operations.

> [!NOTE]
> For the rest of the projects and exams in the cursus, <a href="https://github.com/jotavare/42-common-core">click here</a>.

## HOW TO USE
#### 1º - Clone the repository
```bash
git clone git@github.com:jotavare/push_swap.git
```
#### 2º - Enter the project folder and run `make`
```bash
cd push_swap/push_swap
make
```
#### 3º - Run the code
```bash
./push_swap [numbers]
./push_swap 9 0 -217 2147483647 -2147483648
```

Counting the operations for a given input:
```bash
./push_swap 9 0 -217 2147483647 -2147483648 | wc -l
```

#### 4º - Assign numbers to a variable and run the code
```bash
ARG="3 0 9 2 -1"; ./push_swap $ARG
```

#### 5º - Check the result
The bonus `checker` was not done, so this repository does not ship one. To
verify the output, use the `checker_linux` binary provided with the subject:
```bash
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker_linux $ARG
```

#### MAKEFILE RULES

`make` - Compile `push_swap.a` and the `push_swap` executable.

`make all` - Same as `make`.

`make clean` - Delete the `objects` directory.

`make fclean` - Delete the object files, `push_swap.a` and the executable.

`make re` - Use rules `fclean` + `all`.

`make debug` - Rebuild with `-g3 -fsanitize=address` for use with gdb and AddressSanitizer.


## MANDATORY
#### RULES
> The program is only allowed to work with two stacks, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

Possible actions:
- [x] `pa` **(push A)**: Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
- [x] `pb` **(push B)**: Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
- [x] `sa` **(swap A)**: Swap the first 2 elements at the top of stack A. Do nothing if there are only one or no elements.
- [x] `sb` **(swap B)**: Swap the first 2 elements at the top of stack B. Do nothing if there are only one or no elements.
- [x] `ss`: `sa` and `sb` at the same time.
- [x] `ra` **(rotate A)**: Shift all elements of stack A up by 1. The first element becomes the last one.
- [x] `rb` **(rotate B)**: Shift all elements of stack B up by 1. The first element becomes the last one.
- [x] `rr` : `ra` and `rb` at the same time.
- [x] `rra` **(reverse rotate A)**: Shift all elements of stack A down by 1. The last element becomes the first one.
- [x] `rrb` **(reverse rotate B)**: Shift all elements of stack b down by 1. The last element becomes the first one.
- [x] `rrr` : `rra` and `rrb` at the same time.

#### GRADE
> The grade depends on how efficient the program's sorting process is.
 
- [x] Sorting **3 values**: no more than **3 actions**.
- [x] Sorting **5 values**: no more than **12 actions**.
- [x] Sorting **100 values**: **rating from 1 to 5 points** depending on the number of actions:

   - [ ] **5 points** for less than **700 actions**.
   - [ ] **4 points** for less than **900 actions**.
   - [x] **3 points** for less than **1100 actions**.
   - [x] **2 points** for less than **1300 actions**.
   - [x] **1 point** for less than **1500 actions**.
- [x] Sorting **500 values**: **rating from 1 to 5 points** depending on the number of actions:

   - [ ] **5 points** for less than **5500 actions**.
   - [x] **4 points** for less than **7000 actions**.
   - [x] **3 points** for less than **8500 actions**.
   - [x] **2 points** for less than **10000 actions**.
   - [x] **1 point** for less than **11500 actions**.

> Note: Validating the project requires at least 80/100. I believe 3 points with 100 and 500 numbers would be 80/100.

#### ERROR MANAGEMENT
> The program should print `Error` + `\n` if the following tests are made:

- [x] Non-numeric parameters.
- [x] Duplicate numeric parameter.
- [x] Numeric parameter greater than INT_MAX.
- [x] Numeric parameter less than INT_MIN.

```bash
./push_swap 4 bb 2
./push_swap 4 4 5
./push_swap 4 2 2147483648
./push_swap 4 2 -2147483649
```

#### SORTED EXAMPLES
> Should not print anything if the following tests are made:

- [x] No parameter.
- [x] Single numeric argument.
- [x] The numbers are already sorted.

```bash
./push_swap
./push_swap 42
./push_swap 0 1 2 3
./push_swap 0 1 2 3 4 5 6 7 8 9
```

## BONUS
- [ ] Create a checker for push_swap that will read the program instructions and display `KO` or `OK`.

## NORMINETTE
> At 42 School, it is expected that almost every project is written following the Norm, which is the coding standard of the school.

```
- No for, do...while, switch, case, goto, ternary operators, or variable-length arrays allowed;
- Each function must be a maximum of 25 lines, not counting the function's curly brackets;
- Each line must be at most 80 columns wide, with comments included;
- A function can take 4 named parameters maximum;
- No assigns and declarations in the same line (unless static);
- You can't declare more than 5 variables per function;
- ...
```

* [42 Norms](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf) - Information about 42 code norms. `PDF`
* [Norminette](https://github.com/42School/norminette) - Tool to respect the code norm, made by 42. `GitHub`
* [42 Header](https://github.com/42Paris/42header) - 42 header for Vim. `GitHub`

## DEBUGGING
> Sorting works through a linked list that is allocated once and rearranged
> throughout, so every node has to be freed on both the success and the error
> path.

Build with the sanitizer and debug symbols:

```bash
make debug
```

`gdb --args ./push_swap 3 0 9 2 -1` - Step through parsing and the radix passes.

`valgrind --leak-check=full ./push_swap 3 0 9 2 -1` - Report anything the free path missed.

`valgrind --track-origins=yes ./push_swap 3 0 9 2 -1` - Trace an uninitialised value back to where it came from.

* [GDB](https://www.sourceware.org/gdb/) - The GNU debugger. `Website`
* [Valgrind](https://valgrind.org/docs/manual/quick-start.html) - Quick start guide. `Website`

## CONTRIBUTING

This repository documents work already submitted and graded, so it is not open
to changes. Feel free to fork it if any of it is useful to you.

## LICENSE

This project is available under the MIT License. For further details, please refer to the [LICENSE](https://github.com/jotavare/push_swap/blob/main/LICENSE) file.
