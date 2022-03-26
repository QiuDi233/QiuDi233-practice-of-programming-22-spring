#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

typedef unsigned char BYTE;
typedef unsigned short WORD;//一个字是两个字节
typedef unsigned int DWORD;//四字节是双字
typedef unsigned int LONG;//也是四字节

typedef struct tagBITMAPFILEHEADER//BMP文件头
{
	//WORD bfType; // 位图文件的类型，必须为“BM”单独定义 方便过会儿读取
	DWORD bfSize; // 位图文件的大小，以字节为单位
	WORD bfReserved1; // 位图文件保留字，必须为 0
	WORD bfReserved2; // 位图文件保留字，必须为 0
	DWORD bfOffBits; // 位图数据的起始位置，以相对于位图文件头的偏移量表示，以字节为单位
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {//位图信息头数据
	DWORD biSize; // 本结构所占用字节数
	LONG biWidth; // 位图的宽度，以像素为单位
	LONG biHeight; // 位图的高度，以像素为单位
	WORD biPlanes; // 目标设备的平面数不清，必须为 1
	WORD biBitCount;// 每个像素所需的位数，必须是 1(双色), 4(16 色)，8(256 色)或 24(真彩色)之一
	DWORD biCompression; // 位图压缩类型，必须是 0(不压缩),1(BI_RLE8 压缩类型)或 2(BI_RLE4压缩类型)之一
	DWORD biSizeImage; // 位图的大小，以字节为单位
	LONG biXPelsPerMeter; // 位图水平分辨率，每米像素数
	LONG biYPelsPerMeter; // 位图垂直分辨率，每米像素数
	DWORD biClrUsed;// 位图实际使用的颜色表中的颜色数
	DWORD biClrImportant;// 位图显示过程中重要的颜色数
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD {//颜色表 本题是真彩色 所以这个用不到
	BYTE rgbBlue;// 蓝色的亮度(值范围为 0-255)
	BYTE rgbGreen; // 绿色的亮度(值范围为 0-255)
	BYTE rgbRed; // 红色的亮度(值范围为 0-255)
	BYTE rgbReserved;// 保留，必须为 0
} RGBQUAD;

typedef struct tagBITMAPINFO {//位图信息头和颜色表组成位图信息
	BITMAPINFOHEADER bmiHeader; // 位图信息头
	RGBQUAD bmiColors[1]; // 颜色表
} BITMAPINFO;

typedef struct pixel {//图像为真彩色，图像中每个像素的颜色用三个字节表示，分别对应 R、G、B 值
	BYTE R;
	BYTE G;
	BYTE B;
}Pixel;

int main() {
	FILE* src;
	FILE* dst;
	char ch = '\0';
	src=fopen("4.bmp", "rb");//打开一个可读的二进制文件
	dst = fopen("dest4.bmp", "wb");//打开一个可写的二进制文件 把图像转到这里来
	if (!src) {
		cerr << "打开文件失败" << endl;
	}
	else {
		WORD bfType;
		BITMAPFILEHEADER bmp_head;//文件头
		BITMAPINFOHEADER info_head;//信息头
		int h = 0;//height
		int w = 0;//width
		int size = 0;
		int cnt = 0;
		fread(&bfType, 1, sizeof(WORD), src);//文件类型 从第0个字节开始 读完之后src指针会移动 刚好就接下来读bfType后面的文件头
		fread(&bmp_head, 1, sizeof(BITMAPFILEHEADER), src);//读文件头
		fread(&info_head, 1, sizeof(BITMAPINFOHEADER), src);//读信息头 信息头在文件头后面
		h = info_head.biHeight;
		w = info_head.biWidth;
		size = h * w;//得到位图的高度 宽度 和大小
		cnt = info_head.biBitCount;//由于题目说了给的都是24位真彩色 所以这个肯定是24

		//int DataSizePerLine = (w* cnt + 31) / 8;//图像文件中一个扫描行所占的字节数
		//DataSizePerLine -= DataSizePerLine % 4;

		int DataSizePerLine = (((w * cnt/8) + 3) / 4)*4;

		//然后再读取像素信息 bmp存是左到右 下到上 每行都四字对齐
		Pixel *rgb = new Pixel[size];

		//给出的图片都是真彩色 每个像素的颜色用三个字节表示
		for (int i = 0; i < h; ++i) {
			fread((char*)rgb + i * w * 3, 3, w, src);
			fseek(src, DataSizePerLine - 3 * w, SEEK_CUR);//把后面的那些填充的部分跳过去
		}

		//开始旋转
		int dst_h = w;
		int dst_w = h;//旋转90度 高度宽度互换
		int dst_size = size;
		BITMAPFILEHEADER dst_file = bmp_head;
		BITMAPINFOHEADER dst_info = info_head;
		dst_info.biWidth = (DWORD)dst_w;
		dst_info.biHeight =(DWORD) dst_h;
		dst_info.biSizeImage = (DWORD)((3*dst_w+3)/4)*4 * dst_h;
		//大小可能会变 因为填充的量可能会变

		//相关信息写到dst里
		fwrite(&bfType, 1, sizeof(WORD), dst);
		fwrite(&dst_file, 1, sizeof(BITMAPFILEHEADER), dst);
		fwrite(&dst_info, 1, sizeof(BITMAPINFOHEADER), dst);

		//再来处理像素
		Pixel* dst_rgb = new Pixel[size];
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				dst_rgb[(w - 1 - j) * h + i] = rgb[i * w + j];
			}
		}
		/*for (int i = 0; i < dst_h; i++) {
			for (int j = 0; j < dst_w; j++) {
				*(dst_rgb + i * dst_w + j) = *(rgb + j * w + dst_h - i - 1);
			}
		}*/
		//然后再把它写进去
		//int dst_DataSizePerLine = (dst_w * cnt + 31) / 8;
		//dst_DataSizePerLine -= dst_DataSizePerLine % 4;

		int dst_DataSizePerLine = (((dst_w * cnt / 8) + 3) / 4) * 4;

		for (int i = 0; i < dst_h; ++i) {
			fwrite((char*)dst_rgb + i * dst_w * 3, 3, dst_w, dst);
			//fseek(dst, dst_DataSizePerLine - 3 * dst_w, SEEK_CUR);//跳过补零的字节
			fwrite(&ch, 1, dst_DataSizePerLine - 3 * dst_w, dst);//补零
		}
		//关闭文件 释放空间
		fclose(src);
		fclose(dst);
		delete[]dst_rgb;
	}
	return 0;
}