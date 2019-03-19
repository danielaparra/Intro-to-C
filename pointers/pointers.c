#include <stdio.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    
    // char *copy[512];
    // *x = copy;
    int index = 0;
    while (*y != '\0') {
        x[index] = *y;
        y = y + 1;
        index += 1;
    }
    x[index] = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    // int index = 0;
    char *newstr = NULL;
    while (*str != '\0') {
        if (*str == c) {
            newstr = str;
            break;
        }
        str = str + 1;
        // index += 1;
    }

    return newstr;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{

    while (*haystack != '\0') {
        char *start = haystack;
        while (*haystack == *needle && *needle != '\0') {
            haystack = haystack + 1;
            needle = needle + 1;
        }

        if (*needle == '\0') {
            return start;
        }

        haystack = haystack + 1;
    }

    return NULL;
}

#ifndef TESTING
int main(void)
{
    // char *string = "hello, world";
    // char empty[20];
    
    // string_copy(&empty, string);
    // printf("%s\n", empty);
    
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
