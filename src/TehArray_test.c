#include "include/TehArray_test.h"

static void test_TehArray_getPointer(void);

void test_TehArray_performTest(void)
{
    printf("\n\tPerforming tests of TehArray. ");

    test_TehArray_getPointer();


}




static void test_TehArray_getPointer()
{
    printf(" The test has to test against cases: ");
    printf("\n  2.1. index = 0");
    printf("\n  2.2. index = somewhere in the middle");
    printf("\n  2.3. index = capacity");
    printf("\n  2.4. index out of capacity");

    const size_t value_size = sizeof(double);
    const unsigned int capacity = 10;
    const double test_double = 2.71;

    printf("\n Creating a TehArray of %d doubles(sizeofvalue: %d). Created array: ", capacity, value_size);
    TehArray *testarray = teharray_new(value_size, capacity);
    printf("valsize=%d, capa=%d, ptr_0 = %p", testarray->value_size, testarray->capacity, testarray->ptr_to_zero_value);


    printf("\n Adding the testvalues(%f : @%p) to the TehArray and checking them.", test_double, &test_double);
    for(int i =0; i<2+testarray->capacity; i++)
    {
        printf("\n%d.", i);
        double* const ptr_to_value = teharray_getPointerToIndex(testarray, i);
        if(ptr_to_value)
        {
            printf(" Setting (*%p) = %.2f", ptr_to_value, test_double);
            *ptr_to_value = test_double;
        }
        else
        {
            printf(" Null pointer.");
        }
    }

    printf("\n Displaying testvalues: ");
    for(int i =0; i<2+testarray->capacity; i++)
    {
        printf("\n%d.", i);
        const double* const ptr_to_value = teharray_getPointerToIndex(testarray, i);
        if(ptr_to_value)
        {
            printf(" (*%p) is %.2f ", ptr_to_value, *ptr_to_value);
            if(*ptr_to_value == test_double)
            {
                printf("\tOk.");
            }
        }
        else
        {
            printf(" Null pointer.");
        }
    }
}
