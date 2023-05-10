#include <iostream>

void selectionsort(int arr[], int size);
void bubblesort(int arr[], int size);
int linearsearch(int arr[], int size);
int binarysearch(int arr[], int size);
void swap(int arr[], int first, int second);
void printarr(int arr[], int size);

int main ()
{
    int n;
    std::cout << "Enter the number of elements in array: " << std::endl;
    std::cin >> n;
    int arr[n];

    // Entering the elements in the array
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    // Sorting the array
    bubblesort(arr, n);
    printarr(arr, n);

    // Searching an element
    int index = binarysearch(arr, n);

    if (index == -1)
    {
        std::cout << "Not found" << std::endl;
    }
    else
    {
        std::cout << "Found at index " << index << std::endl;
    }
    return 0;
}

// Sorting using Selection sort
void selectionsort(int arr[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int j = step + 1; j < size; j++)
        {
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;

            }
        }
        swap(arr, min_idx, step);
    }
}

// Sorting using Bubble sort
void bubblesort(int arr[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        for (int i = 0; i < size - step - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, i+1);
            }
        }
    }

}

// Searching using Linear search
int linearsearch(int arr[], int size)
{
    int ele;
    std::cout << "ele you want you find: ";
    std::cin >> ele;
    std::cout << '\n';

    for (int i = 0; i < size; i++)
    {
        if (ele == arr[i])
        {
            return i;
        }
    }

    return -1;
}

// Searching using Binary search
int binarysearch(int arr[], int size)
{
    int first = 0;
    int last = size - 1;
    int middle = (first + last) / 2;
    int key;
    std::cin >> key;

    while (first != last)
    {
        if (arr[middle] == key)
        {
            /* std::cout << "The ele is at index " << middle << std::endl; */
            return middle;
        }
        else
        {
            if (arr[middle] > key)
            {
                last = middle - 1;
            }
            else
            {
                first = middle + 1;
            }
            middle = (first + last) / 2;
            
        }
    }
    
    return -1;
}

// Printing the array yum
void printarr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

// swap func even tho it exists hehe imma kms
void swap(int arr[], int first, int second)
{
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;

}
