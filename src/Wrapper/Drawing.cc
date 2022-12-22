#include <Windows.h>
#include "Wrapper/Drawing.h"

static HDC hTarget;

void Drawing::SetTarget(HDC hdc) {
  ::hTarget = hdc;
}

void Drawing::DrawRect(int x, int y, int width, int height, COLORREF color) {

}

void Drawing::FillRect(int x, int y, int width, int height, COLORREF color) {

  DeleteObject(
    SelectObject(hTarget, CreateSolidBrush(color))
  );

  Rectangle(hTarget, x, y, x + width, y + height);

}


