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


imageYUEE::imageYUEE() {
    width = 0;
    height = 0;
}

imageYUEE::imageYUEE(const CString& filename) {
    loadPGM(filename);
}

imageYUEE::imageYUEE(const imageYUEE& other)
{
    width = other.width;
    height = other.height;
    pixels = other.pixels;
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

bool imageYUEE::imageWrite(const CString& filename)
{
    std::ofstream file(CT2A(filename), std::ios::binary);
    if (!file) return false;

    file << "P5\n" << width << " " << height << "\n255\n";
    for (int y = 0; y < height; ++y)
        file.write((char*)pixels[y].data(), width);

    return true;
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
    if (pixels.empty() || width == 0 || height == 0) return;

    CClientDC dc(CWnd::FromHandle(hwnd));
    CRect rect;
    ::GetClientRect(hwnd, &rect);

    CBitmap bmp;
    bmp.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());

    CDC memDC;
    memDC.CreateCompatibleDC(&dc);
    CBitmap* pOldBmp = memDC.SelectObject(&bmp);

    memDC.FillSolidRect(&rect, RGB(255, 255, 255)); // 배경 흰색

    // 확대 비율 계산
    double scaleX = (double)rect.Width() / width;
    double scaleY = (double)rect.Height() / height;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char px = pixels[y][x];
            COLORREF color = RGB(px, px, px);

            // 확대 범위 계산 (픽셀 블록으로 출력)
            int drawXStart = (int)(x * scaleX);
            int drawXEnd = (int)((x + 1) * scaleX);
            int drawYStart = (int)(y * scaleY);
            int drawYEnd = (int)((y + 1) * scaleY);

            // 클리핑 방지
            drawXEnd = min(drawXEnd, rect.Width());
            drawYEnd = min(drawYEnd, rect.Height());

            for (int yy = drawYStart; yy < drawYEnd; ++yy) {
                for (int xx = drawXStart; xx < drawXEnd; ++xx) {
                    memDC.SetPixel(xx, yy, color);
                }
            }
        }
    }

    // 메모리 DC를 실제 DC에 출력
    dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);
    memDC.SelectObject(pOldBmp);
}