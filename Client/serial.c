#include "serial.h"

int get_input(char* buff, int maxSize)
{
    fgets(buff, maxSize, stdin);
    int length = strlen(buff);
    int indexOfLastChar = length - 1;

    if (buff[indexOfLastChar] == '\n')
    {
        buff[indexOfLastChar] = 0;
        return 1;
    }

    int hasExtra = 0;
    char ch;
    while (((ch = getchar()) != '\n') && (ch != EOF))
        hasExtra = 1;

    if (hasExtra)
        return 0;
    return 1;
}