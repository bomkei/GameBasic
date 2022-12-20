#include <Windows.h>
#include <vector>
#include "Wrapper/CWindow.h"
#include "MainWindow.h"

MainWindow::MainWindow(std::wstring const& title, int width, int height)
  : CWindow(title, width, height)
{
}

MainWindow::~MainWindow() {

}

LRESULT CALLBACK MainWindow::WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
  PAINTSTRUCT ps;

  switch( msg ) {
    case WM_CREATE: {
      

      break;
    }

    case WM_DESTROY: {


      break;
    }

  }

  return 0;
}


