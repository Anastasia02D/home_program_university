#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int **f_read(int *err, int *k_str);
int get_int(char *s, int *x);
void clear(int **arr, int end);
void print (int **arr, int k);
void del (int **arr, int k_str, int a);
int proga(int **arr, int k_str);
