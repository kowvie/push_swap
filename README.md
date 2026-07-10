# push_swap
algorithims to sort a stack of numers

push_swap calculates and displays on the standard output the smallest program,
made of Push swap language operations, that sorts the integers received as arguments.

goal: algorithmic complexity 

rules: 2 stacks named a and b
At the beginning:
    ◦ The stack a contains a random amount of negative and/or positive numbers
without any duplicate.
    ◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
    sa (swap a): Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements.
    sb (swap b): Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements.
    ss : sa and sb at the same time.
    pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
    pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
    ra (rotate a): Shift up all elements of stack a by one.
The first element becomes the last one.
    rb (rotate b): Shift up all elements of stack b by one.
The first element becomes the last one.
    rr : ra and rb at the same time.
    rra (reverse rotate a): Shift down all elements of stack a by one.
The last element becomes the first one.
    rrb (reverse rotate b): Shift down all elements of stack b by one.
The last element becomes the first one.
    rrr : rra and rrb at the same time.

    ALGORITH REQUIREMENTS 

**must implement four distinct sorting strategies

must measure the disorder before doing any moves.

- simple O(n2)
    bubble sort: 
        repeatedly swaps the adjacent elements if they are in the wrong order\\
        Sorts the array using multiple passes.

estrutura do projeto:

   - stack implementada com linked lists:
            A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle;
            implemented using a linked list, each element of the stack is represented as a node. The head of the linked list acts as the top of the stack
        advantages: dynamic size, efficient memory, no overflow (only is system memory is exausted), easy operations, flexible;

        Note: Even being the better method of stack implementation, the linked list implementation only used when it is absolutely necessary because we have to implement the linked list also as there are no built in data structure for it in C Programming Language.
