#pragma once

namespace basic {

struct ObjNone : Object {
  ObjNone()
    : Object(TYPE_None)
  {
  }

  std::string to_string() const override {
    return "none";
  }
};

} // namespace basic

