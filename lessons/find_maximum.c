#include <stdio.h>

int find_maximum(int array[], int n)
{
    int max = array[0];
    int index = 1;
    while(index < n)
    {
        int num = array[index];
        if(num > max) max = num;
        index++;
    }
    return max;
}

int main()
{
    int array[]={1, -3, 5, 2};
    int maximum = find_maximum(array, 4);
    printf("The maximum is %d\n",maximum);
    return 0;
}
