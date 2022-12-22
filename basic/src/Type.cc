#include <vector>
#include <utility>
#include <stdexcept>
#include "Type.h"

static char const* typekind_name_list[] = {
  "none",
  "int",
  "float",
  "char",
  "string",
  "tuple",
};

namespace basic {

Type::Type(TypeKind kind)
  : kind(kind),
    arr_depth(0),
    is_ref(false),
    is_mut(false)
{
}

std::string Type::to_string() const {
  int index = static_cast<int>(this->kind);

  if( index >= std::size(::typekind_name_list) ) {
    throw std::out_of_range("");
  }

  return ::typekind_name_list[index];
}

bool Type::equals(Type const& type) const {
  if( this->kind == type.kind &&
    this->arr_depth == type.arr_depth &&
    this->is_ref == type.is_ref &&
    this->is_mut == type.is_mut ) {
    
    // todo: check sub elements
    return true;
  }

  return false;
}

} // namespace basic