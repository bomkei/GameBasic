#pragma once

class MainWindow : public CWindow {

public:
  MainWindow(std::wstring const& title, int width, int height);
  ~MainWindow();

  LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

private:

  HBITMAP hBitmap;
  HDC hBuffer;

};
