#include "fun.h"

int main (void){
	int **arr = NULL, k_str = -1;
	int err, k;
	arr = f_read(&err, &k_str);
	switch (err){
		case -1:
			printf ("NOT FILE\n");
			return 0;
			break;
		case -2:
			printf ("BAD DATA\n");
			return 0;
			break;
		case 0:
			print (arr, k_str);
			break;
	}
	k = proga (arr, k_str);
	printf("\n");
	print(arr, k);
	clear(arr, k);
	return 0;
}
