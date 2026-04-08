#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"
#define NULL ((void *)0)


char* strtok(char *str, const char* delimeter) {
    static char *last;

    if (str != NULL) last = str;
    if (last == NULL || *last == '\0') return NULL;

    while (*last && strchr(delimeter, *last)) last++;
    if (*last == '\0') return NULL;

    char *token_start = last;

    while (*last && !strchr(delimeter, *last)) last++;

    if (*last != '\0') {
        *last = '\0';
        last++;
    }

    return token_start;
}

int isdigit(char* s) {
    if (s == NULL || *s == '\0') return 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (! ('0' <= s[i] && s[i] <= '9')) {
            return 0;
        }
    }
    return 1;
}

int isTargetNumber(int val) {
    return (val % 5 == 0 || val % 6 == 0);
}

void printsixfive(char *buf) {
    const char *delim = " -\r\t\n./,";
    char *token = strtok(buf, delim);

    while (token != NULL) {
        if (isdigit(token)) {
            int val = atoi(token);
            if (isTargetNumber(val)) {
                printf("%d\n", val);
            }
        }
        token = strtok(NULL, delim);
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2){
        fprintf(2, "Usage: sixfive files...\n");
        exit(1);
    }
    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if(fd < 0){
            fprintf(2, "sixfive: cannot open %s\n", argv[i]);
            close(fd);
            exit(1);
        }
        char buf[512];
        int n = read(fd, buf, sizeof(buf));
        if (n > 0) {
            printsixfive(buf);
        } else {
            fprintf(2, "sixfive: cannot read %s\n", argv[i]);
            close(fd);
            exit(1);
        }
        close(fd);
    }
    exit(0);
}









/* strtok 구현 안하고 직접 만들기
void printSixFive(int buf_size, char *buf) {
    char *tok = " -\r\t\n./,";
    char ret[512];
    char *p = buf;
    char *buf_ed = buf + buf_size;

    while (p < buf_ed) {
        while (p < buf_ed && strchr(tok, *p)) {
            p++;
        }
        if (p >= buf_ed) {
            break;
        }
        char *st = p;
        while (p < buf_ed && !strchr(tok, *p)) {
            p++;
        }
        int len = p - st;

        memmove(ret, st, len);
        ret[len] = '\0';
        int val = atoi(ret);
        if (val % 5 == 0 || val % 6 == 0) {
            printf("%d\n", val);
        }
    }
}


int
main(int argc, char *argv[])
{
    if(argc < 2){
        fprintf(2, "Usage: sixfive file...\n");
        exit(1);
    }
    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if(fd < 0){
            fprintf(2, "sixfive: cannot open %s\n", argv[i]);
            exit(1);
        }
        char buf[512];
        int buf_size = read(fd, buf, sizeof(buf));
        if (buf_size < 0) {
            fprintf(2, "sixfive: cannot read %s\n", argv[i]);
            close(fd);
            exit(1);
        }
        printSixFive(buf_size, buf);
        close(fd);
    }
    exit(0);
}

*/