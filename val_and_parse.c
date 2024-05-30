#include "push_swap.h"

void val_args(int argc, char **argv)
{
    int i;
    char *arg;

    if (argc > 1)
    {
        for (i = 1; i < argc; i++)
        {
            arg = argv[i];
            while (*arg != '\0')
            {
                if (!ft_isdigit(*arg) && !ft_isspace(*arg)
                    && *arg != '-' && *arg != '+')
                {
                    write(1, "Aqui\n", 5);
					ft_display_error();
                    exit(1);
                }
                arg++;
            }
        }
    }
}
