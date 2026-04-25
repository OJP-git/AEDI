#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int *output = (int*) malloc( sizeof(int)*matSize*matSize );
    int lin = 0;
    int col = 0;
    int i = 0;

    if( !output ){
        printf("Erro ao alocar");
        return NULL;
    }
    
    while( lin != matSize && col != matSize){
        

        if(lin < 0){
            lin=0;
        }else if(lin >= matSize){
            lin = matSize-1;
        }

        if(col < 0){
            col=0;
        }else if( col >= matSize ){
            col = matSize-1;
        }

        //diagonal crescente
        while( (lin < matSize && lin >= 0) && (col < matSize && col >= 0) ){
            
            output[i] = mat[lin][col];
            i++;
            lin--;
            col++;
        }

        if(lin < 0){
            lin=0;
        }else if(lin >= matSize){
            lin = matSize-1;
        }

        if(col < 0){
            col=0;
        }else if( col >= matSize ){
            col = matSize-1;
        }

        //diagonal decrescente
        while( (lin < matSize && lin >= 0) && (col < matSize && col >= 0)  ){
            
            output[i] = mat[lin][col];
            i++;
            lin++;
            col--;
        }
    
        

    }
    *returnSize = i;
    return output;

}

int main(){
	
}