#include <stdio.h>
#include "text.h"

/* read text from the file pointer, one line at a time */
struct node_struct *txt2words(FILE *fp) {
	
	if (fp != NULL) 
	{
		char book[1000];
		
		while (fgets(book, sizeof(book), fp))
		{
			fprintf(stdout, "%s", book);
		}
		
		fclose(fp);
	}
	
	
	else
	{
		printf("The file doesn't exist\n");
		return 0;
	}
		
return NULL;
}
	

