#include "fun.h"

int **f_read (int *err, int *k_str){
	int **arr = NULL;
	FILE *in = fopen("1.txt", "r");
	char str[256];
	int  i , **a, *b, sum = 0, x, pos;


	if (in == 0){ 
		 (*err) = -1;
		 return arr;
	}
	while (!feof(in)){

	if (fgets(str, 256, in)!=NULL){
		(*k_str)++;
		//printf("2!");
		arr =  (int**)realloc(arr, sizeof(int*)*((*k_str) + 1));
		arr[(*k_str)]=NULL;
		//printf("3!");
/*		if (a == NULL){
			printf("2!");
			clear(arr, 0, (*k_str)-1);
			fclose(in);
			(*err) = -2;
			//printf("!");
			return arr;
		}
		arr = a;
*/		//printf("3!");	
		i = 0;
		sum = 0;
		while (pos = get_int(str+sum, &x), pos > 0){
			i++;
			sum = sum + pos;
//				printf("#x=%d  k_str=%d   i=%d\n",x, *k_str,i);
			printf("arr1 = %p\n",arr[(*k_str)]);
			arr[(*k_str)]=(int*)realloc(arr[(*k_str)], (sizeof(int))*(i + 1));
			printf("arr2 = %p\n",arr[(*k_str)]);

//			b=(int*)realloc(arr[(*k_str)], (sizeof(int))*(i + 1));

//			printf ("*+ %d\n", *k_str);
//			arr[(*k_str)] = (int*)realloc(arr[(*k_str)], (sizeof(int))*(i +1));
//			printf ("*-\n");
/*			if (b == NULL){
				clear(arr, 0, (*k_str));
				fclose(in);
				(*err) = -2;
				return arr;
			}
*/			printf("k = %d, b = %p\n",*k_str, b);
//			arr[(*k_str)] = b;
			arr[(*k_str)][i] = x;
		}
		if(pos == -1){
			printf("pos = -1\n"); 
	                clear(arr, 0, (*k_str));
	                fclose(in);
	                (*err) = -3;
			return arr;
		}
/*		if (i != 0)
			arr[(*k_str)][0] = i;
		else{
                         b=(int*)realloc(arr[(*k_str)], (sizeof(int))*1);
                         if (b == NULL){
	                         clear(arr, 0, (*k_str));
                                 fclose(in);
                                 (*err) = -2;
                                 return arr;
			}
			else
				arr[(*k_str)][0] = 0;
		}*/
//		printf ("!");
//		f_print(arr, (*k_str));
	}
	}
	fclose (in);
	return arr;
}

void clear (int **arr, int begin, int end){
	for (int i = begin; i <= end; i++)
		free (arr[i]);
}

int get_int(char *s, int *x){
	int pos;
	if (sscanf(s, "%d%n", x,&pos)== 1)
		return pos;
	if (sscanf(s,"%s", s) ==1)
		return -1;
	return 0;
}

/*int proverka_na_chislo(char *str){
	printf ("str = %d, size = %d",(int)sizeof(str)/(int)sizeof(char),(int)sizeof(char));
	for (int i = 0; i < (int)sizeof(str)/(int)sizeof(char); i++)
		if (str[i] < '0' || str[i] > '9'){
			printf("@%d@", i);
			return -1;
		}
	return 0;
}*/

void f_print (int **arr, int k){
//	printf("ololo\n");
//	printf("k=%d\n",k);
	for (int i = 0; i <= k; i++){
		for (int j = 1 ; j <= arr[i][0]; j++)
			printf ("(%d ", arr[i][j]);
		printf (")\n");
	}
}


int proga (int **arr, int k_str){
	int i=0, k, tmp, z_o=0, z_p=0,n, kol = 0;
	while(i <= k_str){
		k = 0; tmp = 0;
		while (k <= k_str && tmp == 0){
			if (i != k){
				if (arr[i][0] > arr[k][0])
					n = arr[k][0];
				else
					n = arr[i][0];
//				printf("n=%d\n", n);
				for (int j = 1; j <= n; j++){
					if (arr[i][j] - arr[k][j] > 0)
						z_p++;
					if (arr[i][j] - arr[k][j] < 0)
						z_o++;
//				 printf("p=%d o=%d k=%d i=%d\n",z_p,z_o,k,i);
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
//			printf("i = %d\n", i);
			f_del(arr, k_str, i);
			k_str--;
		}
		else i++;
		kol = 0;
	}

	return k_str;
}

void f_del(int **arr, int k_str, int a){
	free (arr[a]);
	for (int i = a+1; i <= k_str; i++){
		arr[i-1] = arr[i];
	}
}
