#include <stdio.h>
#include "text.h"


int main() {
	
	FILE *fp;
	
	/* open file in read mode */
	fp = fopen("1342-0.txt", "r");
	
	/* pass the filepointer to txt2words */
	txt2words(fp);
	
	/* close the file */
	fclose(fp);
	
	
return 0;
}
