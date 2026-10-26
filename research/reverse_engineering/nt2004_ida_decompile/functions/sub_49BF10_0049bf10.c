_DWORD *__thiscall sub_49BF10(_DWORD *this, char a2)
{
  int v3; // esi
  LPVOID **v4; // ebp
  char v5; // al
  LPVOID *v6; // edi
  int v7; // esi
  LPVOID **v8; // ebp
  char v9; // al
  LPVOID *v10; // edi

  v3 = this[101];
  while ( v3 )
  {
    v4 = (LPVOID **)v3;
    v5 = *(_BYTE *)(v3 + 8);
    v3 = *(_DWORD *)(v3 + 4);
    if ( v5 )
    {
      v6 = *v4;
      if ( *v4 )
      {
        if ( *v6 )
          sub_5BE8AE(*v6);
        sub_5BE8AE(v6);
      }
    }
    sub_5BE8AE(v4);
  }
  this[101] = 0;
  this[102] = 0;
  this[103] = 0;
  this[104] = 0;
  v7 = this[68];
  while ( v7 )
  {
    v8 = (LPVOID **)v7;
    v9 = *(_BYTE *)(v7 + 12);
    v7 = *(_DWORD *)(v7 + 4);
    if ( v9 )
    {
      v10 = *v8;
      if ( *v8 )
      {
        if ( *v10 )
          sub_5BE8AE(*v10);
        sub_5BE8AE(v10);
      }
    }
    sub_5BE8AE(v8);
  }
  this[68] = 0;
  this[69] = 0;
  this[70] = 0;
  this[71] = 0;
  sub_49D970(this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
