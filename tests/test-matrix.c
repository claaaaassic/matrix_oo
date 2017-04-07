#include "matrix.h"
#include <stdio.h>

MatrixAlgo *matrix_providers[] = {
    &NaiveMatrixProvider,
    &SubMatrixMatrixProvider,
};

char info[2][16] = {"naive","sub matrix"};

int main()
{
    for(int i=0; i<2; i++) {
        MatrixAlgo *algo = matrix_providers[i];

        Matrix dst, m, n, fixed;
        algo->assign(&m, (Mat4x4) {
            .values = {
                { 1, 2, 3, 4, },
                { 5, 6, 7, 8, },
                { 1, 2, 3, 4, },
                { 5, 6, 7, 8, },
            },
        });

        algo->assign(&n, (Mat4x4) {
            .values = {
                { 1, 2, 3, 4, },
                { 5, 6, 7, 8, },
                { 1, 2, 3, 4, },
                { 5, 6, 7, 8, },
            },
        });

        algo->mul(&dst, &m, &n);

        algo->assign(&fixed, (Mat4x4) {
            .values = {
                { 34,  44,  54,  64, },
                { 82, 108, 134, 160, },
                { 34,  44,  54,  64, },
                { 82, 108, 134, 160, },
            },
        });

        if (algo->equal(&dst, &fixed))
            printf("test %s : \n \t equal\n", info[i]);
        else {
            printf("test %s : \n \t not equal\n", info[i]);
            return -1;
        }
    }
    return 0;
}
