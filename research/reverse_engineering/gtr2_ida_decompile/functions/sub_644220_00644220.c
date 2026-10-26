int __thiscall sub_644220(_DWORD *this)
{
  _BYTE *v1; // edx
  int result; // eax

  v1 = (_BYTE *)this[2];
  LOBYTE(result) = *v1;
  this[2] = v1 + 1;
  return result;
}
