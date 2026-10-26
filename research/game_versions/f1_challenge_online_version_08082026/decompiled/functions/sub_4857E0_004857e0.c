_DWORD *__thiscall sub_4857E0(_DWORD *this, char a2)
{
  int v3; // esi
  LPVOID **v4; // ebp
  char v5; // al
  LPVOID *v6; // edi

  v3 = this[58];
  while ( v3 )
  {
    v4 = (LPVOID **)v3;
    v5 = *(_BYTE *)(v3 + 12);
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
  this[58] = 0;
  this[59] = 0;
  this[60] = 0;
  this[61] = 0;
  sub_487250(this);
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
