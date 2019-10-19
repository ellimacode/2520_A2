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
	
	/* points to actual array of text
	 * set to book */
	char *ptr = book;
	
	/* the one word in text that is being pointed to */
	char *word;
	
	/* check if file exist */
	if (fp != NULL) 
	{
		/* read one line of text at a time */
		while (fgets(book, sizeof(book), fp))
		{
			/* print out each line of text */
			fprintf(stdout, "%s", book);
			
			/* call ge_word and get address of the text */
			word = get_word(&ptr);
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
		
return 0;
}

/* helper function - take double pointer to string and returns
 * a malloced string containing the first word in input */
char *get_word(char **string) {
	
	/* holds first word in text */
	char *word;
	
	int i;
	
	/* counter variable */
	int count = 0;
	
	/* dereference double pointer once as *string - gets actual text */
	for (i = 0; (*string)[i] != '\0'; i++)
	{
		/* check if its a sequence of characters */
		if (isalpha((*string)[i]) != 0)
		{		
			/* to save enough space for chars of the word */
			word = realloc(word, (sizeof(char)*count) + (sizeof(char)));
			
			/* set single pointer to the sequence of characters
			 * for one word */ 
			word[count] = (*string)[i];
			
			count++;
			
			/* value of double pointer increments */
		    string++;
		     
		}
	
	}

return word;
}

/*void free_list(struct node *list, int free_data)
{
	if (list != NULL)
	{
		free_list(list->next);
		free(list);
	}
	
	else if (free_data > 0)
	{

	}
}*/

