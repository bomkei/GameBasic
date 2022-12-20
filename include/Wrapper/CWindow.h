#pragma once

#include <memory>
#include <string>

class CWindowImpl;
class CWindow {

public:
  CWindow();
  CWindow(std::wstring const& title, int width, int height);
  virtual ~CWindow();

  void Show() const;
  void Hide() const;

  std::wstring& Title() const;

  HWND Create() const;

  virtual LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

  static WNDCLASS& GetWindowClass();
  
  static int ExecuteMainLoop();

private:
  std::unique_ptr<CWindowImpl> impl;
};
