#include "./includes/common.h"
#include "./includes/chunk.h"
#include "./includes/debug.h"
#include "./includes/vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void repl() {
    char line[1024]; // 1024 byte per line.
    for (;;) {
        printf("> ");
        if (!fgets(line,sizeof(line),stdin)){
            printf("\n");
            break;
        }
        interpret(line);

    }


}

static char *readFile(const char *path) {
    FILE* file= fopen(path,"rb");
    if (file==NULL){
        printf("Couldn't open the file '%s'.\n",path);
        exit(74);

    }
    fseek(file,0L,SEEK_END);
    size_t fileSize= ftell(file);
    rewind(file);
    char* buffer=(char*) malloc(fileSize+1);
    if (buffer==NULL){
        fprintf(stderr,"Not enough memory to allocate.");
    }
    size_t bytesRead= fread(buffer,sizeof(char),fileSize,file);
    if (bytesRead<fileSize){
        fprintf(stderr,"could not read the file.'");
    }
    buffer[bytesRead]='\0';
    fclose(file);
    return buffer;

}

static void runFile(const char* path){
    char* source=readFile(path);

    InterpretResult  result= interpret(source);
    free(source);
    if (result==INTERPRET_COMPILE_ERROR)exit(65);
    if (result==INTERPRET_RUNTIME_ERROR) exit(70);
//


}
int main(int argc, const char* argv[]){
    initVM();
    if (argc==1){
        repl();
    }
    else if(argc==2){
        runFile(argv[1]);
    }
    else{
        fprintf(stderr,"Usage:clox [path]\n");
        exit(64);
    }
//    Chunk chunk;
//	initChunk(&chunk);
//
//	int constant=addConstants(&chunk,118);
//    writeChunk(&chunk,OP_CONSTANT,123);
//    writeChunk(&chunk,addConstants(&chunk,1),123);
//    writeChunk(&chunk,OP_CONSTANT,123);
//    writeChunk(&chunk,addConstants(&chunk,2),123);
//    writeChunk(&chunk,OP_MULTIPLY,123);
//    writeChunk(&chunk,OP_CONSTANT,123);
//    writeChunk(&chunk, addConstants(&chunk,3),123);
//    writeChunk(&chunk,OP_NEGATE,123);
//
//    writeChunk(&chunk,OP_ADD,123);
//
//
//    writeChunk(&chunk,OP_RETURN,123);
//
//    interpret(&chunk);
//
    freeVM();
//	freeChunk(&chunk);

	return 0;
}
