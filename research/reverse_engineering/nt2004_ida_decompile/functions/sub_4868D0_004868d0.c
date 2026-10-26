_DWORD *__thiscall sub_4868D0(_DWORD *this, char a2)
{
  int v3; // esi
  LPVOID **v4; // ebp
  char v5; // al
  LPVOID *v6; // edi

  v3 = this[216];
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
  this[216] = 0;
  this[217] = 0;
  this[218] = 0;
  this[219] = 0;
  sub_4A2330(this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
