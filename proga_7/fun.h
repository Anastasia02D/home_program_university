#include <stdio.h>
#include <stdlib.h>

struct student{
        char *name;
        int group;
        float rating;
};

int get_structur (FILE *file, struct student *);
