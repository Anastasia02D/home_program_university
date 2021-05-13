#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student{
        char *name;
        int group;
        float rating;
};

int proverka (char *str1, char *str2, int l){
	for (int i = 0; i < l; i++)
		if (str1[i]!= str2[i]){
			printf("i = %d\n", i);
			return -1;
		}
	return 0;
}

int main (void){
	int err = 0;
        struct student s1,s2;
        FILE *file1 = fopen("input1.txt", "r");
        if (file1 == 0){
                printf ("Not file1\n");
                return 0;
        }
	if (fscanf(file1, "%ms%d%f", &(s1.name), &(s1.group), &(s1.rating)) != 3){
		printf ("ERROR\n");
		if (s1.name != NULL)
                        free (s1.name);
		fclose(file1);
		return 0;
	}
	fclose(file1);
//	printf ("!%s! !%d! %f\n", s1.name, s1.group, s1.rating);


	FILE *file2 = fopen("input2.txt", "r");
        if (file2 == 0){
                printf ("Not file2\n");
		free(s1.name);
                return 0;
        }
        if (fscanf(file2, "%ms%d%f", &(s2.name), &(s2.group), &(s2.rating)) != 3){
                printf ("ERROR\n");
                if (s2.name != NULL)
                        free (s2.name);
                free(s1.name);
		fclose(file2);
                return 0;
        }
        fclose(file2);
//        printf ("!%s! !%d! %f\n", s2.name, s2.group, s2.rating);

	FILE *file3 = fopen ("output.txt", "w");

	if (strcmp(s1.name, s2.name) == 0 && s1.group == s2.group && s1.rating == s2.rating)
		fprintf(file3, "%s %d %f\n", s1.name, s1. group, s1.rating);
	else

		fprintf(file3, "No out student\n");
	fclose(file3);
/*	if (s1.name == s2.name)
                printf("YES name\n");
	if (s1.group == s2.group)
                printf("YES group\n");
*/


	free(s1.name);
	free(s2.name);

	return 0;
}

