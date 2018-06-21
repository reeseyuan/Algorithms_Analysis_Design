//使用回溯法，将current=1传入backtrack（），从第一个开始涂色。
//涂的时候从颜色1开始到m，每当涂上一个色，要用ok（current）判断第current个点是否可以涂这个色，不可以的话就不再往下涂，改试另一个颜色，可以的话就继续。
//当current>n的时候即前n个点都涂完了，然后输出结果并sum++计数。

#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
int a=1,b=1;
int sum=0;
int graph[20][20]={0};
int color[20]={0};

bool ok(int c){
    for(int k=1;k<=n;k++){
        if(graph[c][k]&&color[c]==color[k]){
            return false;
        }
    }
    return true;
}

void backtrack(int current){
    if(current>n){
        for(int i=1;i<=n;i++){
            printf("%d ",color[i]);
        }
        sum++;
        printf("\n");
    }else{
        for(int i=1;i<=m;i++){
            color[current]=i;
            if(ok(current)){
                backtrack(current+1);
            }
            color[current]=0;
        }
    }
}

int main()
{
    printf("请输入顶点个数 颜色数：\n");
    scanf("%d %d",&n,&m);
    printf("请输入顶点之间的相邻关系,以空格隔开,以0 0结束\n");
    while(scanf("%d %d",&a,&b)!=EOF&&a!=0&&b!=0){
        graph[a][b]=1;
        graph[b][a]=1;
    }
    backtrack(1);
    printf("着色方案总数：%d\n",sum);
    return 0;
}

/*
5 4
1 3
1 2
1 4
2 3
2 4
2 5
3 4
4 5
0 0
*/
