# 42_push_swap
>The push_swap project focuses on sorting data within two stacks
>while minimizing the number of required moves.
>This task involves managing two stacks, 'a' and 'b,'
>initially with 'a' containing a set of positive and negative numbers without duplicates,
>while 'b' starts as an empty stack.
>The primary goal is to sort the numbers in stack 'a' in ascending order,
>with the smallest number positioned at the top.
>To accomplish this, the project offers a set of operations,
>including element swapping within stacks, element pushing between stacks,
>and element rotation within stacks.
>
>The key challenge involves finding the most efficient approach to sort numbers with as few operations as possible.
>This project tests the algorithmic and problem-solving skills
>since it requires creating efficient sorting strategies and applying them using the provided set of operations.

The available set of operations that needed to be implemented:

| Operation    | Explanation                                                                        |
| :-:          | :------------------------------------------------------------------------------ |
| **sa** (swap a)  | Swap the first 2 elements at the top of stack a.                |
| **sb** (swap b)  | Swap the first 2 elements at the top of stack b.                |
| **ss**           | sa and sb at the same time.                                     |
| **pa** (push a)  | Take the first element at the top of stack b and put it at the top of stack a.  | 
| **pb** (push b)  | Take the first element at the top of stack a and put it at the top of stack b.  |  
| **ra** (rotate a)| Shift up all elements of stack a by 1. The first element becomes the last one.  |
| **rb** (rotate b)| Shift up all elements of stack b by 1. The first element becomes the last one.  |
| **rr**       | **ra** and **rb** at the same time. |
| **rra** (reverse rotate a) | Shift down all elements of stack a by 1. The last element becomes the first one. |
| **rrb** (reverse rotate b) | Shift down all elements of stack b by 1. The last element becomes the first one. |
| **rrr**  | **rra** and **rrb** at the same time. |

### Usage
1. clone this repository and `cd` into it:

```zsh
git clone https://github.com/jmatheis00/42_push_swap.git && cd 42_push_swap
```

2. Compile the library using make:

```zsh
make
```

3. Run the project with the following command and replace `<number1 number2 (... numberN)>` bv the numbers you want to sort.

```zsh
./push_swap <number1 number2 (... numberN)>
```
