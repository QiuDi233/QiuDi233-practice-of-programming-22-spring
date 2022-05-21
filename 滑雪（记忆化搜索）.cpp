/*����
Michaelϲ����ѩ���Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б��
���ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael��֪����һ����������Ļ��¡�
������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�������һ������
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�һ���ɻ��еĻ���Ϊ24-17-16-1��
��Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ����
����
����ĵ�һ�б�ʾ���������R������C(1 <= R,C <= 100)��������R�У�ÿ����C������������߶�h��0<=h<=10000��
���
��������ĳ��ȡ�
��������
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
�������
25*/ 

#include<iostream>
#include<cmath>
using namespace std;
int dp[100][100];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int r = 0,c = 0;
int h[100][100];
bool in_board(int xx,int yy){
    if(xx>=0&&xx<r&&yy>=0&&yy<c)
        return true;
    return false;
}
int dfs(int x,int y){
    if(dp[x][y]!=1)
        return dp[x][y];
    for(int i=0;i<4;++i){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(in_board(xx,yy)&&h[x][y]>h[xx][yy]){
            dp[x][y]=max(dp[x][y],dfs(xx,yy)+1);
        }
    }
    return dp[x][y];
}
int main() {
    
    cin >> r >> c;
    
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j){
            cin >> h[i][j];
            dp[i][j]=1;
        }
        int ans=0;
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j){
            ans=max(dfs(i,j),ans);
        }
    cout<<ans<<endl;
    return 0;
}
