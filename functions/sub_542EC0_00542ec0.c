int __thiscall sub_542EC0(_DWORD *this, int a2)
{
  int v3; // ebx
  int v5; // eax
  int v6; // edi
  const char *v7; // esi
  int v8; // esi
  int v9; // edi
  CHAR SrcStr[765]; // [esp+10h] [ebp-700h] BYREF
  __int16 v11; // [esp+30Dh] [ebp-403h]
  char v12; // [esp+30Fh] [ebp-401h]
  char v13[256]; // [esp+310h] [ebp-400h] BYREF
  char v14[765]; // [esp+410h] [ebp-300h] BYREF
  __int16 v15; // [esp+70Dh] [ebp-3h]
  char v16; // [esp+70Fh] [ebp-1h]

  if ( a2 && dword_8B8E28 )
  {
    SrcStr[0] = byte_5EA438[0];
    memset(&SrcStr[1], 0, 0x2FCu);
    v11 = 0;
    v12 = 0;
    v14[0] = byte_5EA438[0];
    memset(&v14[1], 0, 0x2FCu);
    v15 = 0;
    v16 = 0;
    if ( strlen((const char *)a2) > 0x300 )
      *(_BYTE *)(a2 + 767) = 0;
    strcpy(SrcStr, (const char *)a2);
    sub_589901(SrcStr);
    v3 = this[6] & 0xF;
    if ( !sub_543050(SrcStr, v3) )
      return 0;
    v5 = dword_8B8E30;
    v6 = 0;
    if ( dword_8B8E30 > 0 )
    {
      v7 = byte_8B5A3C;
      do
      {
        StringFormatWithBufferOverflowCheck(v14, "%s\\%s", v7, SrcStr);
        if ( !sub_543050(v14, v3) )
          return 0;
        v5 = dword_8B8E30;
        ++v6;
        v7 += 132;
      }
      while ( v6 < dword_8B8E30 );
    }
    if ( v6 == v5 )
    {
      v8 = dword_8B8F14;
      v9 = 0;
      if ( dword_8B8F14 )
      {
        while ( sub_560050(this, SrcStr) )
        {
          v8 = *(_DWORD *)(v8 + 304);
          ++v9;
          if ( !v8 )
            goto LABEL_17;
        }
        return 0;
      }
    }
    else
    {
      v9 = -1;
    }
LABEL_17:
    if ( v9 == dword_8B6AC0 )
    {
      StringFormatWithBufferOverflowCheck(v13, "Could not locate bitmap file %s", v14);
      sub_53C590(-1, v13);
    }
  }
  return -1;
}
