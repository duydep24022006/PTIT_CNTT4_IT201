#include <stdio.h>

int main()
{
    int arr[] ={1,5,2,4,7,50,3,1,4,8,9};

    int max=arr[0];
    int strlen=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<strlen;i++)
    {
        if (max<arr[i])
        {
            max=arr[i];
        }
    }
    printf("%d\n",max);

}