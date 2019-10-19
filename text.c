#include <stdio.h>
#include "text.h"

/* Full Name: Camille Cua
 * Student ID: 1046663
 * Email: ccua@uoguelph.ca */

/* function will split each line into words, allocating a string for each word
 * and storing the address of the string in the data pointer */
struct node_struct *txt2words(FILE *fp) {
	
	/* string represents the text */
	char book[256];
	
	/* check if file exist */
	if (fp != NULL) 
	{
		/* read one line of text at a time */
		while (fgets(book, sizeof(book), fp))
		{
			/* print out each line of text */
			fprintf(stdout, "%s", book);
		}
		
		/* close the file */
		fclose(fp);
	}
	
	/* if doesn't exist */
	else
	{
		printf("The file doesn't exist\n");
		return 0;
	}
		
return NULL;
}

/* helper function - take double pointer to string and returns
 * a malloced string containing the first word in input */
char *get_word(char **string) {
	
	/* single pointer */
	char *word;
	
	/* malloced string */
	word = malloc(sizeof(char)*256);
	
	/* double pointer points to beginning of next word */
	

	
return word;
}

//void free_list(struct node *list, int free_data)
//{
	//if (list != NULL)
	//{
		//free_list(list->next);
		//free(list);
	//}
	
	//else if (free_data > 0)
	//{

	//}
//}

