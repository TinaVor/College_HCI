#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FNAME "input.txt" 
 
int main(){
    FILE* in = fopen( FNAME, "r" );
    size_t counter = 0; 
    int ch, pre = EOF;
    while ( ( ch = fgetc( in ) ) != EOF ) { 
        pre = ch;
        if ( ch == '\n' ) 
            ++counter; 
    }
    if ( pre != '\n'  ) { 
        ++counter; 
    }
 
    printf( "%u", counter );
    return 0;
}