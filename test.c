#include <unistd.h>
int main()
{
    write(2, "[--bench]", 9);
    write(1, "olha la ele", 11);
}