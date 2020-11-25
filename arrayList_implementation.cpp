// arrayList_implementation.cpp   Exercise 5  Q.5.
//
// Implement a Dynamic Array data structure (like Java's ArrayList or C++'s vector)
// that will expand in size when required.
// Notice that the array elements are stored in a dynamically allocated array
// which is allocated from Heap memory.
// 
// Later, we will implement this more elegantly as a SmartArray class.

#include <iostream>
using namespace std;

const int initialCapacity = 4;  // initial size for the internal array
const int growthFactor = 2;     // double in size at each expansion

// struct member data are public by default, so can be accessed directly.
// this struct defines information about the arrayList, but the elements
// are stored in the array block of memory pointed at by arrayPtr.
struct arrayListStruct {
    int* arrayPtr;  // pointer to start of array of int (Dynamically Allocated)
    int count;      // count of the number of elements in the array currently
    int capacity;   // total number of slots in the array (actual size of the array)
};

/* Note that a pointer member is required to point at the array block.
   A reference can not be used as we need to change the value of the pointer 
   to point at a new array block when the array needs to grow.*/

void initialize(arrayListStruct& arrayList)
{
    arrayList.arrayPtr = new int[initialCapacity]; // allocate a new block of memory 
    arrayList.capacity = initialCapacity; // capacity for N elements
    arrayList.count = 0;    // number of values in the array initially
}

void display(arrayListStruct& arrayList) 
{
    cout << "Capacity: " << arrayList.capacity << endl;
    cout << "Count of number of values: " << arrayList.count << endl;
    cout << "Array contents: ";

    for (int i = 0; i < arrayList.count; i++)
        cout << arrayList.arrayPtr[i] << ",";

    cout << endl;
}

void addElement(arrayListStruct& arrayList, int value)
{
    if (arrayList.count >= arrayList.capacity)  // at full capacity, so need to grow
    {
        int* newArrayPtr = new int[arrayList.capacity * growthFactor];  // dynamic memory allocation (from Heap)
        
        for (int i = 0; i < arrayList.count; i++)
            newArrayPtr[i] = arrayList.arrayPtr[i];   // copy data to new array

        arrayList.capacity *= 2;  // set the new capacity value

        delete[] arrayList.arrayPtr;   // free old memory (forgetting this will cause a memory leak)

        arrayList.arrayPtr = newArrayPtr;   // assign pointer to point at new array

        arrayList.arrayPtr[arrayList.count] = value; // add the new value 
        arrayList.count++;

        cout << "*** Expanding array to size: " << arrayList.capacity << endl;
    }
    else  // else, there is free space, so simply insert the new value
    {
        arrayList.arrayPtr[arrayList.count] = value;
        arrayList.count++;
    }
}

void pack(arrayListStruct& arrayList)   // reduce capacity of array to minimum
{
    cout << "pack() called...\n";
    if (arrayList.count < arrayList.capacity)  // if there are unused slots in array, then shrink it
    {
        int* newArrayPtr = new int[arrayList.count];   // allocate just enough space for all the elements

        for (int i = 0; i < arrayList.count; i++)
            newArrayPtr[i] = arrayList.arrayPtr[i];   // copy data to new array

        arrayList.capacity = arrayList.count;  // double the capacity
        
        // the arrayList.count does not change

        delete[] arrayList.arrayPtr; // free old memory block

        arrayList.arrayPtr = newArrayPtr;  // assign the new 'exact size' array
 
        cout << "--- Shrinking array to size: " << arrayList.capacity << endl;

    }
}

// get element at index position 'i'
//
int get(arrayListStruct& arrayList, int i) {
    return arrayList.arrayPtr[i];
    // we should really check that the index i is less than the count !!
}

int main()
{
    cout << "**** ArrayList/vector like data structure ****\n";

    arrayListStruct myArrayList;
    initialize(myArrayList);

    addElement(myArrayList, 2);
    addElement(myArrayList, 4);
    addElement(myArrayList, 6);
    addElement(myArrayList, 8);
    display(myArrayList);

    addElement(myArrayList, 10);
    addElement(myArrayList, 12);
    display(myArrayList);

    addElement(myArrayList, 14);
    addElement(myArrayList, 16);
    display(myArrayList);

    addElement(myArrayList, 18);
    addElement(myArrayList, 20);
    display(myArrayList);

    pack(myArrayList);
    display(myArrayList);

    int n = get(myArrayList, 4);
    cout << "Element at index position 4 is: " << n << endl;

    n = get(myArrayList, 10);
    cout << "Element at index position 10 is: " << n << endl;
    // if there is no value set at index position 10, we may get a garbage value
}