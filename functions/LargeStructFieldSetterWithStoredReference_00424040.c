int __thiscall LargeStructFieldSetterWithStoredReference(_DWORD *this, int a2)
{
  int result; // eax

  *this = a2;
  result = F_4FieldPropagation(a2);
  this[4109] = a2;
  return result;
}
