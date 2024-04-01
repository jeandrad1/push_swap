int my_isspace(int c)
{
    return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v');
}

long ft_strtol(const char *str, char **endptr)
{
    long result = 0;
    int sign = 1;

    // Skip leading whitespace
    while (my_isspace((unsigned char)*str)) str++;

    // Handle optional sign
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    if (endptr != NULL)
        *endptr = (char *)str;
    return sign * result;
}