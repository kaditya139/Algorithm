#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,i;
    cout<<"Enter size of array"<<'\t';
    cin>>n;
    int store[n],factor[n];
    for(i=0;i<n;i++)
        cin>>store[i];
    for(i=0;i<n;i++)
        factor[i]=1;
    int j,flag=0,l=0,max_num=0;
    for(i=0;i<n;i++){
        if(max_num<store[i])
            max_num=store[i];
    }
    i=2;
    while(i<=max_num/2){
        flag=0;
        for(j=0;j<n;j++){
            if(store[j]%i==0){
                flag++;
            }
        }
        if(flag>=2){
            for(j=0;j<n;j++){
                if(store[j]%i==0){
                    store[j]=store[j]/i;
                }
            }
            factor[l++]=i;
        }
        else
            i++;
    }
    unsigned long long int product=1;
    for(i=0;i<n;i++)
        product=product*factor[i];
    for(i=0;i<n;i++)
        product=product*store[i];
    cout<<product<<'\n';

    return 0;
}
