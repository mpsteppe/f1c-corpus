int __thiscall sub_59FB10(_DWORD *this, int a2)
{
  int v3; // ebx
  int v5; // eax
  int v6; // edi
  const char *v7; // esi
  int v8; // esi
  int v9; // edi
  char String[765]; // [esp+10h] [ebp-700h] BYREF
  __int16 v11; // [esp+30Dh] [ebp-403h]
  char v12; // [esp+30Fh] [ebp-401h]
  char Format[256]; // [esp+310h] [ebp-400h] BYREF
  char Buffer[765]; // [esp+410h] [ebp-300h] BYREF
  __int16 v15; // [esp+70Dh] [ebp-3h]
  char v16; // [esp+70Fh] [ebp-1h]

  if ( a2 && dword_7E8D40 )
  {
    String[0] = byte_629120;
    memset(&String[1], 0, 0x2FCu);
    v11 = 0;
    v12 = 0;
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0x2FCu);
    v15 = 0;
    v16 = 0;
    if ( strlen((const char *)a2) > 0x300 )
      *(_BYTE *)(a2 + 767) = 0;
    strcpy(String, (const char *)a2);
    _strupr(String);
    v3 = this[14] & 0xF;
    if ( !sub_59FCA0((int)this, String, v3) )
      return 0;
    v5 = dword_7E8D58;
    v6 = 0;
    if ( dword_7E8D58 > 0 )
    {
      v7 = byte_7E4CCC;
      do
      {
        sprintf(Buffer, "%s\\%s", v7, String);
        if ( !sub_59FCA0((int)this, Buffer, v3) )
          return 0;
        v5 = dword_7E8D58;
        ++v6;
        v7 += 132;
      }
      while ( v6 < dword_7E8D58 );
    }
    if ( v6 == v5 )
    {
      v8 = ElementCount;
      v9 = 0;
      if ( ElementCount )
      {
        while ( sub_5AEF20(v8, (int)this, String) )
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
    if ( v9 == dword_7E5D54 )
    {
      sprintf(Format, "Could not locate bitmap file %s", Buffer);
      sub_591C60((int)this, -1, Format);
    }
  }
  return -1;
}
