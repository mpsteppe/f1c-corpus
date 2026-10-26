int __thiscall sub_5F6390(_DWORD *this, int a2, int a3)
{
  bool v3; // zf
  int result; // eax

  result = a2;
  v3 = a2 == dword_16C9A48;
  this[85] = a2;
  if ( v3 )
  {
    result = a3;
    this[94] = a3;
  }
  return result;
}
