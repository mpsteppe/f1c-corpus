BOOL __thiscall sub_460A10(unsigned __int8 *this, int a2, const char *a3)
{
  unsigned __int8 v4; // al
  unsigned __int8 v5; // cl
  bool v6; // zf
  const char *v7; // edx
  const char *v8; // ecx
  char *v9; // eax
  char *v10; // edi
  char v11; // cl
  const char *v12; // ecx
  const char *v13; // eax
  char v15[79]; // [esp+Ch] [ebp-50h] BYREF
  char v16; // [esp+5Bh] [ebp-1h]

  v4 = this[112469];
  v5 = this[112468];
  this[112490] = 0;
  this[112491] = 0;
  this[112492] = 0;
  this[112493] = 0;
  this[112494] = 0;
  if ( (unsigned __int16)sub_460770(v5, v4) == *(_WORD *)(a2 + 8) )
    this[112490] = 1;
  if ( a3 && sub_45C320((_DWORD *)this + 28117, a3, &a3) && a3 == *(const char **)(a2 + 12) )
    this[112491] = 1;
  if ( sub_45C320((_DWORD *)this + 28117, aTerrainIni, &a3) )
  {
    v6 = &a3[dword_8ACED8 - 1413405834] == *(const char **)(a2 + 16);
    a3 = &a3[dword_8ACED8 - 1413405834];
    if ( v6 )
      this[112492] = 1;
  }
  v7 = (const char *)dword_7CE5D0;
  if ( !dword_7CE5D0 )
    v7 = byte_5EA438;
  v8 = &v7[strlen(v7)];
  if ( v8 > v7 )
  {
    while ( *v8 != 92 )
    {
      if ( --v8 <= v7 )
        goto LABEL_17;
    }
    ++v8;
  }
LABEL_17:
  sub_587DD0(v15, v8, 79);
  v16 = 0;
  v9 = &v15[strlen(v15)];
  if ( v9 > v15 )
  {
    while ( *v9 != 46 )
    {
      if ( --v9 <= v15 )
        goto LABEL_22;
    }
    *v9 = 0;
  }
LABEL_22:
  v10 = &v15[strlen(v15) + 1];
  v11 = byte_5C5D28;
  *(_DWORD *)--v10 = dword_5C5D24;
  v10[4] = v11;
  if ( sub_45C320((_DWORD *)this + 28117, v15, &a3) && a3 == *(const char **)(a2 + 20) )
    this[112493] = 1;
  v12 = (const char *)dword_7D0434;
  if ( !dword_7D0434 )
    v12 = byte_5EA438;
  v13 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v13 = byte_5EA438;
  sub_58969D(v15, 80, "%s%s", v13, v12);
  v16 = 0;
  if ( sub_45C320((_DWORD *)this + 28117, v15, &a3) && a3 == *(const char **)(a2 + 24) )
    this[112494] = 1;
  return this[112490] && this[112491] && this[112492] && this[112493] && this[112494];
}
