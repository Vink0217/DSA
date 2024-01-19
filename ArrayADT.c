#include <stdio.h>
#include <stdlib.h>


struct Array
{
    // fixed size array declared
    int A[10];

    // pointer to array
    // int *A;

    // storing maximum size of array
    int size;

    // storing number of elements in array/length of array containing elements
    int length;
};

// Display Array Elements
void displayarray(struct Array arr)
{
    // Best O(n); Worst O(1)

    int i;
    printf("\nNew Array: \n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

// Add Element at end of Array
void append(struct Array *arr, int item)
{
    // Best O(1)

    // Check if space exists in the array to append
    if (arr->length < arr->size)
        arr->A[arr->length] = item;
        arr->length++;
}

void insert(struct Array *arr, int index, int item)
{
    // Best: O(1); Worst: O(n)

    // Check if index is within array bounds
    // Start from last index +1 and traverse to input index -1
    // Update next index value with current index's value shifting to right by 1
    // Increase length of array

    int i;

    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = item;
        arr->length++;
    }
    else
    {
        printf("Insertion failed: Invalid index or Overflow Error.\n");
    }
}

void delete(struct Array *arr, int index)
{
    // Best: O(1); Worst: O(n)

    // Check if index is within array bounds
    // Start from input index till before last index - 1
    // Update current index value with next index's value
    // Reduce length of array

    if (index >= 0 && index <= arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        printf("\nDeleted element at index: %d", index);
    }
}

void linear_search(struct Array *arr, int key)
{
    // Best: O(1); Worst: O(n)

    // Check for key by iterating 1 by 1 over array and use flag for success/failed search

    int flag=1;
    for (int i = 0; i < arr->length;i++)
    {
        if (key == arr->A[i])
        {
            printf("\nElement %d found at index: %d", key, i);
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\nElement %d not found.", key);
    }
}

void binary_search(struct Array *arr, int key)
{
    // Best: O(1), Worst: O(log n) [successful/failed search]

    // Input Array must be sorted
    // Keep track of lowest, highest and middle index in array
    // Check whether key = middle index element
    // Update low/high index to mid + 1/mid - 1 if element at mid index > key / < key
    // Check until low <= high since when low exceeds high it means element doesn't exist

    int l = arr->A[0];
    int h = arr->length - 1;
    int flag = 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (key == arr->A[mid])
        {
            printf("\nElement %d found at: %d", key, mid);
            flag = 0;
            break;
        }
        else if(key > arr->A[mid])
        {
            l = mid + 1;
        }
        else if(key < arr->A[mid])
        {
            h = mid - 1;
        }
    } 
    if (flag == 1)
    {
        printf("\nElement %d not found.", key);
    }

}

void get(struct Array *arr, int index)
{
    // Worst: O(1)
    if (index>=0 && index<arr->length)
    {
        printf("Data: %d", arr->A[index]);
    }
}

void set(struct Array *arr, int index, int data)
{
    // Worst: O(1)
    if (index>=0 && index<arr->length)
    {
        arr->A[index] = data;
    }
}

void sum(struct Array arr)
{
    // Worst: O(n)
    int total = 0;
    for (int i = 0; i > arr.length; i++)
    {
        total += arr.A[i];
    }
    return total;
}

void avg(struct Array arr)
{
    // Worst: O(n)
    
    return Sum(arr)/arr.length;

}

int max(struct Array *arr)
{
    // Worst: O(n)
    int max = arr->A[0];
    for (int i = 1; i < arr->length;i++)
    {
        if (arr->A[i]>max)
        {
            max = arr->A[i];
        }
    }
    return max;
}

int min(struct Array *arr)
{
    // Worst: O(n)
    int min = arr->A[0];
    for (int i = 1; i < arr->length;i++)
    {
        if (arr->A[i]>max)
        {
            min = arr->A[i];
        }
    }
    return min;
}

void reverse(struct Array *arr)
{
    int *B;
    int i, j;
    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length-1, j = 0; i >= 0;i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (i = 0;  i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
    printf("Array Reversed");
}

void reverse_inplace(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j;i++,j--)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
    printf("Array Reversed in Place.");
}

void lshiftandrotate(struct Array *arr)
{
    int i;
    int temp = arr->A[0];
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = temp;
}

void rshiftandrotate(struct Array *arr)
{
    int i;
    int temp = arr->A[arr->length - 1];
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i+1] = arr->A[i];
    }
    arr->A[0] = temp;
}

