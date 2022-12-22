#pragma once

#include <vector>

class CodeEditor;

class MainWindow : public CWindow {

  enum WindowType {
    WT_Editor,
    WT_Interpreter,
  };

public:
  MainWindow(std::wstring const& title, int width, int height);
  ~MainWindow();

  bool WhenCreate(HWND hwnd);

  LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

private:

  CodeEditor& GetCurrentCodeEditor();

  HBITMAP hBitmap;
  HDC hBuffer;

  HMENU hMenu;
  MENUINFO menuInfo;

  WindowType currentWindowtype;

  size_t current_code_editor_index;
  std::vector<CodeEditor> code_editor_list;

};