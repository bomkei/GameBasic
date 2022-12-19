#include "Wrapper/CWindow.h"
#include "WrapperImpl/CWindowImpl.h"
#include <Windows.h>

CWindow::CWindow() : _impl(new CWindowImpl()) {}

CWindow::~CWindow() {}
