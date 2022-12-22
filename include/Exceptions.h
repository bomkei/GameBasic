#pragma once

#include <stdexcept>

class NotImplementedError : std::exception {

public:
  NotImplementedError() { }

  char const* what() const noexcept override {
    return "not implemented error";
  }

private:
};

