#include "fun.h"
#define N 256

int **f_read(int *err, int *k_str){
	int **arr = NULL;
	FILE *file = fopen("1.txt" ,"r");
	char *str = NULL, str_2[N];
	char *estr;
	int i, sum = 0, x, pos,len,j;
	unsigned long int n;
//	printf("@");
	if (file == 0){
//		printf ("!");
		(*err) = -1;
		return arr;
	}
	n = N;
	while (mygets(&str,&n , file)){
	//	printf("!!!\n");
		(*k_str)++;
		arr = (int**)realloc(arr, sizeof(int*)*((*k_str) + 1));
		arr [(*k_str)] = NULL;
		sum = 0;
		i = 0;
	//	printf("%s!\n", str);
		while (pos = get_int(str+sum, &x), pos > 0){
		//	printf("*%d* ", x);
			i++;
			sum = sum + pos;
			arr[(*k_str)] = (int*)realloc(arr[(*k_str)], sizeof(int)*(i+1));
			arr[(*k_str)][i] = x;
		}
//		printf("\n");

		if (pos == -1){
			clear(arr, (*k_str));
			fclose(file);
			(*err) = -2;
			free(str);
			return arr;
		}
		if (i == 0){
			arr[(*k_str)] = (int*)realloc(arr[(*k_str)], sizeof(int));
			arr[(*k_str)][0] = 0;
		}
		arr[(*k_str)][0] = i;
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

void clear(int **arr, int end){
	for (int i = 0; i <= end; i++)
		free(arr[i]);
	free (arr);
}

void print (int **arr, int k){
	for (int i = 0; i <= k; i++){
		for (int j = 1; j <= arr[i][0]; j++)
			printf ("%d ", arr[i][j]);
		printf ("\n");
	}
}

void del (int **arr, int k_str, int a){
	free (arr[a]);
        for (int i = a+1; i <= k_str; i++){
                arr[i-1] = arr[i];
        }
}



int proga(int **arr, int k_str){
	int i = 0, k ,tmp, z_o = 0, z_p = 0, n, kol = 0;
	while (i <= k_str){
		k = 0;
		tmp = 0;
		while (k <= k_str && tmp == 0){
			if (i != k){
				if (arr[i][0] > arr[k][0])
					n = arr[k][0];
				else
					n = arr[i][0];

				for (int j = 1; j <= n; j++){
					if (arr[i][j] - arr[k][j] > 0)
						z_p++;
	                                if (arr[i][j] - arr[k][j] < 0)
        	                        	z_o++;
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

