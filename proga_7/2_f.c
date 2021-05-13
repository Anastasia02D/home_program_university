#include "fun.h"

//int get_structur (FILE *file, struct student *s){

int get_structur (FILE *file, struct student *s){

	if (fscanf(file, "%s %d %f", s->name, s->group, s->rating) != 3);
                return -1;
	printf ("%s %d %f\n", s.name, &s.group, &s.rating);


	return 0;
}
