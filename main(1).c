#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int tam = matSize * (*matColSize);
    int *output = (int*) malloc( sizeof(int) * tam  );
    int lin = 0;
    int col = 0;
    int i = 0;
    int c = 0;

   while(  i<tam ){
        if(c==0){  
            while( lin >= 0 && col < (*matColSize) ){  
                output[i] = mat[lin][col];
                i++;
                lin--;
                col++;
            }
            c = 1;  
                lin++;  
            if( col >= (*matColSize) ){
                lin+=1;
                col--;
            }
        }else{
            while( lin < matSize && col >= 0 ){
                output[i] = mat[lin][col];
                i++;
                lin++;
                col--;     
            }
            c = 0;
                col++;  
            if(lin >= matSize){
                lin--;
                col+=1;
            }   
        }
        
    }
    *returnSize = tam;
    return output;
}

int main() {
 
    int col = 3; 
    int retSize;
    int* matriz[] = { (int[]){1,2,3}, (int[]){4,5,6}, (int[]){7,8,9} };
    int* matriz2[] = { (int[]){1,2}, (int[]){3,4} };
    int* res = findDiagonalOrder(matriz, 3, &col, &retSize);
    
    printf("{%d",res[0]);
    for (int i = 1; i < retSize; i++) 
        printf(",%d", res[i]);
    printf("}");
    
    col = 2;
    int* res2 = findDiagonalOrder(matriz2, 2, &col, &retSize);
    
    printf("\n{%d",res2[0]);
    for (int i = 1; i < retSize; i++) 
        printf(",%d", res2[i]);
    printf("}");
    
    free(res);
    free(res2);
    return 0;
}

