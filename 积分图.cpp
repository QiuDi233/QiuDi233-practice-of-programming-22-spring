/*����
����һ���Ҷȵ�ͼ�񣬻���ͼ�е�����һ��(x,y)��ֵ��ָ��ͼ������Ͻǵ������������ɵľ������������еĵ�ĻҶ�ֵ֮�͡�

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class IntegralImage{
// �ڴ˴�������Ĵ���
};
int main(){
    int H, W;
    cin >> H >> W;
    int ** image = new int*[H];
    for(int i=0;i<H;++i){
        image[i]=new int[W];
    }
    for(int i=0;i<H;++i)
    for(int j=0;j<W;++j)
        cin >> image[i][j];
    IntegralImage it(H,W);
    for_each(image, image+H, it);
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j)
            cout<<it[i][j]<<" ";
        cout<<endl;
    }
   
}
����
��һ�������������ֱ���ͼ��Ŀ���H, W
������H*W�ľ��󣬷ֱ����ͼ���ÿ������ֵ
���
����ͼ��ÿ�����ֵ, H*W�ľ���ÿ������֮���ÿո�ֿ�
��������
2 3
1 2 3
1 0 0
�������
1 3 6
2 4 7*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class IntegralImage {
    // �ڴ˴�������Ĵ���
public:
    int h;
    int w;
    int** img;
    IntegralImage(int H, int W):h(H),w(W){ 
        img = new int* [h];
        for (int i = 0; i < h; ++i) {
            img[i] = new int[w];
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                img[i][j] = -1;
            }
        }
    }
    void operator()(int *p) {
        int cnt = 0;//������һ��д��
        for (int i = 0; i < h; ++i) {
            if (img[i][0] == -1) {
                cnt = i;
                break;
            }
        }
        if (cnt == 0) {
            img[cnt][0] =  p[0];
            for (int i = 1; i < w; ++i) {
                img[cnt][i] = img[cnt][i - 1]+p[i];
            }

        }
        else {
            int num = p[0];
            img[cnt][0] = img[cnt - 1][0] + p[0];
            for (int i = 1; i < w; ++i) {
                img[cnt][i] = num+img[cnt - 1][i] + p[i];
                num += p[i];
            }
        }
    }
    int* operator[] (int i) {
        return img[i];
    }
};
int main() {
    int H, W;
    cin >> H >> W;
    int** image = new int* [H];
    for (int i = 0; i < H; ++i) {
        image[i] = new int[W];
    }
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> image[i][j];
    IntegralImage it(H, W);
    for_each(image, image + H, it);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j)
            cout << it[i][j] << " ";
        cout << endl;
    }
}

