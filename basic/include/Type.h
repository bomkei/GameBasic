#pragma once

#include <string>

namespace basic {

enum TypeKind {
  TYPE_None,
  TYPE_Int,
  TYPE_Float,
  TYPE_Char,
  TYPE_String,
  TYPE_Tuple,
};

struct Type {
  TypeKind kind;

  size_t arr_depth;
  bool is_ref;
  bool is_mut;

  Type(TypeKind kind = TYPE_None);

  std::string to_string() const;
  bool equals(Type const& type) const;
};

} // namespace basic