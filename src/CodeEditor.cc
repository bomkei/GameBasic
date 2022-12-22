#include <Windows.h>
#include "CodeEditor.h"
#include "Wrapper/Drawing.h"

CodeEditor::CodeEditor()
  : scroll_x(0),
    scroll_y(0),
    cursor_x(0),
    cursor_y(0),
    font_width(7),
    font_height(14)
{
#if 1
  this->source = {
    L"fn func() -> string {",
    L"  \"Hello, World!\"",
    L"}",
    L"",
    L"println(func());",
  };
#endif

  Drawing::SetFont()
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

  int begin = this->scroll_y;
  int end = std::min<int>(begin + line, this->source.size());
  int dy = 0;

  for( ; begin < end; begin++, dy += this->font_height ) {
    auto const& str = this->source[begin];

    Drawing::DrawString(
      0, dy,
      str,
      RGB(255, 255, 255)
    );


  }


}

std::pair<int, int> CodeEditor::GetFontSize() const {
  return { this->font_width, this->font_height };
}