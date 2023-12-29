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
    int firstLargest = arr[0];
    int secondLargest = arr[0];

    for (i = 1; i < size; i++) 
	{
        if (arr[i] > firstLargest)
		 {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        } 
		else if (arr[i] > secondLargest && arr[i] < firstLargest)
		 {
            secondLargest = arr[i];
        }
    }

    printf("The 2nd largest element is: %d\n", secondLargest);

    return 0;
}
