// f1c  0x005427d0  size=383
int __stdcall sub_5427D0(int a1, int a2, int a3, int a4)
{
  int v4; // edi
  const char *v5; // esi
  int v6; // esi
  int i; // edi
  char v9[256]; // [esp+14h] [ebp-700h] BYREF
  CHAR SrcStr[768]; // [esp+114h] [ebp-600h] BYREF
  _BYTE v11[768]; // [esp+414h] [ebp-300h] BYREF

  if ( !a1 )
    return 0;
  if ( strlen((const char *)a1) > 0x300 )
    *(_BYTE *)(a1 + 767) = 0;
  strcpy(SrcStr, (const char *)a1);
  sub_589901(SrcStr);
  if ( !sub_543130(SrcStr, a2, a3, a4) )
    return 0;
  v4 = 0;
  if ( dword_8B8E30 > 0 )
  {
    v5 = byte_8B5A3C;
    do
    {
      sub_58815F(v11, "%s\\%s", v5, SrcStr);
      if ( !sub_543130(v11, a2, a3, a4) )
        break;
      ++v4;
      v5 += 132;
    }
    while ( v4 < dword_8B8E30 );
  }
  if ( v4 == dword_8B8E30 )
  {
    v6 = dword_8B8F14;
    for ( i = 0; v6; ++i )
    {
      if ( !sub_55FE70(SrcStr, a2, a3, a4) )
        break;
      v6 = *(_DWORD *)(v6 + 304);
    }
  }
  else
  {
    i = -1;
  }
  if ( i != dword_8B6AC0 )
    return 0;
  sub_58815F(v9, "Could not locate bitmap file %s", SrcStr);
  sub_53C590(-1, v9);
  return -1;
}
