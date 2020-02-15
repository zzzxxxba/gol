#include<stdio.h>
#include"gol.h"
#include"gol.c"

int main(int argc, char *argv[]){
  struct universe u;
  struct universe v;

  //u's struct pointer points to the v
  u.structpointer = &v;
  FILE infile;

  read_in_file(&infile, &u);
  FILE *outfile;
  
  outfile = fopen("test.txt","w+");
  write_out_file(outfile,&u);

  return 0;
}
