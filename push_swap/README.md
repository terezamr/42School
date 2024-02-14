# push_swap
The goal of this program is to sort in ascending order a stack _a_, using a stack _b_ and several defined operations.

## Usage
Execution: The program receives as arguments the numbers of the stack a.

```shell
./push_swap <n>
```

The available operations are the following:
* sa (swap a): Swap the first 2 elements at the top of stack a.
* sb (swap b): Swap the first 2 elements at the top of stack b.
* ss : sa and sb at the same time.
* pa (push a): Take the first element at the top of b and put it at the top of a.
* pb (push b): Take the first element at the top of a and put it at the top of b.
* ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
* rb (rotate b)
* rr: ra and rb at the same time.
* rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
* rrb (reverse rotate b)
* rrr: rra and rrb at the same time.

Notes: the usage of a [visualizer](https://github.com/o-reo/push_swap_visualizer) might be helpful to check the algorithm's solution.

Bonus: not included.
