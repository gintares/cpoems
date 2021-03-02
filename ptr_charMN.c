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

}

//RESULT :
// kptr[0]=A 
// kptr[1]=B 
// kptr[2]=C 
