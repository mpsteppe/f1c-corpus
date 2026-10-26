int __stdcall sub_4C55B0(const char *a1)
{
  int result; // eax
  int v2; // ebp
  int i; // edi
  int v4; // eax
  CHAR *v5; // edx
  CHAR v6; // cl
  CHAR v7[80]; // [esp+0h] [ebp-A0h] BYREF
  CHAR SrcStr[80]; // [esp+50h] [ebp-50h] BYREF

  strcpy(SrcStr, a1);
  sub_589901(SrcStr);
  result = dword_8AC488;
  v2 = 0;
  if ( dword_8AC488 > 0 )
  {
    for ( i = 0; ; i += 396 )
    {
      v4 = i + dword_8AC490 + 260;
      v5 = &v7[-v4];
      do
      {
        v6 = *(_BYTE *)v4;
        v5[v4] = *(_BYTE *)v4;
        ++v4;
      }
      while ( v6 );
      sub_589901(v7);
      result = strcmp(SrcStr, v7);
      if ( !result )
        break;
      result = dword_8AC488;
      if ( ++v2 >= dword_8AC488 )
        return result;
    }
    dword_8AC48C = v2;
  }
  return result;
}

