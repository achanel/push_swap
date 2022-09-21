# push_swap

This project make sort data on a "stack", with a limited set of instructions,
using the lowest possible number of actions.

# SUMMARY

- [x] Mandatory part

# Operationals

* sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

* sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

* ss : sa and sb at the same time.

* pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

* pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

* ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

* rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

* rr : ra and rb at the same time.

* rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.

* rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

* rrr : rra and rrb at the same time.

![pushswap]

# RUN
- [x] Mandatory part
```bash
make && ./push_swap <any_sequence_of_numbers>
```

To run push swap and count the number of instructions :

```shell
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

# Run push_swap with the checker

```shell
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
```

# Resources

* [Алгоритмы сортировки](https://academy.yandex.ru/journal/osnovnye-vidy-sortirovok-i-primery-ikh-realizatsii)