#include <iostream>
using namespace std;
const int N = 4;
template <class type>
void Swap(type &x, type &y){
    type temp = x;
    x = y;
    y = temp;
}
void Sort(int w[],int t[], int n){
    for (int i = 1; i <= n; i++)
    {
        t[i] = i;
    }
    
    for  (int i = 1;  i < n; i++)
    {
        int temp = i;
        for (int j =i+1; j <= n; j++){
            if (w[temp]>w[j])
            {
                temp = j;
                Swap(w[i], w[j]);
            }
        }
        Swap(t[i], t[temp]);
    }
}
void Loading(int w[], int x[],int c, int n){
    
    int t[N + 1] = {0};//记录原始索引
    Sort(w, t, N);
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
    for (int i = 1; i <= n&& w[t[i]] <= c; i++)
    {
        x[t[i]] = 1;
        c -= w[t[i]];
    }
}
int main(){
    int c = 50;
    int w[] = { 0, 25,10,20,15 };
    int x[N + 1];
    cout << "载重容量为：\n" << c << endl;
    cout << "物品的重量分别为：" << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << w[i] << " ";
    }
    cout << endl;
    Loading(w,x, c, N);
    cout << "贪心选择结果为:" << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}
