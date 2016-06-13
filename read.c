#include <stdlib.h>
#include <memory.h>
#include <ctype.h>

char *s;

int readElement () {
    char *element = (char *) malloc(sizeof(char) * 2);
    strncpy(element, s, 1);
    s++;
    if ((*s >= 'a') && (*s <= 'z')) {
        strncat(element, s, 1);
        s++;
    }
    switch (*element) {
        case 'K':
            return 39;
        case 'O':
            return 16;
        case 'C':
            return 12;
        case 'N':
            return 14;
        case 'H':
            return 1;
        default:
            return 0;
    }
    free(element);
}

int readNumber () {
    int i = 0;
    if (!isdigit(*s)) return 1;
    while (isdigit( *(s+i))) i++;
    char *number = (char*) malloc(sizeof(char) * i);
    strncpy(number, s, i);
    s+=i;
    return atoi(number);
}

int charType (char c) {
    if (isalpha(c)) return 0;
    if (isdigit(c)) return 1;
    if (c == '(') return 2;
    if (c == ')') return 3;
}

int readBlock () {
    int result = 0;
    while ((*s) && ( *s != ')')) {
        switch (charType(*s)) {
            case 0:
                result += readElement() * readNumber();
                break;
            case 1:
                readNumber();
                break;
            case 2:
                s++;
                result += readBlock() * readNumber();
                break;
            case 3:
                s++; // skip )
                break;
            default:
                return result;
        }
    }
    if (*s == ')') s++;
    return result;
}