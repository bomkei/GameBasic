#include <Windows.h>
#include <vector>
#include "Wrapper/CWindow.h"
#include "MainWindow.h"

int Main(std::vector<std::wstring> const& args) {
  MainWindow mainWindow{ L"main window", 600, 400 };

  mainWindow.Create();
  mainWindow.Show();

  return CWindow::ExecuteMainLoop();
}

