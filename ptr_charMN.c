#include <stdio.h>              /* I/O lib         C89   */


void cStr(void *vstr, char *str ) {
    vstr=&str;
}

void cArr(void *vkeys, char *keys[]) {
    vkeys=&keys; 
}

void inner( void *vstr, char *str[], char **str2) {
    //str2=calloc( 1, sizeof(char*) ); //works inside inner, but, does not work in main
    *str2=calloc(  strlen(str[0]), sizeof(char*));
   strcpy( *str2, str[0]) ;
   //vstr=&str2; //works inside inner, but does not work inside main
   printf("\n str2=%s from inner", *str2 ); 
    //printf("\n vstr=%s ", *(char**)vstr ); // vstr=&(*str2); in main or inner
    //printf("\n vstr=%s ", **(char***)vstr ); // vstr=&str2; in main or inner
}

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
    char *keys2[2][3] = {  {"AAA", "BBB", "CCC" }, { "DD", "EE", "FF" }  }; 
    void *vkeys2 = &keys2;
    char **kptr2 = vkeys2;
    u=-1;
    for ( i=0; i<6; i++ ) {
        j=i%3;  if(j==0) { u++; }
        printf("\n kptr2=[%d][%d]=%s ", u, j, (char*)kptr2[i] ); 
                //kptr++; 
    } // for ( i=0; i<3; i++ 
 //RESULT : 
 // kptr2=[0][0]=AAA 
 // kptr2=[1][1]=BBB 
 // kptr2=[2][2]=CCC 
 // kptr2=[3][0]=DD 
 // kptr2=[4][1]=EE 
 // kptr2=[5][2]=FF
    
    
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
    
    //DOES NOT WORK WITH STRINGS
    char *str="labutis";
    void *vstr=NULL; 
    cStr(vstr,str);
    char *str2= (char*)vstr;
    printf("\n vstr=%s ", (char*)vstr ); // vstr=null
    printf("\n str2=%s ", str2 ); //str2=null
// RESULT:
// vstr=null
// str2=null


    //WORKS WITH STRING ARRAYS
    //int i;
    //char *keys[3] = { "AAAAA", "BBBBBBBBB", "CCCCCCCC" }; //above
    //void *vkeys = &keys; //above
    cArr(vkeys, keys) ; 
    char **kptrA = vkeys;
    for ( i=0; i<3; i++ ) {
        printf("\n kptrA[%d]=%s ", i, kptrA[i] );
        //kptr++; 
    } // for ( i=0; i<3; i++ 
// RESULT:
//kptrA[0]=AAAAA 
//kptrA[1]=BBBBBBBBB 
//kptrA[2]=CCCCCCCC
     
     
     //TO ALLOCATE MEMORY INSIDE A inner FUNCTION, ONE HAS TO DEFINE MINIMUM D2 ARRAY in OUTER, AND ALLOCARE D1 IN OUTER(MAIN)
    char *str[1]= {"labutis"};
    char **str2=NULL; 
    str2=calloc( 1, sizeof(char*) ); 
    //*str2=calloc(  strlen(str[0]), sizeof(char*));//POSSIBLE INSIDE INNER
    //void *vpstr=NULL;// segmentation fault if assignin inside INNTER function
    void *vpstr=&str2; // segmentation fault if assignin inside INNTER function
    calV( vpstr, str, str2); //COPIES STR TO STR2, VPSTR POINTS TO STR2 AND PRINTS VALUE TOO
    printf("\n '''''''''''MAIN "); 
    printf("\n str2=%s from main", *str2 ); 
    printf("\n vpstr=%s from main", **(char***)vpstr ); 
//RESULT:
//str2=labutis from inner
//'''''''''''MAIN 
//str2=labutis from main
//vpstr=labutis from main
    
    return 1
    
}


