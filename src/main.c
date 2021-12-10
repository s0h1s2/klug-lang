#include "./includes/common.h"
#include "./includes/chunk.h"
#include "./includes/debug.h"

int main(int argc,const char* argv[]){
	Chunk chunk;
	initChunk(&chunk);
	int constant=addConstants(&chunk,120);
	writeChunk(&chunk,OP_CONSTANT,123);
	writeChunk(&chunk,constant,123);
	writeChunk(&chunk,OP_RETURN,123);
	dissassembleChunk(&chunk,"test chunk");
	printf("Hello,world!\n");

	freeChunk(&chunk);

	return 0;	
}
