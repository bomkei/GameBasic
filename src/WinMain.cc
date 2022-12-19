#include <Windows.h>
#include <vector>
#include "Wrapper/CWindow.h"

class MainWindow : CWindow {

public:
  MainWindow() {

  }

  ~MainWindow() {

  }


private:


};

static constexpr auto g_class_name = TEXT("GAME_BASIC");

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) {

  WNDCLASS wc{
    .style = CS_HREDRAW | CS_VREDRAW,
    .lpfnWndProc = WindowProc,
    .cbClsExtra = 0,
    .cbWndExtra = 0,
    .hInstance = hInst,
    .hIcon = LoadIcon(nullptr,IDI_APPLICATION),
    .hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH),
    .lpszMenuName = nullptr,
    .lpszClassName = g_class_name
  };

  if( !RegisterClass(&wc) ) {
    return -1;
  }

  auto hwnd = CreateWindow(
    g_class_name, TEXT("Game Basic"),
    WS_OVERLAPPEDWINDOW | WS_VISIBLE,
    CW_USEDEFAULT, CW_USEDEFAULT,
    500, 400,
    nullptr, nullptr,
    hInst, nullptr
  );

  if( !hwnd )
    return -1;

  MSG msg;

  while( GetMessage(&msg, nullptr, 0, 0) ) {
    DispatchMessage(&msg);
    TranslateMessage(&msg);
  }

  return msg.wParam;
}

