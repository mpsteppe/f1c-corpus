int __thiscall sub_548890(_DWORD *this, const char *a2)
{
  int v3; // ebp
  char *v4; // eax
  char v5; // cl
  CHAR *v6; // esi
  char *v7; // eax
  bool v8; // cf
  unsigned __int8 v9; // dl
  int v10; // eax
  CHAR *v11; // esi
  unsigned __int8 v12; // dl
  _BYTE v14[4]; // [esp+8h] [ebp-204h] BYREF
  char v15[256]; // [esp+Ch] [ebp-200h] BYREF
  CHAR SrcStr[256]; // [esp+10Ch] [ebp-100h] BYREF

  strcpy(SrcStr, a2);
  sub_589901(SrcStr);
  v3 = this[9];
  if ( !v3 )
    return 0;
  while ( 1 )
  {
    v4 = (char *)v3;
    if ( (*(_DWORD *)(v3 + 156) & 0x200) != 0 )
    {
      do
      {
        v5 = *v4;
        v15[(_DWORD)v4 - v3] = *v4;
        ++v4;
      }
      while ( v5 );
      v14[strlen(v15)] = 0;
      v6 = SrcStr;
      v7 = v15;
      while ( 1 )
      {
        v8 = (unsigned __int8)*v7 < (unsigned __int8)*v6;
        if ( *v7 != *v6 )
          break;
        if ( *v7 )
        {
          v9 = v7[1];
          v8 = v9 < (unsigned __int8)v6[1];
          if ( v9 != v6[1] )
            break;
          v7 += 2;
          v6 += 2;
          if ( v9 )
            continue;
        }
        v10 = 0;
        goto LABEL_17;
      }
    }
    else
    {
      v11 = SrcStr;
      while ( 1 )
      {
        v8 = (unsigned __int8)*v4 < (unsigned __int8)*v11;
        if ( *v4 != *v11 )
          break;
        if ( *v4 )
        {
          v12 = v4[1];
          v8 = v12 < (unsigned __int8)v11[1];
          if ( v12 != v11[1] )
            break;
          v4 += 2;
          v11 += 2;
          if ( v12 )
            continue;
        }
        v10 = 0;
        goto LABEL_17;
      }
    }
    v10 = -v8 - (v8 - 1);
LABEL_17:
    if ( !v10 )
      return v3;
    v3 = *(_DWORD *)(v3 + 192);
    if ( !v3 )
      return 0;
  }
}
