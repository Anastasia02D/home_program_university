#include "fun.h"

int **f_read(int *err, int *k_str){
	int **arr = NULL;
	FILE *file = fopen("1.txt" ,"r");
	char str[256], str_2[256];
	char *estr;
	int i, sum = 0, x, pos,len; 
//	printf("@");
	if (file == 0){
		printf ("!");
		(*err) = -1;
		return arr;
	}
	while (!feof(file)){
		estr = fgets(str, 256, file);
//		printf("!%s!!%s!!!\n", estr, str);
/*		if (str == "\n")
			printf("A\n");
		else
			printf("neA\n");
		printf("%s!\n",str);
*/		if (estr !=  NULL){
//		if (estr !=  NULL || str == "\n"){
			while (str[strlen(str)-1] != '\n' && !feof(file)) {
                                estr = fgets(str_2, 256, file);
                                memcpy(str, str_2, strlen(str_2));
			}
//			printf("bef");
			(*k_str)++;
			arr = (int**)realloc(arr, sizeof(int*)*((*k_str) + 1));
			arr [(*k_str)] = NULL;
			sum = 0;
			i = 0;
			while (pos = get_int(str+sum, &x), pos > 0){
				i++;
				sum = sum + pos;
				arr[(*k_str)] = (int*)realloc(arr[(*k_str)], sizeof(int)*(i+1));
				arr[(*k_str)][i] = x;
			}
			if (pos == -1){
				clear(arr, (*k_str));
				fclose(file);
				(*err) = -2;
				return arr;
			}
			if (i == 0)
				 arr[(*k_str)] = (int*)realloc(arr[(*k_str)], sizeof(int));
			arr[(*k_str)][0] = i;
		}
	}
	fclose (file);
	(*err) = 0;
	return arr;
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

