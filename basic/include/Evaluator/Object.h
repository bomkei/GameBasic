#pragma once

#include <string>


namespace basic {

struct Object {
public:


  virtual ~Object();

  std::string to_string() const;

protected:

};

} // namespace basic