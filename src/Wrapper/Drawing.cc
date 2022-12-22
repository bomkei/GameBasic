#include <Windows.h>
#include "Wrapper/Drawing.h"

static HDC hTarget;
static HFONT hFont;

void Drawing::SetTarget(HDC hdc) {
  ::hTarget = hdc;
}

void Drawing::SetFont(HFONT hFont) {
  ::hFont = hFont;
}

void Drawing::DrawRect(int x, int y, int width, int height, COLORREF color) {

}

void Drawing::FillRect(int x, int y, int width, int height, COLORREF color) {

  DeleteObject(
    SelectObject(hTarget, CreateSolidBrush(color))
  );

  Rectangle(hTarget, x, y, x + width, y + height);

}

void Drawing::DrawString(
  int x, int y,
  std::wstring const& str,
  COLORREF fore,
  COLORREF back,
  bool trans)
{
  SetTextColor(hTarget, fore);
  SetBkColor(hTarget, back);

  SetBkMode(hTarget, trans ? TRANSPARENT : OPAQUE);

  TextOut(hTarget, x, y, str.c_str(), str.length());
}

