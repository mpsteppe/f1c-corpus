int __thiscall sub_507540(_DWORD *this)
{
  int result; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // esi
  int v8; // edi

  result = this[2];
  if ( result )
    result = sub_5BE8AE();
  v3 = this[4];
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 - 4);
    v5 = 3 * v4;
    v6 = v4 - 1;
    v7 = v3 + 8 * v5;
    if ( v6 >= 0 )
    {
      v8 = v6 + 1;
      do
      {
        v7 -= 24;
        sub_5075A0(v7);
        --v8;
      }
      while ( v8 );
    }
    return sub_5BE8AE();
  }
  return result;
}
