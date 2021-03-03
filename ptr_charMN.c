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
    
   //voiding coverts to D1 array of strings 
    char *keys3[2][2][3] = {
          {  {"AAA", "BBB", "CCC" }, { "DD", "EE", "FF" }  }, 
          {  {"GG", "HHH", "JJJ" }, { "KKK", "LLL", "ZZZ" }  }
    };
    int i, j, u; 
    //printf("\n keys[%d][%d][%d]=%s ", 1,2, 1, (char*)keys[1][1][1] ); 

    void *vkeys3 = &keys3;
    char **kptr3 = vkeys3; // Becomes D1 array 
    for ( u=0; u<12; u++ ) {  printf(" =%s ", (char*)kptr3[u] ); } //kptr++; 
    // kptr[u] points to "AAA", "BBB", "CCC", "DD", "EE", "FF" ....
    // kptr[u][i] points to "AAA" letters from i position
    // printf &kpt[u][i][j] - does not work, j type is not recognised 
    
    return 1; 
}


