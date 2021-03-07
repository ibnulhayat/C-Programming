#include<stdio.h>
void input(int n, int arr[])
{
    printf("Enter data: ");
    int i;
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void output(int n, int arr[])
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;

        }
        arr[j + 1] = key;

        output(n,arr);
    }
}

int main()
{
    int arr[100], n;
    printf("How many inputs? ");
    scanf("%d", &n);
    input(n, arr);
    printf("\nBefore sorting: ");
    output(n, arr);

    insertionSort(arr, n);
    printf("\nAfter sorting: ");
    output(n, arr);
    return 0;
}
