# push_swap
algorithims to sort a stack of numers

push_swap calculates and displays on the standard output the smallest program,
made of Push swap language operations, that sorts the integers received as arguments.

goal: algorithmic complexity 

note: use a [checker/visualizer](https://github.com/o-reo/push_swap_visualizer)

# Rules
2 stacks named a and b

At the beginning:

The stack a contains a random amount of negative and/or positive numbers
without any duplicate.

The stack b is empty.

The goal is to sort in ascending order numbers into stack a. To do so you have the
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

## ALGORITH REQUIREMENTS 

**must implement four distinct sorting strategies

must measure the disorder before doing any moves.

- simple O(n2): selection sort adaptation;

- medium O(n√n): chunk/bucket- based sorting;

- complex O(n log n): Radix sort (LSD, binary)

    fits stacks naturally
   

## estrutura do projeto:
Part 1
   - stack implementada com linked lists:

     A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle;
    implemented using a linked list, each element of the stack is represented as a node. The head of the linked list acts as the top of the stack
    advantages: dynamic size, efficient memory, no overflow (only is system memory is exausted), easy operations, flexible;

     Note: Even being the better method of stack implementation, the linked list implementation only used when it is absolutely necessary because we have to implement the linked list also as there are no built in data structure for it in C Programming Language.

   Em concreto, os teus ficheiros .h vão definir algo como:

    typedef struct s_node
    {
        int             value;
        struct s_node   *next;
    }   t_node;

    typedef struct s_stack
    {
        t_node  *top;
        int     size;
        char    name;   // 'a' ou 'b'
    }   t_stack;

E o teu programa principal vai ter dois destes — stack_a e stack_b — que passas para todas as funções.

PARTE 2 - Parsing e validação dos argumentos

Há vários casos de erro que tens de apanhar todos:

- string vazia ou so espacos;
- contem caracteres nao numericos;
- sinal "-" ou "+" no lugar errado;
- valor nao cabe num int de 32 bits;
- valores duplicados;

Todos dao erro e terminam o programa.

Ter atencao ao overflow, em vez do atoi, fazer uma especie de atoi que converte para long e depois para int.

os argumentos podem ser passados por uma unica string ou com multiplos argumentos. temos de lidar com ambos.
ex:  se `argc == 2` e `argv[1]` contém espaços, precisas de dividir por espaços (split) antes de processar.

PARTE 3 - As 11 operacoes

Há um aspeto crítico nas operações compostas (ss, rr, rrr): elas não chamam sa e depois sb — fazem as duas modificações sem imprimir nada, e no final imprimem só "ss\n". Se chamares sa dentro de ss, vais imprimir "sa\n" a mais. A solução é ter uma versão "silenciosa" de cada operação que não imprime, e a versão normal que chama a silenciosa e depois imprime

PARTE 4 - Organizacao de codigo

![alt text](image-1.png)



# O que é o disorder? 
É um número entre 0 e 1 que mede o quão desorganizada está a stack A. Calcula-se contando pares de posições onde um número maior aparece antes de um menor. Se disorder = 0, está ordenada. Se disorder = 1, está na pior ordem possível.

program get the numbers via arg so we need a type of itoa to do the conversion to ints;

of the 11 operations each one needs a funcion that will do the operation and prints its name.

![4 algoritmos](image.png)

## Pontos-chave para não esquecer
Algumas coisas que o subject sublinha e que costumam ser fonte de erros:

Erros a gerir obrigatoriamente — argumentos que não são inteiros, inteiros fora do range do int (overflow), e valores duplicados. Todos devem imprimir Error\n para stderr.

Sem variáveis globais — o subject proíbe explicitamente. Usa structs para passar estado.

O Makefile deve ter as regras $(NAME), all, clean, fclean, re, e bonus. Não pode fazer relinking desnecessário.

Atenção ao modo adaptive como padrão — se não passares nenhuma flag de estratégia, o comportamento é --adaptive. Se não passares argumentos nenhuns, o programa não deve imprimir nada.

O benchmark output vai para stderr — as operações continuam no stdout. Isto permite fazer:

     ./push_swap --bench 5 4 3 2 1 | ./checker 5 4 3 2 1 e funcionar corretamente.