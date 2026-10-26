int __thiscall sub_52ACD0(_DWORD *this)
{
  int i; // esi
  bool v3; // zf
  int result; // eax

  for ( i = this[20]; i; result = sub_5BE8AE() )
  {
    v3 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v3 )
      sub_5BE8AE();
  }
  this[20] = 0;
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  return result;
}
