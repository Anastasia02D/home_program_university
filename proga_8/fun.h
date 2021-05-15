#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256

typedef struct spisok{
        int value;
        struct spisok *next;
} spisok;


void add_element(int data, spisok *head);
spisok **f_read(int *err, int *k_str);
int get_int(char *s, int *x);
void clear(spisok **head, int k);
void print (spisok **arr, int k);
char *mygets(char **str, unsigned long int *LMax, FILE *in);
void del (spisok **head, int k_str, int a);
int proga(spisok **arr, int k_str);
