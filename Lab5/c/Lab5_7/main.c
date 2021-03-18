/*
This program read and output makefile characters as ASCII
NEED TO INCLUDE WHITESPACE
*/

#include <stdio.h>
#include<string.h>

int main()
{
    FILE *makefile = fopen("makefile","r");
    if(makefile == NULL)
    {
        printf("makefile don't exists.");
        return 1;
    }
    char words[10000]="";
    while(1)
    {
        char temp[100];
        int ret = fscanf(makefile, "%s", temp);
        if(ret == 1)
        {
            strcat(words, temp);
        }
        else if(ret == EOF)
        {
            break;
        }
    }
    fclose(makefile);
    printf("%s\n",words);
    for(int i=0;i<strlen(words);i++)
    {
        printf("%d\n",(int)words[i]);
    }
    return 0;
}
