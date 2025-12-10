***This project has been created as part of the 42 curriculum by abahoumi.***

## Description
Push_swap is a sort algorithm project. The goal is to sort a number set on a stack in ascending order, with a limited set of operations, using the minimum number of moves.

The project involves two stacks:
* Stack A: Contains a random amount of non-duplicated negative or positive numbers.
* Stack B: Initially empty.

Allowed operations:

* sa (swap a): Swap the first 2 elements at the top of stack a.
* sb (swap b): Swap the first 2 elements at the top of stack b.
* ss: sa and sb at the same time.
* pa (push a): Take the first element at the top of b and put it at the top of a.
* pb (push b): Take the first element at the top of a and put it at the top of b.
* ra (rotate a): Shift up all elements of stack a by 1.
* rb (rotate b): Shift up all elements of stack b by 1.
* rr: ra and rb at the same time.
* rra (reverse rotate a): Shift down all elements of stack a by 1.
* rrb (reverse rotate b): Shift down all elements of stack b by 1.
* rrr: rra and rrb at the same time.
## Algorithm Used
I implemented this project with The Turkish Algorithm that simply do multiple calculations before each move

* Small Inputs : Hardcoded logic for sorting 3 and 5 numbers.
* Large Inputs (The Turk Algorithm):
  This algorithm focuses on reducing the total operation count by calculating the "cheapest" move at every step.
  Initialization: Push the first two nodes to Stack B.
  Greedy Push (A to B):
  Calculate current indices and determine if nodes are above the median.
  Assign a target for every node in Stack A (the correct spot where it belongs in Stack B).
  Calculate the cost (number of instructions) to move each node to its target.
  Execute the move for the node with the lowest cost.
  Repeat until only 3 nodes remain in Stack A.
  Sort Small: Sort the remaining 3 nodes in Stack A.
  Push Back (B to A): Calculate targets for nodes in Stack B to place them correctly back into Stack A.
  Final Adjustment: Check if the minimum node is at the top of the stack. If not, rotate (ra/rra) until the list is    fully sorted.
## Compilation
To compile the project, navigate to the root of the repository and run:
``
make
``
This will generate the push_swap executable.

To compile the bonus part run:
``
make bonus
``
This will generate the checker executable.

Other available Make commands:

``make clean``: Removes object files.
``make fclean``: Removes object files and the executable.
``make re``: Recompiles the project from scratch.
## Execution
Run the program by passing a list of integers as arguments:


```bash
./push_swap 2 1 3 6 5 8
```

The program will output the list of operations required to sort the stack:

```text
sa
pb
pb
...
```
## Valid formats
```bash
./push_swap "2 1 3 6 5 8"
```
```bash
./push_swap "2" 1 3 "6 5 8"
```
```bash
./push_swap "2 1""3" 6 5 8
```
## Error Handling
The program handles the following error cases by printing Error followed by a new line on the standard error:
* Empty arg
```bash
./push_swap ""
```
* Multiple spaces
```bash
./push_swap "            "
```
* Non-integer arguments.
```bash
./push_swap 11 8 nine
```
Arguments bigger than an integer.
```bash
./push_swap 11 8 99999999999
```
Duplicate arguments.
```bash
./push_swap 11 8 -9 8
```
To verify the number of instructions, you can pipe the output to a line counter:

```Bash
./push_swap 0 9 1 8 2 7 3 6 4 5 | wc -l
```
## Resources
* Meduim article : [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
* Youtube Video : [push_swap TUTORIAL!](https://youtu.be/wRvipSG4Mmk?si=Snznpy-rndvoRZmN)

## AI Usage
* Conceptual Understanding: I used AI to break down the mechanics of the push_swap instructions and to visualize how the two stacks interact.
* Optimization: AI helped me understand the mathematical logic behind calculating the "cheapest" move, allowing me to optimize the algorithm for a lower instruction count.
