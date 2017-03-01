/* This program is to multiply very large number. You can even multiply two number having 500 digits or even higher
(even number can be of lacs digits). Since no any type of variable can store such large number. So I used array of integer
to store and multiply such large numbers. This program runs in time complexity of O(m*n) where m and n is the number of digit
in the number which needs to be multiplied.*/

#include<stdio.h>
int main(){
    int m,n,i,j;
    printf("Enter Length of First and Second number :\t");    //Enter size of number
    scanf("%d%d",&m,&n);
    int s=m+n;
    int num1[m],num2[n],result[s];
    printf("Enter First Number \t");    //Enter digit of first number one by one
    for(i=0;i<m;i++)
        scanf("%d",&num1[i]);
    printf("Enter Second Number \t");   //Enter digit of second number one by one
    for(i=0;i<n;i++)
        scanf("%d",&num2[i]);
    for(i=0;i<s;i++)
        result[i]=0;

    int k,rem=0,carry=0,mult=0,l;
    for(j=n-1;j>=0;j--){
        k=s-(n-j);
        for(i=m-1;i>=0;i--){
            mult=num1[i]*num2[j];
            int temp=result[k]+mult+carry;
            rem=temp%10;
            result[k]=rem;
            carry=temp/10;
            k--;
        }
        result[k]=carry;
        carry=0;
    }
    for(i=0;i<s;i++)
        printf("%d",result[i]);
    printf("\n");
    return 0;
}
