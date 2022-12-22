#pragma once

#include <string>
#include <vector>
#include <utility>

class CodeEditor {

public:

  CodeEditor();
  ~CodeEditor();

  void WhenKeyboard(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

  void Draw(HDC hdc, int length, int line) const;

  void SetFontSize(int width, int height);

  // フォントのサイズ
  std::pair<int, int> GetFontSize() const;

private:

  // スクロール
  int scroll_x;
  int scroll_y;

  // カーソル位置
  int cursor_x;
  int cursor_y;

  // フォントのサイズ
  int font_width;
  int font_height;

  std::vector<std::wstring> source;

};

