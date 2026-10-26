void __thiscall sub_5A6150(_DWORD *this, _DWORD *a2)
{
  int v3; // eax
  _DWORD *v4; // edi
  int v5; // eax
  _DWORD *i; // edi
  int v7; // eax

  if ( (this[1282] & 0x10000000) != 0 )
  {
    v3 = this[1128];
    if ( v3 )
    {
      sub_5A7FD0(v3);
      if ( this[1128] )
        sub_5BE8AE();
      this[1128] = 0;
    }
    if ( this[1127] )
    {
      sub_5A7FD0(this[1127]);
      if ( this[1127] )
        sub_5BE8AE();
      this[1127] = 0;
    }
    if ( this[1129] )
    {
      sub_5A8170(this[1129]);
      if ( this[1129] )
        sub_5BE8AE();
      this[1129] = 0;
    }
    v4 = (_DWORD *)this[2145];
    this[1280] = 1;
    this[2135] = 0;
    this[2136] = 0;
    this[2137] = 0;
    this[2138] = 0;
    this[2139] = 0;
    for ( this[2140] = 0; v4; v4 = (_DWORD *)v4[8] )
    {
      if ( v4[5] )
      {
        sub_5A7FD0(v4[5]);
        v4[5] = 0;
      }
      v5 = v4[4];
      if ( v5 && *(_DWORD *)(v5 + 16) )
        sub_5AB000(v4[4]);
    }
    for ( i = (_DWORD *)this[2171]; i; i = (_DWORD *)i[8] )
    {
      sub_5A32F0(i);
      v7 = i[1070];
      if ( v7 && *(_DWORD *)(v7 + 16) )
        sub_5AB000(i[1070]);
    }
    if ( a2 )
    {
      sub_596D40(a2);
      sub_5AB0A0(a2);
      sub_5AAED0((int)this, (int)a2);
      a2[60] |= 0x10000u;
    }
    this[1282] &= ~0x10000000u;
  }
}
