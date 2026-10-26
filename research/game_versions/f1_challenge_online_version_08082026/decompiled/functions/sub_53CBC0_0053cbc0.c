int __stdcall sub_53CBC0(_DWORD *a1, CHAR *a2)
{
  CHAR *v2; // eax
  int v3; // ebx
  CHAR v4; // cl
  int v5; // esi
  bool v6; // zf
  const char *v7; // edi
  int v9; // eax
  _DWORD *v10; // esi
  int v11; // eax
  int v12; // ecx
  int i; // eax
  int v14; // [esp+10h] [ebp-214h]
  char v15[16]; // [esp+14h] [ebp-210h] BYREF
  CHAR SrcStr[256]; // [esp+24h] [ebp-200h] BYREF
  char v17[256]; // [esp+124h] [ebp-100h] BYREF

  v2 = a2;
  v3 = 0;
  v14 = 0;
  if ( !a2 || !*a2 )
    return v14;
  do
  {
    v4 = *v2;
    v2[SrcStr - a2] = *v2;
    ++v2;
  }
  while ( v4 );
  sub_589901(SrcStr);
  v5 = sub_587DB0(SrcStr, aRb);
  if ( !v5 )
  {
    v6 = dword_8B8E30 == 0;
    if ( dword_8B8E30 > 0 )
    {
      v7 = byte_8B5A3C;
      do
      {
        sub_58815F(v17, "%s\\%s", v7, SrcStr);
        v5 = sub_587DB0(v17, aRb);
        if ( v5 )
          break;
        ++v3;
        v7 += 132;
      }
      while ( v3 < dword_8B8E30 );
      v6 = v3 == dword_8B8E30;
    }
    if ( v6 )
    {
      sub_58815F(v17, "Error opening MAS file %s", SrcStr);
      sub_53C590(-2, v17);
      return -2;
    }
  }
  sub_58803F(v15, 1, 12, v5);
  sub_587D02(v5);
  if ( !strcmp(v15, aCubemas410) )
  {
    v9 = sub_587C03(308);
    if ( v9 )
      v10 = (_DWORD *)sub_55FBE0(v9);
    else
      v10 = 0;
    v11 = sub_55FC40(SrcStr);
    switch ( v11 )
    {
      case -2:
        if ( v10 )
        {
          j_nullsub_3(v10);
          sub_587BCF(v10);
        }
        v14 = -2;
        break;
      case -1:
        if ( v10 )
        {
          j_nullsub_3(v10);
          sub_587BCF(v10);
        }
        v14 = -1;
        break;
      case 0:
        v12 = dword_8B8F14;
        if ( dword_8B8F14 )
        {
          for ( i = *(_DWORD *)(dword_8B8F14 + 304); i; i = *(_DWORD *)(i + 304) )
            v12 = i;
          *(_DWORD *)(v12 + 304) = v10;
          v10[75] = v12;
        }
        else
        {
          dword_8B8F14 = (int)v10;
        }
        ++dword_8B6AC0;
        v14 = 0;
        break;
    }
    if ( a1 )
      *a1 = v10;
    return v14;
  }
  if ( strcmp(v15, aCubemas400) && strcmp(v15, aCubemas401) )
    return v14;
  sub_53C590(-2, aIncorrectMasFi);
  return -1;
}
