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
    imageYUEE(const CString& filename);
    void imageProc(int mode); // 0: ����ȭ, 1: ����, 2: �������, 3: ������
    void imageWrite(const CString& filename);
    void drawImage(CStatic* control, CDC* pDC);

private:
    void binarize();
    void invert();
    void brighten();
    void sharpen();

    bool loadPGM(const CString& filename);
    bool savePGM(const CString& filename);
};