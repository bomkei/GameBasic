#include <Windows.h>
#include "Wrapper/CWindow.h"
#include "WrapperImpl/CWindowImpl.h"

CWindow::CWindow()
  : impl(new CWindowImpl(L"window", 500, 400))
{
}

CWindow::CWindow(std::wstring const& title, int width, int height)
  : impl(new CWindowImpl(title, width, height))
{
}

CWindow::~CWindow() {}

void CWindow::Show() const {
  this->impl->Show();
}

void CWindow::Hide() const {
  this->impl->Hide();
}

std::wstring& CWindow::Title() const {
  return this->impl->title;
}

HWND CWindow::Create() const {
  return this->impl->Create(this);
}

LRESULT CALLBACK CWindow::WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
  

  return 0;
}

WNDCLASS& CWindow::GetWindowClass() {
  return CWindowImpl::winc;
}

int CWindow::ExecuteMainLoop() {
  MSG msg;

  while (GetMessage(&msg, nullptr, 0, 0)) {
    DispatchMessage(&msg);
    TranslateMessage(&msg);
  }

  return msg.wParam;
}

