#include "./includes/common.h"
#include "./includes/compiler.h"
#include "./includes/scanner.h"

void compile(const char*source){
    initScanner(source);
    int line=-1;
    for (;;){
        Token token=scanToken();
        if(token.line!=line){
            printf("%4d",token.line);
            line=token.line;

        }else{
            printf("    |");
        }
//        printf("%2d '%.*s'\n");
        if (token.type==TOKEN_EOF)break;

    }
}