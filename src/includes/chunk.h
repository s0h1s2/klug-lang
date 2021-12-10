#ifndef clox_chunk_h
#define clox_chunk_h
#include "common.h"
#include "value.h"

typedef enum{
    OP_RETURN,
    OP_CONSTANT
} OpCode;

typedef struct{
    uint8_t* code;

    int count;
    int capacity;
    ValueArray constants;
    int* lines;

    
} Chunk;
void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk,uint8_t byte,int line);
int addConstants(Chunk* chunk,Value value);




#endif