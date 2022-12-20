#include <Windows.h>
#include "Wrapper/CWindow.h"
#include "WrapperImpl/CWindowImpl.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {

  CWindow* pWindow{ };

  switch (msg) {
    case WM_CREATE: {
      auto createStruct = (CREATESTRUCT*)lp;

      if(createStruct) {
        pWindow = (CWindow*)createStruct->lpCreateParams;

        pWindow->Title() = createStruct->lpszName;

        CWindowImpl::hwnd_map[hwnd] = pWindow;
      }

      break;
    }

    case WM_DESTROY:
      PostQuitMessage(0);
      break;

    default: {
      pWindow = CWindowImpl::hwnd_map[hwnd];
      break;
    }
  }

  if( pWindow ) {
    pWindow->WindowProc(hwnd, msg, wp, lp);
  }
 
  return DefWindowProc(hwnd, msg, wp, lp);
}
