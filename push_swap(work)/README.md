*This project has been created as part of the 42 curriculum by husobral and jsilva-r.*

## Description
Push_swap is a algorithim projects where the data in two stacks `a` and `b`, must be sorted by ascending order in a limited number of operations.

Operations include:
- `sa` (swap a): Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.
- `sb` (swap b): Swap the first two elements at the top of stack b. Do nothing if there is only one or no elements.
- `ss` : sa and sb at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb` (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra` (rotate a): Shift up all elements of stack a by one. The first element becomes the last one.
- `rb` (rotate b): Shift up all elements of stack b by one. The first element becomes the last one.
- `rr` : ra and rb at the same time.
- `rra` (reverse rotate a): Shift down all elements of stack a by one. The last element becomes the first one.
- `rrb` (reverse rotate b): Shift down all elements of stack b by one. The last element becomes the first one.
- `rrr`: rra and rrb at the same time.

The project makes us implement four sorting strategies using the push_swap operations to perform the sorting.
- `Simple algorithm (O(n2))` we decided on: Selection Sort
- `Medium algorithm  (O(n√n))` we decided on : Chunks Sort
- `Complex algorithm (O(n log n))` we decided on: Radix Sort

The projects has a `disorder metric` that we need to implement not only to know how disorganized is the stack but it will also be usefull in our `Custom algorithm`. Its mandatory to measure the disorder before doing any moves.

As mention above, it's also required to create a `custom adaptive algorithm (learner's design)` where our adaptive strategy selects diffrent internal methods depending on the mesured `disorder`

- `low disorder` the method must be run in O(n2) time;
- `Medium disorder` the method must run in
O(n√n) time.
- `High disorder` the method must run in O(n log n)
time.

### Explanation of the algorithm
only god knows
### Learners's contributions
husobral :

jsilva-r: 

## Instructions
## Resources
### How AI was used?
for mental and emotional support :D T_T