#pragma once

#include <string>

class Drawing {

public:
  static void SetTarget(HDC hdc);

  static void SetFont(HFONT hFont);

  static void DrawRect(int x, int y, int width, int height, COLORREF color);

  static void FillRect(int x, int y, int width, int height, COLORREF color);

  static void DrawString(
    int x, int y,
    std::wstring const& str,
    COLORREF fore,
    COLORREF back = 0,
    bool transparent = true
  );

};

