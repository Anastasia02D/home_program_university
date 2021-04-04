#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
                                    
int **f_read (int *err, int *k_str);
void clear (int **arr, int begin, int end);
//int proverka_na_chislo(char *str);
void f_print (int **arr, int k);
int proga (int **arr, int k_str);
void f_del(int **arr, int k_str, int a);
int get_int(char *s, int *x);
