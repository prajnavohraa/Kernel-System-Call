#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>

int main(){
    double source_matrix[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    double destination_matrix[4][3];
    syscall(548,source_matrix,destination_matrix,4,3);
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            printf("%f ",destination_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}