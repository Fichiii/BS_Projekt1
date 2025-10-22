#include <stdio.h>



int binary_search(int *array, int target, int length){
    int left = 0;
    int right = length;

    while(left <= right){
        int mid = (left + right)/2;
        if(target == *(array + mid)) { return *(array + mid); }
        if(target < *(array + mid))
        {
            right = mid -1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}



int main(void){
    int array[] = {1,5,6,9,12,34,56,78,89,100};
    int length = sizeof(array) / sizeof(array[0]);
    int solution = binary_search(array,89, length);
    printf("%d\n", solution);

    return 0;
}