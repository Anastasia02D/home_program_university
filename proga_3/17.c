#include "fun.h"

int main (void){
	int **arr = 0, k_str = -1;
	int err;//,k;
	arr = f_read (&err, &k_str);
//	printf("err %d k = %d\n", err,k_str);
//	printf ("arr = %d\n", arr[1][1]);

	switch (err){
		case -1:
			printf ("Not file\n");
			return 0;
			break;
		case -2:
			printf ("Not enought memory\n");
			return 0;
			break;
		case -3:
			printf ("Bad data");
			return 0;
			break;
		default:{
//			printf ("like\n");
//			printf ("arr = %d\n", arr[1][1]);
			f_print (arr, k_str);
			break;
		}
	}

/*	k = proga(arr, k_str);
	if ((k_str != 0) && (k == 0)){
		free (arr[0]);
		k--;
	}
	printf("-----------\n");
	f_print(arr, k);
*/
	/*if (k_str != -1){
		clear (arr, 0, k_str);
	}*/
	clear(arr,0, k_str);
//	clear(arr,0, k);
	return 0;
}
