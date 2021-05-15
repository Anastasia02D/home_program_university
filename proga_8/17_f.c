#include "fun.h"

void add_element(int data, spisok *head){
        spisok *p = head;
        spisok *tmp = (spisok*)malloc(sizeof(spisok));
        tmp -> value = data;
        tmp -> next = NULL;

        while (p -> next != NULL)
                p = p -> next;
        p -> next = tmp;
}


spisok **f_read(int *err, int *k_str){
        spisok **arr = NULL;
        FILE *file = fopen("1.txt" ,"r");
        char *str = NULL;
        char *estr;
        int i, sum = 0, x, pos,len,j;
        unsigned long int n;

        if (file == 0){
                (*err) = -1;
                return arr;
        }
        n = N;
        while (mygets(&str, &n , file)){
                (*k_str)++;
                arr = (spisok**)realloc(arr, sizeof(spisok*)*((*k_str) + 1));
                arr [(*k_str)] = (spisok*)malloc(sizeof(spisok));
                arr[(*k_str)] -> next = NULL;
                sum = 0;
                i = 0;
                while (pos = get_int(str+sum, &x), pos > 0){
                        i++;
                        sum = sum + pos;
                        add_element(x, arr[(*k_str)]);
//                      print (arr, *k_str);
                }
                if (pos == -1){
                        clear(arr, (*k_str));
                        fclose(file);
                        (*err) = -2;
                        free(str);
                        return arr;
                }
                free (str);
                str = NULL;
        }
        fclose (file);
        (*err) = 0;
        return arr;
}


char *mygets(char **str, unsigned long int *LMax, FILE *in){
        int begin=0;
        if(!*str)
                *str=(char *)malloc(*LMax);
        while(fgets(*str+begin,*LMax-begin,in)){
                begin=*LMax-1;
                if(strchr(*str,'\n'))
                        break;
                (*LMax)*=2;
                (*str)=(char *)realloc(*str,*LMax);
        }
        if(begin==0){
                free(*str);
                return NULL;
        }
        return *str;

}


int get_int(char *s, int *x){
        int pos;
        if (sscanf(s, "%d%n", x,&pos) == 1)
                return pos;
        if (sscanf(s, "%s", s) == 1)
                return -1;
        return 0;
}

void clear(spisok **head, int k){
        spisok *p;
        for (int i = 0; i <= k; i++){
                while (head[i] != NULL){
                        p = head[i];
                        head[i] = head[i] -> next;
                        free (p);
                }
        }
        free (head);
}


void print (spisok **arr, int k){
        spisok *p;
        for (int i = 0; i<= k; i++){
                p = arr[i] -> next;
                while (p != NULL){
                        printf ("%d ", p -> value);
                        p = p -> next;
                }
                printf ("\n");
        }
}

void del (spisok **head, int k_str, int a){
        spisok *p;
        while (head[a] != NULL){
                p = head[a];
                head[a] = head[a] -> next;
                free (p);
        }

        for (int i = a+1; i <= k_str; i++){
                head[i-1] = head[i];
        }
}


int proga(spisok **arr, int k_str){
        int i = 0, k ,tmp, z_o = 0, z_p = 0, kol = 0;
        spisok *s_i, *s_k;
        while (i <= k_str){
                k = 0;
                tmp = 0;
                while (k <= k_str && tmp == 0){
                        if (i != k){
                                s_i = arr[i] -> next;
                                s_k = arr[k] -> next;
                                while (s_k != NULL && s_i != NULL){
                                        if (s_k -> value - s_i -> value > 0)
                                                z_p++;
                                        if (s_k -> value - s_i -> value < 0)
                                                z_o++;
                                        s_k = s_k -> next;
                                        s_i = s_i -> next;
                                }
                                if ((z_o != 0) && (z_p != 0))
                                        kol++;
                                else
                                         tmp = -1;
                                z_p = 0; z_o = 0;
                        }
                        k++;
                }
                if (kol == k_str){
                        del(arr, k_str, i);
                        k_str--;
                }
                else
                        i++;
                kol = 0;
        }
        return k_str;
}
