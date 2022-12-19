#pragma once

#include <string>
#include <memory>

class CWindowImpl;
class CWindow {

public:
  CWindow();
  virtual ~CWindow();

  void Show();
  void Hide();




private:

  std::wstring title;

  std::unique_ptr<CWindowImpl> _impl;

};

