// f1c  0x0047fbd0  size=132
_DWORD *__thiscall sub_47FBD0(_DWORD *this, char a2)
{
  int v3; // esi
  LPVOID **v4; // ebp
  char v5; // al
  LPVOID *v6; // edi

  v3 = this[273];
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
          sub_587BCF(*v6);
        sub_587BCF(v6);
      }
    }
    sub_587BCF(v4);
  }
  this[273] = 0;
  this[274] = 0;
  this[275] = 0;
  this[276] = 0;
  sub_48CA50(this);
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
