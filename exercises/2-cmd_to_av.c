#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main ()
{
    int i = 0;
    char *buffer;
    char *portion;
    char delimiter[] = " ";
    size_t buffsize = 4095;

    buffer = (char *)malloc(sizeof(char) * buffsize);
    if (buffer == NULL)
        return (-1);
    
    getline(&buffer, &buffsize, stdin);
    portion = strtok(buffer, delimiter);
    array[i] = strdup(portion);
    printf("%s\n", portion);
    printf("%s\n", array[i]);

    while (portion != NULL)
    {
        i++
        portion = strtok(NULL, delimiter);
        array[i] = strdup(portion);
        printf("%s\n", portion);
        printf("%s\n", array[i]);
    }
    return (0);
}
