#include <stdio.h>
#include "./includes/memory.h"
#include "./includes/value.h"
void initValueArray(ValueArray* array){
    array->values=NULL;
    array->capacity=0;
    array->count=0;

}
void writeValueArray(ValueArray* array, Value value){
    if (array->capacity<array->count+1)
    {
        // allocate new array
        int oldCap=array->capacity;
        array->capacity=GROW_CAPACITY(oldCap);
        array->values=GROW_ARRAY(Value,array->values,oldCap,array->capacity);

    }
    
    array->values[array->count]=value;
    array->count+=1;

}
void freeValueArray(ValueArray* array){
    FREE_ARRAY(Value,array->values,array->capacity);
    initValueArray(array);
}
void printValue(Value value){
    printf("%g'",value);
}
