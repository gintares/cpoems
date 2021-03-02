#include <stdio.h>              /* I/O lib         C89   */


int main(){

    char *keys[3] = { "A", "B", "C" }; 
    void *vkeys = &keys;
    char **kptr = vkeys;
    int i; 
    for ( i=0; i<3; i++ ) {
        printf("\n kptr[%d]=%s ", i, kptr[i] );
        //kptr++; 
    } // for ( i=0; i<3; i++ 
//RESULT :
// kptr[0]=A 
// kptr[1]=B 
// kptr[2]=C 
    
    
// WORKS WITHOUT MEMORY ALLOCATION, because points to the same memory

 char *keys1[3] = { "AAAAA", "BBBBBBBBB", "CCCCCCCC" }; 
 void *vkeys1 = &keys1; 
 char **kptr1 = vkeys1; 
 for ( i=0; i<3; i++ ) { printf("\n kptr1[%d]=%s ", i, kptr1[i] );  } 
    
//RESULTS: 
 // kptr1[0]=AAAAA 
 // kptr1[1]=BBBBBBBBB 
 // kptr1[2]=CCCCCCCC
    
    return 1; 
}


