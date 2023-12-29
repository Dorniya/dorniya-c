#include <stdio.h>

int main() 
{
    int arr[100], size, i;

 
    printf("Enter the size of the array: ");
    scanf("%d", &size);

   
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) 
	{
        scanf("%d", &arr[i]);
    }

 
    printf("Odd numbers in odd indices are: ");
    for (i = 1; i < size; i += 2) 
	{
        if (arr[i] % 2 != 0)
		 {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    return 0;
}
