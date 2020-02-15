struct universe {
    char **unipointer;
    int rows;
    int cols;

	char *array1d;

	//points to 
	struct universe *structpointer;

};

void read_in_file(FILE *infile, struct universe *u);
void write_out_file(FILE *outfile, struct universe *u);


