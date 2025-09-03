#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
    char buffer[512];
    FILE *fp = NULL;
    if(argc<1)//no args is illegal
        exit(0);
    for(int i = 1 ; i<argc ; i++){ //for each arg
        fp = fopen(argv[i],"r");
        if(fp == NULL){
            printf("wcat: cannot open file\n");
            exit(1);
        }
        while(fgets(buffer, sizeof(buffer), fp) != NULL)
                    printf("%s", buffer);
        fclose(fp);
    }
    return 0;
}