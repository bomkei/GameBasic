#include <Windows.h>
#include "Wrapper/CWindow.h"
#include "WrapperImpl/CWindowImpl.h"

WNDCLASS CWindowImpl::winc;
std::map<HWND, CWindow*> CWindowImpl::hwnd_map;

CWindowImpl::CWindowImpl(std::wstring const& title, int width, int height)
  : title(title),
    width(width),
    height(height)
{
}

CWindowImpl::~CWindowImpl() {

}

void CWindowImpl::Show() {
  ShowWindow(this->hwnd, SW_SHOW);
}

void CWindowImpl::Hide() {
  ShowWindow(this->hwnd, SW_HIDE);
}

HWND CWindowImpl::Create(CWindow const* wnd) {
  return this->hwnd = CreateWindow(
    winc.lpszClassName, this->title.c_str(),
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT,
    this->width, this->height,
    nullptr, nullptr,
    winc.hInstance, (LPVOID)wnd
  );
}

