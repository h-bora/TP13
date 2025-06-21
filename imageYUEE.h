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
    void imageProc(int mode); // 0: ÀÌÁøÈ­, 1: ¹ÝÀü, 2: ¹à±âÁ¶Àý, 3: »þÇÁ´×
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