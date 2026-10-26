int __thiscall sub_5004E0(_DWORD *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // edx
  int v5; // eax
  _DWORD *v6; // esi
  int v7; // ebp
  int result; // eax
  int v9; // esi
  int v10; // ebp
  int v11; // eax

  sub_578600(&byte_629120);
  v2 = this[3];
  this[2] = 0;
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 - 4);
    v4 = 5 * v3;
    v5 = v3 - 1;
    v6 = (_DWORD *)(v2 + 8 * v4);
    if ( v5 >= 0 )
    {
      v7 = v5 + 1;
      do
      {
        v6 -= 10;
        sub_4FF690(v6);
        if ( *v6 )
          sub_5BE8AE();
        --v7;
      }
      while ( v7 );
    }
    sub_5BE8AE();
    this[3] = 0;
  }
  result = this[5];
  this[4] = 0;
  if ( result )
  {
    v9 = result + 2072 * *(_DWORD *)(result - 4);
    if ( *(_DWORD *)(result - 4) - 1 >= 0 )
    {
      v10 = *(_DWORD *)(result - 4);
      do
      {
        v11 = *(_DWORD *)(v9 - 2072);
        v9 -= 2072;
        if ( v11 )
          sub_5BE8AE();
        --v10;
      }
      while ( v10 );
    }
    result = sub_5BE8AE();
    this[5] = 0;
  }
  this[8] = -1;
  return result;
}
