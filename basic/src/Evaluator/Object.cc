#include "Evaluator/Object/Object.h"

namespace basic {

Object::Object(Type&& type)
  : type(std::move(type)),
    ref_count(0)
{

}

Object::~Object() {

}

} // namespace basic

