#include <stdio.h>
#include <ctype.h>

int containsNumbers(const char* str) {
    while (*str) {
        if (isdigit(*str)) {
            return 1; // String contains numbers
        }
        str++;
    }
    return 0; // String does not contain numbers
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;
    if (argc == 2)
    {
        if (containsNumbers(argv[1]) == 1)
            return (1);
    }
    printf("No numbers found\n");
    return 0;
}