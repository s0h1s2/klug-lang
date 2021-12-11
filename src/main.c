#include "./includes/common.h"
#include "./includes/chunk.h"
#include "./includes/debug.h"
#include "./includes/vm.h"

int main(int argc,const char* argv[]){
    initVM();

    Chunk chunk;
	initChunk(&chunk);

	int constant=addConstants(&chunk,118);
    writeChunk(&chunk,OP_CONSTANT,123);
    writeChunk(&chunk,addConstants(&chunk,1),123);
    writeChunk(&chunk,OP_CONSTANT,123);
    writeChunk(&chunk,addConstants(&chunk,2),123);
    writeChunk(&chunk,OP_MULTIPLY,123);
    writeChunk(&chunk,OP_CONSTANT,123);
    writeChunk(&chunk, addConstants(&chunk,3),123);
    writeChunk(&chunk,OP_NEGATE,123);

    writeChunk(&chunk,OP_ADD,123);


    writeChunk(&chunk,OP_RETURN,123);
//	disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);
    freeVM();

	freeChunk(&chunk);

	return 0;
}
