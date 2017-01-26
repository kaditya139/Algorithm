#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char string[50],str[50];
    char a='a',b='b',x='x',y='y';
    int i=0,flag1=0,flag2=0,flag3=0,flag4=0;
    printf("Enter your string\t");
    scanf("%s",string);
    strcpy(str,string);
    while(str[i]!='\0'){
        flag3=0;
        if(str[i]==a && flag2==0){
            str[i]=x;
            i++;
            flag3=1;
        }
        while(str[i]!=b){
            i++;
            if(str[i]=='\0'){
                flag1=1;
                break;
            }
        }
        if(str[i]==b && flag3==1){
            str[i]=y;
            if(str[i+1]=='\0')
                flag2=1;
            i--;
        }
        if(flag1==0){
            while(str[i]!=x){
                if(flag3==1)
                    i--;
                else
                    i++;
                if(str[i]=='\0'){
                    break;
                }
            }
        }
        if(str[i]==x)
            i++;
    }
    i=0;
    while(str[i]!='\0'){
        i++;
        if(str[i]==a || str[i]==b){
            flag4=1;
            break;
        }
    }
    if(flag4==0)
        printf("String Follow the pattern of a^n b^n\n");
    else
        printf("String does not Follow the pattern of a^n b^n\n");
}
