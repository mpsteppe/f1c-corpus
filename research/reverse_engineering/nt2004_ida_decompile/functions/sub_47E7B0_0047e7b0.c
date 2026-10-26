_DWORD *__thiscall sub_47E7B0(_DWORD *this, char a2)
{
  int v3; // esi
  LPVOID **v4; // ebp
  char v5; // al
  LPVOID *v6; // edi

  *this = &off_5D7850;
  v3 = this[68];
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
  this[68] = 0;
  this[69] = 0;
  this[70] = 0;
  this[71] = 0;
  this[68] = 0;
  this[69] = 0;
  this[70] = 0;
  this[71] = 0;
  sub_49D970(this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
