int __thiscall F_4FieldSetter(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int result; // eax

  this[7] = a4;
  result = a2;
  this[8] = a5;
  this[9] = a2;
  this[10] = a3;
  return result;
}

