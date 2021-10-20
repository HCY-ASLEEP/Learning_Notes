#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
int main(int argc, char** argv) {
    char path[50];
    memset(path, 0, 50);
    sprintf(path, "%s", "./test");
    int fd;

    printf("access function -------------------------/n");

    if ((fd = access(path, F_OK)) == 0)
        printf("[access] file exist!/n");
    else
        printf("[access] file not exist!!/n");

    if ((fd = access(path, R_OK)) == 0)
        printf("[access] read file ok!/n");
    else
        printf("[access] read file no!/n");

    if ((fd = access(path, W_OK)) == 0)
        printf("[access] write file ok!/n");
    else
        printf("[access] write file no!/n");

    if ((fd = access(path, X_OK)) == 0)
        printf("[access] execute file ok!/n");
    else
        printf("[access] execute file no!/n");

    printf("open  function -------------------------/n");

    if ((fd = open(path, O_RDONLY)) == -1)
        printf("[open] open no!/n");
    else {
        close(fd);
        printf("[open] open ok!/n");
    }

    if ((fd = open(path, O_WRONLY)) == -1)
        printf("[open] write no!/n");
    else {
        close(fd);
        printf("[open] write ok!/n");
    }
    if ((fd = open(path, O_RDWR)) == -1)
        printf("[open] rdwr no!/n");
    else {
        close(fd);
        printf("[open] rdwr ok!/n");
    }
}
