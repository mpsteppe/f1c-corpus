_DWORD *__thiscall sub_4706C0(_DWORD *this, char a2)
{
  int v3; // esi
  LPVOID **v4; // ebp
  char v5; // al
  LPVOID *v6; // edi

  v3 = this[72];
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
  this[72] = 0;
  this[73] = 0;
  this[74] = 0;
  this[75] = 0;
  sub_49E0D0(this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
