#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

typedef unsigned char BYTE;
typedef unsigned short WORD;//һ�����������ֽ�
typedef unsigned int DWORD;//���ֽ���˫��
typedef unsigned int LONG;//Ҳ�����ֽ�

typedef struct tagBITMAPFILEHEADER//BMP�ļ�ͷ
{
	//WORD bfType; // λͼ�ļ������ͣ�����Ϊ��BM���������� ����������ȡ
	DWORD bfSize; // λͼ�ļ��Ĵ�С�����ֽ�Ϊ��λ
	WORD bfReserved1; // λͼ�ļ������֣�����Ϊ 0
	WORD bfReserved2; // λͼ�ļ������֣�����Ϊ 0
	DWORD bfOffBits; // λͼ���ݵ���ʼλ�ã��������λͼ�ļ�ͷ��ƫ������ʾ�����ֽ�Ϊ��λ
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {//λͼ��Ϣͷ����
	DWORD biSize; // ���ṹ��ռ���ֽ���
	LONG biWidth; // λͼ�Ŀ�ȣ�������Ϊ��λ
	LONG biHeight; // λͼ�ĸ߶ȣ�������Ϊ��λ
	WORD biPlanes; // Ŀ���豸��ƽ�������壬����Ϊ 1
	WORD biBitCount;// ÿ�����������λ���������� 1(˫ɫ), 4(16 ɫ)��8(256 ɫ)�� 24(���ɫ)֮һ
	DWORD biCompression; // λͼѹ�����ͣ������� 0(��ѹ��),1(BI_RLE8 ѹ������)�� 2(BI_RLE4ѹ������)֮һ
	DWORD biSizeImage; // λͼ�Ĵ�С�����ֽ�Ϊ��λ
	LONG biXPelsPerMeter; // λͼˮƽ�ֱ��ʣ�ÿ��������
	LONG biYPelsPerMeter; // λͼ��ֱ�ֱ��ʣ�ÿ��������
	DWORD biClrUsed;// λͼʵ��ʹ�õ���ɫ���е���ɫ��
	DWORD biClrImportant;// λͼ��ʾ��������Ҫ����ɫ��
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD {//��ɫ�� ���������ɫ ��������ò���
	BYTE rgbBlue;// ��ɫ������(ֵ��ΧΪ 0-255)
	BYTE rgbGreen; // ��ɫ������(ֵ��ΧΪ 0-255)
	BYTE rgbRed; // ��ɫ������(ֵ��ΧΪ 0-255)
	BYTE rgbReserved;// ����������Ϊ 0
} RGBQUAD;

typedef struct tagBITMAPINFO {//λͼ��Ϣͷ����ɫ�����λͼ��Ϣ
	BITMAPINFOHEADER bmiHeader; // λͼ��Ϣͷ
	RGBQUAD bmiColors[1]; // ��ɫ��
} BITMAPINFO;

typedef struct pixel {//ͼ��Ϊ���ɫ��ͼ����ÿ�����ص���ɫ�������ֽڱ�ʾ���ֱ��Ӧ R��G��B ֵ
	BYTE R;
	BYTE G;
	BYTE B;
}Pixel;

int main() {
	FILE* src;
	FILE* dst;
	char ch = '\0';
	src=fopen("4.bmp", "rb");//��һ���ɶ��Ķ������ļ�
	dst = fopen("dest4.bmp", "wb");//��һ����д�Ķ������ļ� ��ͼ��ת��������
	if (!src) {
		cerr << "���ļ�ʧ��" << endl;
	}
	else {
		WORD bfType;
		BITMAPFILEHEADER bmp_head;//�ļ�ͷ
		BITMAPINFOHEADER info_head;//��Ϣͷ
		int h = 0;//height
		int w = 0;//width
		int size = 0;
		int cnt = 0;
		fread(&bfType, 1, sizeof(WORD), src);//�ļ����� �ӵ�0���ֽڿ�ʼ ����֮��srcָ����ƶ� �պþͽ�������bfType������ļ�ͷ
		fread(&bmp_head, 1, sizeof(BITMAPFILEHEADER), src);//���ļ�ͷ
		fread(&info_head, 1, sizeof(BITMAPINFOHEADER), src);//����Ϣͷ ��Ϣͷ���ļ�ͷ����
		h = info_head.biHeight;
		w = info_head.biWidth;
		size = h * w;//�õ�λͼ�ĸ߶� ��� �ʹ�С
		cnt = info_head.biBitCount;//������Ŀ˵�˸��Ķ���24λ���ɫ ��������϶���24

		//int DataSizePerLine = (w* cnt + 31) / 8;//ͼ���ļ���һ��ɨ������ռ���ֽ���
		//DataSizePerLine -= DataSizePerLine % 4;

		int DataSizePerLine = (((w * cnt/8) + 3) / 4)*4;

		//Ȼ���ٶ�ȡ������Ϣ bmp�������� �µ��� ÿ�ж����ֶ���
		Pixel *rgb = new Pixel[size];

		//������ͼƬ�������ɫ ÿ�����ص���ɫ�������ֽڱ�ʾ
		for (int i = 0; i < h; ++i) {
			fread((char*)rgb + i * w * 3, 3, w, src);
			fseek(src, DataSizePerLine - 3 * w, SEEK_CUR);//�Ѻ������Щ���Ĳ�������ȥ
		}

		//��ʼ��ת
		int dst_h = w;
		int dst_w = h;//��ת90�� �߶ȿ�Ȼ���
		int dst_size = size;
		BITMAPFILEHEADER dst_file = bmp_head;
		BITMAPINFOHEADER dst_info = info_head;
		dst_info.biWidth = (DWORD)dst_w;
		dst_info.biHeight =(DWORD) dst_h;
		dst_info.biSizeImage = (DWORD)((3*dst_w+3)/4)*4 * dst_h;
		//��С���ܻ�� ��Ϊ���������ܻ��

		//�����Ϣд��dst��
		fwrite(&bfType, 1, sizeof(WORD), dst);
		fwrite(&dst_file, 1, sizeof(BITMAPFILEHEADER), dst);
		fwrite(&dst_info, 1, sizeof(BITMAPINFOHEADER), dst);

		//������������
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
		//Ȼ���ٰ���д��ȥ
		//int dst_DataSizePerLine = (dst_w * cnt + 31) / 8;
		//dst_DataSizePerLine -= dst_DataSizePerLine % 4;

		int dst_DataSizePerLine = (((dst_w * cnt / 8) + 3) / 4) * 4;

		for (int i = 0; i < dst_h; ++i) {
			fwrite((char*)dst_rgb + i * dst_w * 3, 3, dst_w, dst);
			//fseek(dst, dst_DataSizePerLine - 3 * dst_w, SEEK_CUR);//����������ֽ�
			fwrite(&ch, 1, dst_DataSizePerLine - 3 * dst_w, dst);//����
		}
		//�ر��ļ� �ͷſռ�
		fclose(src);
		fclose(dst);
		delete[]dst_rgb;
	}
	return 0;
}