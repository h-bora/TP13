#pragma once

#include <afxwin.h>
#include <string>
#include <vector>


class imageYUEE {
private:
    int width;
    int height;
    std::vector<std::vector<unsigned char>> pixels;

public:
    imageYUEE();
    imageYUEE(const CString& filename);
	imageYUEE(const imageYUEE& other);     //  ���� ������
    void imageProc(int mode); // 0: ����ȭ, 1: ����, 2: �������, 3: ������
    bool imageWrite(const CString& filename);
    void drawImage(HWND hwnd);

private:
    void binarize();
    void invert();
    void brighten();
    void sharpen();

    bool loadPGM(const CString& filename);
    bool savePGM(const CString& filename);
};