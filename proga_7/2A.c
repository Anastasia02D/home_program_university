#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student{
        char *name;
        int group;
        float rating;
};

struct student *get_structur(FILE *file, int *err){
	struct student *s_st = NULL;
	s_st =  (struct student *) malloc(sizeof(struct student));
	s_st->name =NULL;
	if (fscanf(file, "%ms", &(s_st->name)) != 1){
		if (!feof(file)){
			(*err) = -1;
//			printf ("no finish file\n");
		}
		(*err) = -2;
	}
	if ((*err) == 0 && fscanf(file, "%d%f",  &(s_st->group), &(s_st->rating)) != 2){
//		printf("no 2 chisla\n");
		(*err) = -1;
	}
	if ((*err) != 0){
		if (s_st->name != NULL)
			free (s_st->name);
		free(s_st);
		return NULL;
	}

	return s_st;
}

struct student ** get_mass(FILE *file, int *err, int *i){
	struct student **s = NULL;
	struct student *tmp = NULL;
	int err_get = 0,j;
//	printf("xa\n");
	while ((!feof(file)) && (err_get == 0)){
//		printf("!\n");
//		printf("do\n");
		tmp = get_structur (file, &err_get);
//		printf("posle\n");
		if (err_get == 0){
			(*i)++;
//			printf("do2\n");
			s = (struct student **)realloc(s, ((*i) + 1) * sizeof(struct student *));
//			if (s == NULL)
//				printf("NO MEMORY\n");
//			s = (struct student **) realloc(s, sizeof(struct student *)*((*i)+1));
//			printf("Da %d\n",j);
//			printf ("%s\n",  s[(*i)]->name );
			s[(*i)] = tmp;
//			printf("%s %d %f\n", s[(*i)]->name,s[(*i)]->group, s[(*i)]->rating);
//			err_get = -1;
		}
	}
//	printf("%d\n", err_get);
	if (err_get == 2)
		err_get = 0;
	(*err) = err_get;
	return s;
}


void print_structur (struct student **s, int kol){
	for (int i = 0; i < kol; i++)
		printf ("%s %d %f\n", s[i]->name, s[i]->group, s[i]->rating);
	printf("\n");
}

void print_structur_file (FILE *file, struct student **s, int kol){
        for (int i = 0; i < kol; i++)
                fprintf (file,"%s %d %f\n", s[i]->name, s[i]->group, s[i]->rating);
        fprintf(file,"\n");
}


void clear(struct student **s, int kol){
	for (int i = 0; i < kol; i++){
		free(s[i]->name);
		free(s[i]);
	}
	free(s);
}

void del(struct student **s, int kol, int a){
	free(s[a]->name);
	free(s[a]);
	for (int i = a+1; i < kol; i++)
		s[i-1] = s[i];
}

void new_god(struct student **s1, struct student **s2, int *kol, int kol2){
	int tmp = 0, kol1 = (*kol);
	for(int i = 0; i < kol2; i++){
		for (int j = 0; j < kol1; j++){
			if (strcmp(s1[j]->name, s2[i]->name) == 0 && s1[j]->group == s2[i]->group && s1[j]->rating == s2[i]->rating){
				del(s1, kol1, j);
				kol1 --;
			}
		}
	}
	(*kol) = kol1;
}

int main (void){
        struct student **s1 = NULL, **s2 = NULL;
        int err = 0, kol1 = -1, kol2 =-1;
        FILE *file1 = fopen("input1.txt", "r");
        if (file1 == 0){
                printf ("Not file1\n");
                return 0;
        }
        s1 = get_mass (file1, &err, &kol1);
	kol1++;
	fclose(file1);
	if (err == -1){
		printf ("ERROR\n");
		clear (s1, kol1);
		return 0;
	}
	if (s1 != NULL)
		 print_structur(s1, kol1);
	else{
		printf ("No students\n");
		return 0;
	}


	err = 0;

	FILE *file2 = fopen("input2.txt", "r");
        if (file2 == 0){
                printf ("Not file2\n");
		clear (s1, kol1);
                return 0;
        }
        s2 = get_mass (file2, &err, &kol2);
	fclose(file2);
        kol2++;
        if (err == -1){
                printf ("ERROR\n");
		clear (s1, kol1);
		clear (s2, kol2);
                return 0;
        }
        if (s2 != NULL)
                 print_structur(s2, kol2);
        else{
                printf ("No students\n");
                return 0;
        }

	new_god(s1, s2, &kol1, kol2);
	print_structur(s1, kol1);

	FILE *file3 = fopen("output.txt", "w");
		print_structur_file(file3, s1, kol1);
	fclose(file3);
	clear (s1, kol1);
	clear (s2, kol2);
	return 0;
}
