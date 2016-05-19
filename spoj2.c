#include<stdio.h>
#include<string.h>
int main()
{
    char input[100], search[100];
    int i =0,j=0,fo;
    gets(input);
    gets(search);
  //  input[100] = "hello";
    //search[100] = "ell";
    while(input[i]!='\0'){
    while(input[i]!=search[0]&&input[i]!='\0')
        i++;
    if(input[i]=='\0'){
        printf("String not found\n");
        break;
        }
    fo = i;
    while(input[i]==search[j]&&input[i]!='\0'&&search[j]!='\0')
    {

        i++;
        j++;

    }
    if(search[j]=='\0'){
        printf("String Found at %d", fo+1);
        break;
        }
    if(input[i]=='\0'){
            printf("String Not found");
            break;
                        }
    i = fo+1;
    j=0;


}
}
