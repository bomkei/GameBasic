#include "Wrapper/CWindow.h"
#include <Windows.h>


LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {

  switch (msg) {
  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hwnd, msg, wp, lp);
  }

  return 0;
}
