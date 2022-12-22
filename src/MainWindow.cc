#include <Windows.h>
#include <vector>
#include "Exceptions.h"
#include "Wrapper/CWindow.h"
#include "MainWindow.h"
#include "CodeEditor.h"
#include "resource.h"

// メインウィンドウ ビットマップのサイズ
static constexpr auto
  mainWindow_bitmap_width = 2000,
  mainWindow_bitmap_height = 1200;

MainWindow::MainWindow(std::wstring const& title, int width, int height)
  : CWindow(title, width, height),
    hBitmap(nullptr),
    hBuffer(nullptr),
    hMenu(nullptr),
    menuInfo({ }),
    currentWindowtype(WT_Editor),
    current_code_editor_index(0),
    code_editor_list({ CodeEditor() })
{
}

MainWindow::~MainWindow() {

}

bool MainWindow::WhenCreate(HWND hwnd) {
  auto hdc = GetDC(hwnd);

  this->hBitmap = CreateCompatibleBitmap(
    hdc,
    mainWindow_bitmap_width,
    mainWindow_bitmap_height
  );

  this->hBuffer = CreateCompatibleDC(hdc);

  SelectObject(this->hBuffer, this->hBitmap);
  SelectObject(this->hBuffer, GetStockObject(NULL_PEN));

  PatBlt(
    this->hBuffer,
    0, 0,
    mainWindow_bitmap_width, mainWindow_bitmap_height,
    WHITENESS
  );

  ReleaseDC(hwnd, hdc);

  this->hMenu = LoadMenu(nullptr, L"MAIN_WINDOW_MENU");

  SetMenu(hwnd, this->hMenu);

  return true;
}

LRESULT CALLBACK MainWindow::WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
  PAINTSTRUCT ps;

  switch( msg ) {
    case WM_CREATE: {
      if( !this->WhenCreate(hwnd) ) {
        MessageBox(
          nullptr,
          L"MainWindow::WindowProc: WM_CREATE failed",
          L"error",
          MB_OK
        );

        PostQuitMessage(0);
        exit(1);
      }

      break;
    }

    case WM_DESTROY: {
      DeleteObject(this->hBitmap);
      DeleteDC(this->hBuffer);

      SetMenu(hwnd, nullptr);
      DestroyMenu(this->hMenu);

      break;
    }

    case WM_COMMAND: {
      int wmID = LOWORD(wp);

      switch( wmID ) {
        // ファイル --> 開く
        case MENUID_FILE_OPEN: {

          break;
        }
      }

      break;
    }

    case WM_PAINT: {
      auto hdc = BeginPaint(hwnd, &ps);

      WINDOWINFO windowInfo;

      GetWindowInfo(hwnd, &windowInfo);

      int window_width =
        windowInfo.rcClient.right - windowInfo.rcClient.left;

      int window_height =
        windowInfo.rcClient.bottom - windowInfo.rcClient.top;

      switch( this->currentWindowtype ) {
        case WT_Editor: {
          auto const& editor = this->GetCurrentCodeEditor();

          int len = window_width / editor.GetFontSize().first;
          int line = window_height / editor.GetFontSize().second;

          editor.Draw(
            this->hBuffer, len, line
          );


          break;
        }

        case WT_Interpreter: {

          break;
        }

        default: {
          throw NotImplementedError();
        }
      }

      BitBlt(
        hdc,
        0, 0, mainWindow_bitmap_width, mainWindow_bitmap_height,
        this->hBuffer,
        0, 0,
        SRCCOPY
      );

      EndPaint(hwnd, &ps);
      break;
    }
  }

  return 0;
}

CodeEditor& MainWindow::GetCurrentCodeEditor() {
  return
    this->code_editor_list[this->current_code_editor_index];
}
