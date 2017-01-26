//This code is for finding the LCM of two or more number. You have to provide the number of input and inputs to get the LCM.


#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,i;
    cout<<"Enter size of array"<<'\t';
    cin>>n;
    int store[n],factor[n];     //'store' stores the number povided by user. 
    for(i=0;i<n;i++)
        cin>>store[i];
    for(i=0;i<n;i++)
        factor[i]=1;
    int j,flag=0,l=0,max_num=0;
    for(i=0;i<n;i++){
        if(max_num<store[i])
            max_num=store[i];       //'max_num finds the maximum value in the array
    }
    i=2;
    while(i<=max_num/2){
        flag=0;
        for(j=0;j<n;j++){
            if(store[j]%i==0){
                flag++;          //'flag' variable is used for checking whether two or more number is divisibe by a particular number or not.
            }
        }
        if(flag>=2){
            for(j=0;j<n;j++){
                if(store[j]%i==0){
                    store[j]=store[j]/i;
                }
            }
            factor[l++]=i;          //If any number divides two or more number in array, it gets stored in 'factor' array.
        }
        else
            i++;
    }
    unsigned long long int product=1;
    for(i=0;i<n;i++)
        product=product*factor[i];
    for(i=0;i<n;i++)
        product=product*store[i];
    cout<<product<<'\n';            //Lastly finds product of both the array and dispay it.

    return 0;
}
