#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_2_arr(int **arr, int m, int n){
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%2d ",arr[i][j]);
        }

        printf("\n");
    }
}

int main(void){
    int m, n;
    scanf("%d %d",&m, &n);
    int **stat;

    stat = (int **)malloc(sizeof(int *)*m);
    stat[0] = (int *)malloc(sizeof(int)*m*n);
    for(int i = 1; i < m; i++){
        stat[i] = stat[0] + n * i;
        //stat[i] = stat[i-1] + n;
    }

    
    int t = 0;
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            stat[i][j]=t++;
        }
    }

    printf("\narray\n");
    print_2_arr(stat, m, n);

    printf("\nthe pointer of array's each element\n");
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%p ",&stat[i][j]);
        }
        printf("\n");
    }

    printf("\nwhat's stat?\n");
    printf("%p\n",&stat);

    printf("\nwhat's stat[m]?\n");
    for(int i = 0;i<m;i++){
        printf("%p ",&stat[i]);
    }
    printf("\n");

    printf("\nwhat's stat[m] stands for?\n");
    for(int i = 0;i<m;i++){
        printf("%p ",stat[i]);
    }
    printf("\n");

    printf("\nstat[0]\n");
    for(int i = 0;i<m*n;i++){
        printf("%d ",stat[0][i]);
    }
    printf("\n");

    printf("\npointer of stat[0]\n");
    for(int i = 0;i<m*n;i++){
        printf("%p ",stat[0] + i);
    }
    printf("\n\n");
    
    free(stat[0]);
    free(stat);
    return 0;
}