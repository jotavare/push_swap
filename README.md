<p align="center">
  <img src="https://github.com/jotavare/jotavare/blob/main/42/banner/42_banner_push_swap.png">
</p>

<p align="center">
	<img src="https://img.shields.io/badge/status-finished-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/github/languages/top/jotavare/libft?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/github/last-commit/jotavare/libft?color=%2312bab9&style=flat-square" />
	<a href='https://www.linkedin.com/in/joaoptoliveira' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=0A66C2&color=0A66C2'/></a>
	<a href='https://profile.intra.42.fr/users/jotavare' target="_blank"><img alt='42' src='https://img.shields.io/badge/Porto-100000?style=flat-square&logo=42&logoColor=white&labelColor=000000&color=000000'/></a>
</p>

<p align="center">
	<a href="#about">About</a> •
	<a href="#how-to-use">How to use</a> •
	<a href="#mandatory">Mandatory</a> •
	<a href="#bonus">Bonus</a> •
	<a href="#disclaimer">Disclaimer</a> •
	<a href="#testers">Testers</a> •
	<a href="#license">License</a>
</p>

## ABOUT
push_swap is a 42 school algorithm project where we must sort a given list of random numbers with a limited set of instructions, using the lowest possible number of actions.

<a href="https://github.com/jotavare/push_swap/blob/master/subject/en_subject_push_swap.pdf">Click here</a> for the subject of this project.

## HOW TO USE
#### COMPILE
#### 1º - Clone the repository
```bash
git clone git@github.com:jotavare/push_swap.git
```
#### 2º - Enter the project folder and run `make`
```bash
cd push_swap\push_swap
make
```
#### 3º - Run the code
```bash
./push_swap <numbers>
./push_swap 9 0 -217 2147483647 -2147483648
```
#### 4º - Use the subject checker
```bash
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```

#### MAKEFILE RULES

`make` - Compile libft mandatory functions.

``make bonus`` - Compile libft bonus functions.

``make all`` - Compile all functions.

``make clean`` - Delete all .o (object files) files.

``make fclean`` - Delete all .o (object files) and .a (executable) files.

``make re`` - use rules `fclean` + `all`


## Mandatory
#### push_swap rules:
The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

Possible actions are:

* ```pa``` **(push A)**: Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* ```pb``` **(push B)**: Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* ```sa``` **(swap A)**: Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* ```sb``` **(swap B)**: Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ```ss```: ```sa``` and ```sb``` at the same time.
* ```ra``` **(rotate A)**: Shift all elements of stack A up by 1. The first element becomes the last one.
* ```rb``` **(rotate B)**: Shift all elements of stack B up by 1. The first element becomes the last one.
* ```rr```: ```ra``` and ```rb``` at the same time.
* ```rra``` **(reverse rotate A)**: Shift all elements of stack A down by 1. The last element becomes the first one.
* ```rrb``` **(reverse rotate B)**: Shift all elements of stack b down by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.

#### Grade
The grade depends on how efficient the program's sorting process is.
 
* Sorting **3 values**: no more than **3 actions**.
* Sorting **5 values**: no more than **12 actions**.
* Sorting **100 values**: **rating from 1 to 5 points** depending on the number of actions:

  * **5 points** for less than **700 actions**
  * **4 points** for less than **900 actions**
  * **3 points** for less than **1100 actions**
  * **2 points** for less than **1300 actions**
  * **1 point** for less than **1500 actions**
* Sorting **500 values**: **rating from 1 to 5 points** depending on the number of actions:

  * **5 points** for less than **5500 actions**
  * **4 points** for less than **7000 actions**
  * **3 points** for less than **8500 actions**
  * **2 points** for less than **10000 actions**
  * **1 point** for less than **11500 actions**

Validating the project requires at least 80/100.

#### Error Managemnt
The program should print `Error` if the following tests are made:
```
Non numeric parameters -> ./push_swap 4 bb 2
Duplicate numeric parameter -> ./push_swap 4 4 5
Numeric parameter greater than INT_MAX -> ./push_swap 4 2 2147483648
Numeric parameter less than INT_MIN -> ./push_swap 4 2 -2147483649
```

## DISCLAIMER
At 42 School, it is expected that almost every project is written in accordance with the Norm, which is the coding standard of the school.

```bash
- No for, do while, switch, case or goto are allowed
- No more than 25 lines per function and 5 functions per file
- No assigns and declarations in the same line (unless static)
- No more than 5 variables in 1 function
- ...
```

<a href="https://github.com/jotavare/jotavare/blob/main/42/pdf/en_norm.pdf">Click here</a> for more information on 42 norms.

## TESTERS
- [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer) `o-reo` `GitHub`
- [Push Swap Tester](https://github.com/laisarena/push_swap_tester) `laisarena` `GitHub`
- [Push Swap Leak Tester](https://github.com/IDC87/push_swap_leak_tester) `IDC87` `GitHub`
- [Push Swap Tester](https://github.com/gemartin99/Push-Swap-Tester) `gemartin99` `GitHub`

## LICENSE
<p>
This work is published under the terms of <a href="https://github.com/jotavare/jotavare/blob/main/LICENSE">42 Unlicense</a>.
</p>
