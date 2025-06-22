#pragma once
#define NOMINMAX
#include <afxwin.h>
#include "pch.h"
#include "imageYUEE.h"
#include <fstream>
#include <vector>
#include <algorithm> 
#include <cmath>

#undef min
#undef max

using namespace std;

imageYUEE::imageYUEE(const CString& filename) {
    loadPGM(filename);
}

void imageYUEE::imageProc(int mode) {
    switch (mode) {
    case 0: binarize(); break;
    case 1: invert(); break;
    case 2: brighten(); break;
    case 3: sharpen(); break;
    default: break;
    }
}

void imageYUEE::imageWrite(const CString& filename) {
    savePGM(filename);
}

bool imageYUEE::loadPGM(const CString& filename) {
    std::ifstream file(CT2A(filename), std::ios::binary);
    if (!file) return false;

    std::string magic;
    file >> magic;
    if (magic != "P5") return false;

    file >> width >> height;
    int maxVal;
    file >> maxVal;
    file.get(); // skip newline

    pixels.resize(height, std::vector<unsigned char>(width));
    for (int y = 0; y < height; ++y)
        file.read((char*)pixels[y].data(), width);

    return true;
}

bool imageYUEE::savePGM(const CString& filename) {
    std::ofstream file(CT2A(filename), std::ios::binary);
    if (!file) return false;

    file << "P5\n" << width << " " << height << "\n255\n";
    for (int y = 0; y < height; ++y)
        file.write((char*)pixels[y].data(), width);

    return true;
}

void imageYUEE::binarize() {
    for (auto& row : pixels)
        for (auto& px : row)
            px = (px > 127) ? 255 : 0;
}

void imageYUEE::invert() {
    for (auto& row : pixels)
        for (auto& px : row)
            px = 255 - px;
}

void imageYUEE::brighten() {
    for (auto& row : pixels)
        for (auto& px : row)
            px = std::min(255, px + 50);
}

void imageYUEE::sharpen() {
    std::vector<std::vector<unsigned char> > copiedPixels = pixels;

    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            int val = 5 * copiedPixels[y][x]
                - copiedPixels[y - 1][x]
                - copiedPixels[y + 1][x]
                - copiedPixels[y][x - 1]
                - copiedPixels[y][x + 1];

            int clipped = std::max(0, std::min(255, val)); // 범위 클리핑
            pixels[y][x] = static_cast<unsigned char>(clipped);
        }
    }
}



void imageYUEE::drawImage(HWND hwnd) {
    CClientDC dc(CWnd::FromHandle(hwnd));
    CRect rect;
    ::GetClientRect(hwnd, &rect);
    CBitmap bmp;
    bmp.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());

    CDC memDC;
    memDC.CreateCompatibleDC(&dc);
    CBitmap* pOldBmp = memDC.SelectObject(&bmp);

    memDC.FillSolidRect(&rect, RGB(255, 255, 255));

    for (int y = 0; y < height && y < rect.Height(); ++y) {
        for (int x = 0; x < width && x < rect.Width(); ++x) {
            unsigned char px = pixels[y][x];
            memDC.SetPixel(x, y, RGB(px, px, px));
        }
    }

    dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);
    memDC.SelectObject(pOldBmp);
}