#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* this structure will represent your text, the attribute "data" will 
 * point to malloced memory holding a string of text followe by '\0'
 * character */
 
struct node_struct
{
	void *data;
	struct node_struct *next;
	
};

/* function prototypes */
struct node_struct *txt2words(FILE *fp);
struct node_struct *search(struct node_struct *list, char *target, int(*compar)(const void *, const void *));
struct node_struct *copy(struct node_struct *start, struct node_struct *end);
void ftext(FILE *fp, struct node_struct *list);
struct node_struct *sort(struct node_struct *list, int (*compar)(const void *, const void *));
void remove_repeats(struct node_struct *list, int (*compar)(const void *, const void *));
int length(struct node_struct *list);
void free_list(struct node_struct *list, int free_data);


