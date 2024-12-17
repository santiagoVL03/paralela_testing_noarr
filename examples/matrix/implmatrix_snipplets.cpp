float A[ I ] [ K ] , B [ K ] [ J ] , C[ I ] [ J ] ;

for ( i = 0 ; i < I ; i ++)
    for ( j = 0 ; j < J ; j ++)
        for ( k = 0 ; k < K ; k ++)
            Comp: C[ i ] [ j ] += A[ i ] [ k ] ∗ B [ k ] [ j ] ;
affine ( Comp , { [ i , j , k ] −>[ i , k , j ] } )
affine ( Comp , { [ i , j , k ] −>[ i1 , j1 , k1 , i2 , j2 , k2 ] : i1 =[ i / 32 ] and i2 = i %32
    and j1 =[ j / 32 ] and j2 = j %32 and k1 =[ k / 32 ] and k2=k % 32 } )