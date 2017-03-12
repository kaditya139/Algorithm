/* This is an invariant of Binary Search which requires data to be sorted. Here, the difference from binary search is that binary Search
limits the range by dividing 2 whereas in this we search number with checking and comparing with number found on random index.
I can't say, it is better or worse than binary search but it one of my own approach. */
#include<stdio.h>
#include<time.h>
int main(){
    srand(time(NULL));
    int i, j, temp, n = 10, search = 20;                    // We have to search that is 20 exist in the given set of number
    int arr[] = {8, 10, 20, 14, 9, 7, 12, 18, 4, 21};       // Let we are having these 10 numbers
    for (i = 0; i < 10; i++){
        for (j = 0; j < i; j++){
            if (arr[i] < arr[j]){
                temp = arr[j];                                 //Here in this block , I performed bubble sort operation
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    int p, k = 1, flag = 0, min = 0, max = (n-1), diff;
    p = rand() % (max);

    if (arr[0] == search){
        p = 0;
        k = 0;
        flag = 1;
    }
    if (arr[n-1] == search){
        p = (n - 1);
        k = 0;
        flag = 1;
    }                                                   // In these two condition I checked if number is at first or last index
    while ( k ){
        if (arr[p] > search){
            max = p;
            diff = max - min - 1;
            p = (rand() % diff) + min + 1;    // If number is smaller that found on generated index , it will search in left side
        }
        if (arr[p] < search){
            min = p;
            diff = max - min - 1;
            p = (rand() % diff )+ min + 1;     // If number is larger that found on generated index , it will search in right side
        }
        if (arr[p] == search) {
            flag = 1;                   // If number is found on generated index , set flag to 1 and will break the loop
            break;
        }
        if (((p == (min + 1)) && (arr[p] > search)) || ((p == (max - 1))) && (arr[p] < search))
            break;                      // If number is not in the list , it will simply break the loop without modifying flag
    }
    if (flag == 1)
        printf ("%d is found at %d location\n", search, p+1);
    else
        printf ("%d is not found\n", search);       // Value of flag is 1 indicates that number found else not

    return 0;
}
