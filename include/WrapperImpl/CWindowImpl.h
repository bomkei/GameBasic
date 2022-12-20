#pragma once

#include <string>
#include <map>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

class CWindow;
class CWindowImpl {
  friend class CWindow;
  friend LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

public:
  ~CWindowImpl();

private:
  CWindowImpl(std::wstring const& title, int width, int height);

  void Show();
  void Hide();

  HWND Create(CWindow const* wnd);

  HWND hwnd;
  std::wstring title;

  int width;
  int height;


  static WNDCLASS winc;
  static std::map<HWND, CWindow*> hwnd_map;
};