void InsertSort(struct Array *arr, int data)
{
    // Insert element within a sorted array
    int i = arr->A[arr->length] - 1;
    while (i >= 0 && arr->A[i] > data)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = data;
    arr->length++;
}

void SeparatePosNeg(struct Array *arr)
{
    // Worst: O(n)
    // Separate positive values on the right side and negative values on the left side
    int j = arr->length - 1;
    int i = 0;
    // Run until left is less than right
    while (i < j)
    {
        // Move left counter forward until a negative number is found
        while (arr->A[i]<0)
            i++;
        // Move right counter backward until a positive number is found
        while (arr->A[i]>=0)
            j--;
        // Swap the positive and negative numbers
        if (i < j)
        {
            int temp = arr->A[j];
            arr->A[j] = arr->A[i];
            arr->A[i] = temp;
        }
    }
}

int isSorted(struct Array *arr)
{
    // Worst: O(n)
    for (int i = 0; i < arr->length - 1;i++)
    {
        if (arr->A[i] > arr->A[i+1])
        {
            return 0;
        }
    }
    return 1;
}

int Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k= 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k] = arr1->A[i];
            k++;
            i++;
        }
        else
        {
            arr3->A[k] = arr2->A[j];
            k++;
            j++;
        }
    }
    // Extra elements in either arrays after comparison
    for (; i < arr1->length;i++)
    {
        arr3->A[k] = arr1->A[i];
        k++;
    }
    for (; j < arr2->length;j++)
    {
        arr3->A[k] = arr1->A[j];
        k++;
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 20;
    return arr3;
}

int array_union(struct Array *arr1, struct Array *arr2)
{
    // O(n^2); Sorted Arrays: θ(m+n) <=> θ(n)
    int i, j, k;
    i=j=k= 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k] = arr1->A[i];
            k++;
            i++;
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            arr3->A[k] = arr2->A[j];
            k++;
            j++;
        }
        else
        {
            arr3->A[k] = arr1->A[i];
            k++;
            i++;
            j++;
        }      
    }
    // Extra elements in either arrays after comparison
    for (; i < arr1->length;i++)
    {
        arr3->A[k] = arr1->A[i];
        k++;
    }
    for (; j < arr2->length;j++)
    {
        arr3->A[k] = arr1->A[j];
        k++;
    }
    arr3->length = k;
    arr3->size = 20;
    return arr3;
    
}

struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    // Checking for unequal elements by comparing greater or less than each other
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;

    // Appending equal elements to arr3
        else if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array));
    // Comparing elements of set 1 w/ set 2 and only appending unequal set 1 elements
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];

    arr3->length=k;
    arr3->size=10;
    return arr3;
}


int main()
{
// Initializing Array

/*
    // Dynamic Array
    struct Array arr;

    printf("Enter maximum size of array: ");
    scanf("%d", &arr.size);

    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    // Taking Array Input
    printf("\nEnter the number of elements you want to enter: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &arr.A[i]);
        
    }
    // Storing Number of Elements
    arr.length = n;
*/

    int n, index, pos, i, item;

    // Static Array
    struct Array arr = {{2, 6, 10, 15, 25}, 10, 5};

    struct Array arr2 = {{3, 4, 7, 18, 20}, 10, 5};

    struct Array arr3;

    displayarray(arr);

    append(&arr, 8);

    insert(&arr, 3, 23);
    displayarray(arr);

    delete(&arr, 4);
    displayarray(arr);

    linear_search(&arr, 8);

    binary_search(&arr, 24);

    return 0;
}
