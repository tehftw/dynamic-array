#include "include/TehArray.h"




TehArray* teharray_new(const size_t value_size__, const unsigned int capacity__)
{
    TehArray* new_teharray = malloc( sizeof(TehArray) );


    new_teharray->value_size = value_size__;
    new_teharray->capacity = capacity__;


    const size_t needed_memory_for_data = value_size__ * capacity__;
    new_teharray->ptr_to_zero_value = calloc(capacity__, value_size__);




    return new_teharray;
}


void teharray_delete(TehArray* const teharray__)
{
    free(teharray__->ptr_to_zero_value);
    free(teharray__);
}


void teharray_resize(TehArray* const teharray__, const unsigned int desired_capacity__)
{
    teharray__->capacity = desired_capacity__;


    const size_t needed_memory_for_content = desired_capacity__ * teharray__->value_size;


    realloc(teharray__->ptr_to_zero_value, needed_memory_for_content);
}



    //
void* teharray_getPointerToIndex(const TehArray* const teharray__, const unsigned int index__)
{
    if( index__ < teharray__->capacity )
    {
        // Because each value has length of value_size [bytes], and char points to a byte, we have to add value_size to move to the next index
        const size_t number_of_bytes_to_jump = teharray__->value_size * index__;


        void* const pointer_to_zero = teharray__->ptr_to_zero_value;

        char* pointer_to_index =   pointer_to_zero;
        pointer_to_index +=  number_of_bytes_to_jump;


        return pointer_to_index;
    }
    else
    {
        return 0;   // Out of bounds
    }
}












