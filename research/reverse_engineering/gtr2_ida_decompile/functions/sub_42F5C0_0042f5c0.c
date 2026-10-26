double __thiscall sub_42F5C0(_DWORD *this)
{
  int v1; // eax
  double v3; // st7
  int v4; // eax
  int v5; // edi
  unsigned int v6; // esi
  int v7; // eax
  double v8; // st7
  int v9; // eax
  double v10; // st7
  int v11; // eax
  double v12; // st7
  int v13; // eax
  int v14; // edx
  int v15; // eax

  v1 = this[64];
  if ( !v1 )
    return *(float *)&this[this[65]];
  if ( v1 != 1 )
    return 0.0;
  v3 = 0.0;
  v4 = this[65];
  v5 = 0;
  if ( dword_757C24 >= 4 )
  {
    v6 = ((unsigned int)(dword_757C24 - 4) >> 2) + 1;
    v5 = 4 * v6;
    do
    {
      v7 = v4 - 1;
      v8 = v3 + *(float *)&this[v7 + 1];
      v9 = v7 + (v7 < 0 ? 0x40 : 0) - 1;
      v10 = v8 + *(float *)&this[v9 + 1];
      v11 = v9 + (v9 < 0 ? 0x40 : 0) - 1;
      v12 = v10 + *(float *)&this[v11 + 1];
      v13 = v11 + (v11 < 0 ? 0x40 : 0) - 1;
      v3 = v12 + *(float *)&this[v13 + 1];
      v4 = v13 + (v13 < 0 ? 0x40 : 0);
      --v6;
    }
    while ( v6 );
  }
  if ( v5 < dword_757C24 )
  {
    v14 = dword_757C24 - v5;
    do
    {
      v15 = v4 - 1;
      v3 = v3 + *(float *)&this[v15 + 1];
      v4 = v15 + (v15 < 0 ? 0x40 : 0);
      --v14;
    }
    while ( v14 );
  }
  return v3 / (double)dword_757C24;
}
