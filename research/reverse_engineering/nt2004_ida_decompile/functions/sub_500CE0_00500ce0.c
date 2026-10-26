int __thiscall sub_500CE0(int *this)
{
  int result; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  _DWORD *v9; // esi
  int v10; // ebp

  result = *this;
  v3 = 0;
  if ( *this > 0 )
  {
    v4 = 0;
    do
    {
      sub_5004E0((_DWORD *)(v4 + this[1]));
      result = *this;
      ++v3;
      v4 += 36;
    }
    while ( v3 < *this );
  }
  v5 = this[1];
  *this = 0;
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 - 4);
    v7 = 9 * v6;
    v8 = v6 - 1;
    v9 = (_DWORD *)(v5 + 4 * v7);
    if ( v8 >= 0 )
    {
      v10 = v8 + 1;
      do
      {
        v9 -= 9;
        sub_5004E0(v9);
        if ( v9[6] )
          sub_5BE8AE();
        if ( *v9 )
          sub_5BE8AE();
        --v10;
      }
      while ( v10 );
    }
    result = sub_5BE8AE();
  }
  this[1] = 0;
  return result;
}
