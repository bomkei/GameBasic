#pragma once

#include <cstdint>

namespace basic {

struct ObjLong : Object {
  int64_t val;

  ObjLong(int64_t val)
    : Object(TYPE_Int),
      val(val)
  {
  }

  std::string to_string() const {
    return std::to_string(val);
  }
};

} // namespace basic

