#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void read_in_file(FILE *infile,struct universe *u) {
	infile = fopen( "input.txt", "r" );

	if (infile == NULL )//check if the file is NULL
		printf("Empty file\n");


	//used to print out the file
	char firstline[512];
	char oneline2[512];

	//used to get a line from the file to get the colnum
	fscanf(infile,"%s",oneline2);

	//count the number of rows by incrementing a variable within the while loop

	int characters=0;
	int colnum;
	int rownum;
	int i;
	int j;

	//The column number is the number of all characters in a line
	colnum = strlen(oneline2);

	//while loop iterates till EOF
	while( fscanf(infile,"%c",firstline ) != EOF )
    {
    	characters = characters+1;
    }

    //calculate the row number by dividing it by the number of columns
    rownum = characters/colnum;

	// pointer to the universe values
	u->cols = colnum;
	u->rows = rownum;

    //create a list of pointers in the memory and dynamically allocate space for the universe

    char *arr[rownum];
	char *arr2[rownum];

    for (i=0;i<rownum;i++){
    	arr[i] =  (char *)malloc(colnum*sizeof(char));
		arr2[i] = (char *)malloc(colnum*sizeof(char));
    }

    char singleline[colnum];

    //set the pointer back to the beginning
	fseek(infile,0L,SEEK_SET);

    //enter all the data in to the memory locations
    for (i=0; i<rownum; i++){
    	fscanf(infile,"%s",singleline);
    	for (j=0;j<colnum;j++){
    		arr[i][j]=singleline[j];
			arr2[i][j]=singleline[j];
    	}
    }

    u->unipointer = arr;
	u->structpointer->unipointer = arr2; // u's points to v, and set v's array to the arr

	fclose(infile);

}

void write_out_file(FILE *outfile, struct universe *u){	
	printf("inside write out file");
	printf("%c",u->unipointer[0][0]);

}
