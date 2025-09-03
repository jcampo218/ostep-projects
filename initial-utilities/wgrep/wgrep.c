#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
    if(argc==1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    char buffer[1024];
    char *target = argv[1];
    if(argc==2){
        while(fgets(buffer, sizeof(buffer), stdin) != NULL)
            if(strstr(buffer, target) != NULL)
                printf("%s", buffer);
    return 0;
    }
    FILE *fp = fopen(argv[2],"r");
    if(fp == NULL){
        printf("wgrep: cannot open file\n");
        exit(1);
    }

    while(fgets(buffer, sizeof(buffer), fp) != NULL)
        if(strstr(buffer, target) != NULL)
            printf("%s", buffer);
    fclose(fp);
    return 0;
}