#include <Windows.h>
#include <vector>
#include "Wrapper/CWindow.h"

static constexpr auto g_class_name = TEXT("GAME_BASIC");

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

int Main(std::vector<std::wstring> const& args);

int APIENTRY wWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPWSTR lpCmdLine,
                   int nCmdShow) {

  auto& winc = CWindow::GetWindowClass();

  winc = {
    .style = CS_HREDRAW | CS_VREDRAW,
    .lpfnWndProc = WindowProc,
    .cbClsExtra = 0,
    .cbWndExtra = 0,
    .hInstance = hInst,
    .hIcon = LoadIcon(nullptr, IDI_APPLICATION),
    .hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH),
    .lpszMenuName = nullptr,
    .lpszClassName = g_class_name
  };

  if (!RegisterClass(&winc)) {
    return -1;
  }

  std::vector<std::wstring> args;

  std::wstring cmdline = lpCmdLine;

  cmdline += L' ';

  for( std::wstring arg; auto&& ch : cmdline ) {
    if( ch == L' ' ) {
      args.emplace_back(arg);
      arg.clear();
      continue;
    }

    arg += ch;
  }

  return Main(args);
}
