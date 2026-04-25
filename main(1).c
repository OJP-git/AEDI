#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
=======================================================================================================

    Essa função recebe uma matriz m x n e retorna o endereço para o um vetor com os valores da matriz
    em ordem das diagonais, primeiro uma crescente e depois uma decrescente a partir do próximo valor
    da matriz, alternando as diagonais até o último valor da matriz.

    Exemplo: 
    {
        { 1, 2, 3, }
        { 4, 5, 6, }
        { 7, 8, 9, }

        a ordem dos indices a serem pego é
        [ 0 ][ 0 ]
        [ 0 ][ 1 ] [ 1 ][ 0 ]
        [ 2 ][ 0 ] [ 1 ][ 1 ] [ 0 ][ 2 ]
        [ 1 ][ 2 ] [ 2 ][ 1 ]
        [ 2 ][ 2 ]

        resultando no vetor: { 1, 2, 4, 7, 5, 3, 6, 8, 9 }
    }

=======================================================================================================
*/
int* FindDiagonalOrder ( int** mat, int matSize, int* matColSize, int* returnSize ) {
    int tam = matSize * ( *matColSize );
    int *output = ( int* ) malloc( sizeof( int ) * tam  );
    int lin = 0;
    int col = 0;
    int i = 0;
    int c = 0;

   while (  i<tam ) {
        if ( c==0 ) {  
            while ( lin >= 0 && col < ( *matColSize ) ) {  
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
        } else {
            while ( lin < matSize && col >= 0 ) {
                output[i] = mat[lin][col];
                i++;
                lin++;
                col--;     
            }
            c = 0;
            col++;  
            if ( lin >= matSize ) {
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
    int* matriz[] = { ( int[] ) {1,2,3}, ( int[] ) {4,5,6}, ( int[] ) {7,8,9} };
    int* matriz2[] = { ( int[] ) {1,2}, ( int[] ) {3,4} };
    int* matriz3[] = { ( int[] ) {1,2,3,4}, ( int[] ) {5,6,7,8}, ( int[] ) {9,10,11,12}, ( int[] ) {13,14,15,16} };
    int* res = FindDiagonalOrder ( matriz, 3, &col, &retSize );
    
    printf ( "{%d",res[0] );
    for ( int i = 1; i < retSize; i++ ) { 
        printf ( ",%d", res[i] );
    }
    printf ( "}" );
    
    col = 2;
    int* res2 = FindDiagonalOrder ( matriz2, 2, &col, &retSize );
    
    printf ( "\n{%d",res2[0] );
    for ( int i = 1; i < retSize; i++ ) 
        printf ( ",%d", res2[i] );
    printf ( "}" );

    col = 4;
    int* res3 = FindDiagonalOrder ( matriz3, 4, &col, &retSize );
    
    printf ( "\n{%d",res3[0] );
    for ( int i = 1; i < retSize; i++ ) 
        printf ( ",%d", res3[i] );
    printf ( "}\n" );
    
    free ( res );
    free ( res2 );
    free ( res3 );
    return 0;
}

