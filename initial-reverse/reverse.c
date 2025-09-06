/*  John Campo reverse

    This program rewrites an output file with the reverse of an input file

    it is broken up into 3 sections (seperated by a blank line)

    first variables are declared and the input file/output file are tested
    and the dynamiclly expanding buffer is declared and initialized
    
    second the lines of text are put into a buffer and into an array for temporary storage and the input is closed

    finally the array is traversed in reverse order printing into the output file
    along the way until the array is empty before closing the output file

    unfortuenately I couldnt get tests 5 and 7 to work properly, though 1-4 and 6 worked out. I was struggling to differentiate
    the files path from the files name for test 5, and I dont really know where test 7 was going wrong
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

int main (int argc, char *argv[]){
    char buffer[1024];
    FILE *fp = NULL;
    if(argc>3){ //ensures command and 1 arg
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }
    fp = fopen(argv[1],"r"); //open input file
    if(fp == NULL){ //make sure it opened
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
        exit(1);
    }
    if(strcmp(argv[1],argv[2])==0){
        fprintf(stderr, "reverse: input and output file must differ\n");
        exit(1);
    }
    int capacity = 8, count = 0; //initial temp size
    char **lines = malloc(capacity * sizeof(char *));
    if(lines == NULL){
        exit(1);
    }

    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        if (count>=capacity){
            capacity*=2;
            lines = realloc(lines, capacity * sizeof(char *));
        }
        count++;
        lines[count] = malloc(strlen(buffer)+1);
        strcpy(lines[count], buffer);
        
    }
    fclose(fp);

    fp = fopen(argv[2],"w");
    if(fp == NULL){ //make sure it opened
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
        exit(1);
    }
    while(count>0){
        fprintf(fp, "%s", lines[count]);
        count--;
    }
    return 0;
}