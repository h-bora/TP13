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
	imageYUEE(const imageYUEE& other);     //  복사 생성자
    void imageProc(int mode); // 0: 이진화, 1: 반전, 2: 밝기조절, 3: 샤프닝
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