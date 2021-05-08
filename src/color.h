#ifndef _COLOR_H_
#define _COLOR_H_
#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

void success_print(char *message) {
    printf("%s",GRN);
    printf(message);
    printf("%s\n",NRM);
}

void error_print(char *message) {
    printf("%s",RED);
    printf(message);
    printf("%s\n",NRM);
}

void warning_print(char *message) {
    printf("%s",YEL);
    printf(message);
    printf("%s\n",NRM);
}
#endif