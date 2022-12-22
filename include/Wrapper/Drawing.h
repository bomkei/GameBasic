#pragma once

class Drawing {

public:
  static void SetTarget(HDC hdc);

  static void DrawRect(int x, int y, int width, int height, COLORREF color);

  static void FillRect(int x, int y, int width, int height, COLORREF color);


};

