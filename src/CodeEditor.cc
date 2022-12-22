#include <Windows.h>
#include "CodeEditor.h"
#include "Wrapper/Drawing.h"

CodeEditor::CodeEditor()
  : cursor_x(0),
    cursor_y(0),
    font_width(7),
    font_height(14)
{
#if 1
  this->source = {
    "fn func() -> string {",
    "  \"Hello, World!\"",
    "}",
    "",
    "println(func());",
  };
#endif
}

CodeEditor::~CodeEditor() {

}

void CodeEditor::WhenKeyboard(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {

  switch( msg ) {
    case WM_KEYDOWN: {

      break;
    }

    case WM_KEYUP: {

      break;
    }
  }

}

void CodeEditor::Draw(HDC hdc, int length, int line) const {

  int width = length * this->font_width;
  int height = line * this->font_height;

  Drawing::SetTarget(hdc);

  

  // background
  Drawing::FillRect(
    0, 0,
    width, height,
    RGB(30, 30, 30)
  );


}

std::pair<int, int> CodeEditor::GetFontSize() const {
  return { this->font_width, this->font_height };
}