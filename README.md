*This project has been created as part of the 42 curriculum by husobral, jsilva-r.*

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

**Simple algorithm — Selection Sort `O(n²)`**
Repeatedly finds the minimum value still in stack `a`, rotates it to the top, then pushes it onto `b`. Once `a` is empty, everything is pushed back from `b` onto `a`, which restores ascending order because each element was pushed to `b` in increasing order.

**Medium algorithm — Chunks Sort `O(n√n)`**
Each node is assigned an `index` representing its rank (0 to n-1) via `assign_indexes`. The stack is then split into `√n`-sized chunks: nodes belonging to the current chunk are pushed to `b`, everything else is rotated past in `a`. Once a chunk is fully pushed, the chunk size limit increases and the next chunk is collected. Finally, `b` is emptied back into `a` by repeatedly finding the largest remaining index in `b` and moving it to the top before pushing, which reassembles the stack in order.

**Complex algorithm — Radix Sort `O(n log n)`**
Nodes are ranked with `assign_indexes` (0 to n-1), and the number of bits needed to represent the largest rank is computed with `get_max_bits`. For each bit position, from least to most significant, every element in `a` is inspected once: if the current bit is `0` it's rotated back into place (`ra`), if it's `1` it's pushed to `b` (`pb`). After each full pass, `b` is emptied back onto `a` with `pa`. After all bit passes, the stack is sorted — this is the standard stack-based LSD radix sort.

**Adaptive algorithm**
Before any moves are made, `compute_disorder` measures how disordered the input is. `select_adaptive` then picks a strategy based on that measurement:
- `disorder < 0.2` → Selection Sort (`O(n²)`)
- `0.2 ≤ disorder < 0.5` → Chunks Sort (`O(n√n)`)
- `disorder ≥ 0.5` → Radix Sort (`O(n log n)`)

### Learners's contributions
husobral :
- Parsing
- Sorting algorithms
- Stack movements/operations
- Norm correction

jsilva-r:
- Parsing completion
- Flag handling
- Benchmarking (`--bench`)
- Project integration
- README
- Makefile
- Header/includes

## Instructions

**Build**
```sh
make
```
This compiles the `push_swap` binary from the sources listed in the `Makefile`.

**Usage**
```sh
./push_swap [strategy flag] [--bench] number1 number2 ...
```

Strategy flags (optional, choose one):
- `--simple`   → force Selection Sort
- `--medium`   → force Chunks Sort
- `--complex`  → force Radix Sort
- `--adaptive` → force disorder-based strategy selection

If no strategy flag is given, `--adaptive` is used by default.

`--bench` prints sorting statistics to stderr after the operations: measured disorder, requested vs. executed strategy, and the total/per-operation counts.

**Examples**
```sh
./push_swap 3 1 2
./push_swap --complex "5 -3 8 1"
./push_swap --bench 4 67 3 87 23 1 2
```

## Resources
*(Add the specific links/articles you actually used — e.g. the 42 push_swap subject PDF, any radix sort or chunk sort articles, a push_swap visualizer you tested against, etc.)*

### How AI was used?
- start a study and project plan;
- debugging
- help with the printing of the `bench`;
- wording of README;