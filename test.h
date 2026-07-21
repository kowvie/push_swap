#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
    char    a;
}   t_stack;
