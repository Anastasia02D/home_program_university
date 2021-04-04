#include <stdio.h>

int main (void){
	char a1[1] = "1", a2[5]="12 34";
	printf ("%d %d", (int)sizeof(a1),(int)sizeof(a2));
return 0;
}
