#include <stdio.h>
#include <iostream>
#define VERTEXNUM 5

void createGraph(int (*edge)[VERTEXNUM], int start, int end);
void displayGraph(int (*edge)[VERTEXNUM]);
void DFT(int (*edge)[VERTEXNUM],int* vertexStatusArr);
void DFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr);

int main(void){
        //动态创建存放边的二维数组
        int (*edge)[VERTEXNUM] = (int (*)[VERTEXNUM])malloc(sizeof(int)*VERTEXNUM*VERTEXNUM);
        int i,j;
        for(i=0;i<VERTEXNUM;i++){
                for(j=0;j<VERTEXNUM;j++){
                        edge[i][j] = 0;
                }
        }
        //存放顶点的遍历状态，0：未遍历，1：已遍历
        int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);
        for(i=0;i<VERTEXNUM;i++){
                vertexStatusArr[i] = 0;
        }

        printf("after init:\n");
        displayGraph(edge);
        //创建图
        createGraph(edge,0,3);
        createGraph(edge,0,4);
        createGraph(edge,3,1);
        createGraph(edge,3,2);
        //createGraph(edge,4,1);

        printf("after create:\n");
        displayGraph(edge);
        //深度优先遍历
        DFT(edge,vertexStatusArr);

        free(edge);
        return 0;
}
//创建图
void createGraph(int (*edge)[VERTEXNUM], int start, int end){
        edge[start][end] = 1;
}
//打印存储的图
void displayGraph(int (*edge)[VERTEXNUM]){
        int i,j;
        for(i=0;i<VERTEXNUM;i++){
                for(j=0;j<VERTEXNUM;j++){
                        printf("%d ",edge[i][j]);
                }
                printf("\n");
        }
}
//深度优先遍历
void DFT(int (*edge)[VERTEXNUM], int* vertexStatusArr){
        printf("start BFT graph:\n");

        int start = 3;
        int i = start + 1;
        for(; i != start; ){
            DFTcore(edge,i,vertexStatusArr);
            i = (i + 1) % VERTEXNUM;
        }
        DFTcore(edge, start, vertexStatusArr);
        printf("\n");
}

void DFTcore(int (*edge)[VERTEXNUM],int i,int* vertexStatusArr){
        if(vertexStatusArr[i] == 1){
                return;
        }
        printf("%d ",i);
        vertexStatusArr[i] = 1;

        int j;
        for(j=0;j<VERTEXNUM;j++){
                if(edge[i][j] == 1){
                        DFTcore(edge, j, vertexStatusArr);
                }
        }
}
