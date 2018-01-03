#pragma once

#include <stdlib.h>

/**     minimal dynamic array, this means that it allows operations:


    Memory:
1. Create array
2. Resize array
3. Delete array

    Content:
4. Get pointer to a given index(element)



*/

typedef struct TehArray TehArray;


struct TehArray
{
    size_t value_size;
    unsigned int capacity;

    void* ptr_to_zero_value;
};


    // Init and destruction
TehArray* teharray_new(const size_t value_size__, const unsigned int capacity__);
void teharray_delete(TehArray* const teharray__);
void teharray_resize(TehArray* const teharray__, const unsigned int desired_capacity__);

    // Access to array
void* teharray_getPointerToIndex(const TehArray* const teharray__, const unsigned int index__); // Because the pointer to index

