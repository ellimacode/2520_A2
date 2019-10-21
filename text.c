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
	
	struct node_struct *head, **current;
	
	/* check if file exist */
	if (fp != NULL) 
	{
		/* read one line of text at a time */
		while (fgets(book, sizeof(book), fp))
		{
			/* print out each line of text */
			fprintf(stdout, "%s", book);
			
			/* call get_word and get address of the text */
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
	
	current = &head; 
	
	while (current != NULL)
	{
		*current = malloc(sizeof(struct node_struct));
		(*current)->data = &ptr;
		current = &((*current)->next);
		
	}
	
	*current = NULL;
	
	
return head;
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
		if (isalpha((*string)[i]) != 0 || isdigit((*string)[i]) != 0)
		{		
			/* to save enough space for chars of the word */
			word = realloc(word, sizeof(char)*count + sizeof(char));
			
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

/* search function - run the compar with data and target,  */
struct node_struct *search(struct node_struct *list, char *target, int(*compar)(const void *, const void *))
{
	while (list != NULL)
	{
		/* advance the pointer to next item in list */
		list = list->next;
		
		/* if compar function returns 0, node is considered found */
		if (compar(list->data, target) == 0)
		{
			
		}
		
	}

return 0;	
}

/* ftext - print out strings pointed to by data */
void ftext(FILE *fp, struct node_struct *list)
{
	while (list != NULL)
	{
		/* print the data attribute of the structure pointed
		 * to by the list */
		fprintf(fp, "%s", ((char*)list->data));
		
		/* advance pointer to point to next item in list */
		list = list->next;
	}
}

/* length function - returns number of nodes in the list */
int length(struct node_struct *list)
{
	/* counter variable */
	int count = 0;
	
	struct node_struct *current = list;
	
	while (current != NULL)
	{
		/* increment count for each node in list */
		count++;
		current = current->next;
	}
	
return count;	
}

/* free function */
void free_list(struct node_struct *list, int free_data)
{
	/* free contents of list first */
	if (list != NULL)
	{
		free(list->next);
		
	}
	
	/* free entire list */
	free(list);
	
	if (free_data != 0)
	{
		free(list->data);
	}
	
	
}

