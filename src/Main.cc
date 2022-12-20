#include <Windows.h>
#include <vector>
#include "Wrapper/CWindow.h"
#include "MainWindow.h"

int Main(std::vector<std::wstring> const& args) {
  MainWindow mainWindow{ L"GAME BASIC", 1000, 700 };

  mainWindow.Create();
  mainWindow.Show();

  return CWindow::ExecuteMainLoop();
}

