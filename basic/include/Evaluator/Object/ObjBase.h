#pragma once

namespace basic {

struct Object {
  Type type;
  size_t ref_count;

  virtual ~Object();

  virtual std::string to_string() const = 0;

protected:
  Object(Type&& type);
};

} // namespace basic