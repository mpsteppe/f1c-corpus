int __thiscall sub_52B930(_DWORD *this)
{
  int result; // eax
  int v3; // esi
  int i; // esi
  bool v5; // zf

  result = this[14];
  this[13] = 0;
  if ( result )
  {
    do
    {
      v3 = *(_DWORD *)(this[14] + 12);
      result = sub_5BE8AE();
      this[14] = v3;
    }
    while ( v3 );
  }
  for ( i = this[20]; i; result = sub_5BE8AE() )
  {
    v5 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v5 )
      sub_5BE8AE();
  }
  this[20] = 0;
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  return result;
}
