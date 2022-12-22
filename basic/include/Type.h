#pragma once

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
  
};

} // namespace basic