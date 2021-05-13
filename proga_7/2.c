#include <stdio.h>
#include <stdlib.h>


struct student{
	char *name;
	int group;
	float rating;
};

//int get_structur (FILE *file, struct student *s);


int get_structur (FILE *file, struct student *s){
	int res = 0;
	char * c;
	int g;
	float f;
        if (fscanf(file, "%ms%d%f", &(s->name), &(s->group), &(s->rating)) != 3)
//        res = fscanf(file, "%ms%d", &(s->name), &(s->group));
		printf("res = %d\n", res);
        //        return -1;
        printf ("%s %d %f\n", s->name, s->group, s->rating);


        return 0;
}


int main (void){
	struct student *s;
	int err;
	FILE *file1 = fopen("input.txt", "r");
	if (file1 == 0){
		printf ("Not file1\n");
		return 0;
	}
	err = get_structur (file1, &s);
	fclose(file1);
//	if (err == -1)
//		printf("ERROR\n");
//	else
//		printf ("%s %d %f\n", s.name, s.group, s.rating);
	if (s.name != NULL)
		free(s.name);
	return 0;
}

