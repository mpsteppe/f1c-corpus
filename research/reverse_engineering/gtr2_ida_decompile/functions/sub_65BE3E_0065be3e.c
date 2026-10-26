int __thiscall sub_65BE3E(int this)
{
  int v2; // eax
  int v3; // eax
  int result; // eax
  bool v5; // zf
  _BYTE *v6; // eax
  _DWORD *v7; // eax
  int v8; // ecx
  BOOL v9; // eax
  int v10; // ecx
  char v11; // al
  char v12; // bl
  char v13; // [esp+0h] [ebp-34h]
  char ArgList[32]; // [esp+Ch] [ebp-28h] BYREF
  int v15; // [esp+2Ch] [ebp-8h] BYREF
  int v16; // [esp+30h] [ebp-4h] BYREF

  if ( *(_DWORD *)(this + 64) || *(_DWORD *)(this + 72) )
  {
    *(_DWORD *)(this + 632) = 12;
    return -1;
  }
  v2 = *(_DWORD *)(this + 100);
  if ( v2 )
  {
    qmemcpy((void *)(this + 632), (const void *)(v2 + 16), 0x20u);
    *(_DWORD *)(this + 100) = *(_DWORD *)(v2 + 12);
    *(_DWORD *)(v2 + 12) = 0;
  }
  else if ( (int)sub_65E7A1(*(_DWORD *)(this + 664) | 4, this + 632) < 0 )
  {
    return -1;
  }
  v3 = *(_DWORD *)(this + 632);
  if ( v3 == 1 )
  {
    v11 = *(_BYTE *)(this + 641);
    if ( !v11 )
      return *(char *)(this + 640);
    if ( !*(_BYTE *)(this + 642) )
    {
      if ( v11 == 61 )
      {
        switch ( *(_BYTE *)(this + 640) )
        {
          case '!':
            return 275;
          case '<':
            return 272;
          case '=':
            return 274;
          case '>':
            return 273;
        }
      }
      else
      {
        v12 = *(_BYTE *)(this + 640);
        if ( v12 == v11 )
        {
          if ( v12 == 38 )
            return 276;
          if ( v12 == 124 )
            return 277;
        }
      }
    }
    return 281;
  }
  if ( v3 <= 1 )
    return 281;
  if ( v3 <= 4 )
    return 279;
  if ( v3 != 9 )
  {
    if ( v3 == 10 )
      return 280;
    if ( v3 == 12 || v3 == 13 )
    {
      *(_DWORD *)(this + 64) = 1;
      return -1;
    }
    return 281;
  }
  if ( !*(_DWORD *)(this + 76) )
  {
    if ( !strcmp(*(const char **)(this + 640), "defined") )
    {
      *(_DWORD *)(this + 88) = 0;
      return 271;
    }
    if ( !*(_DWORD *)(this + 88) || !sub_65B1A2((_DWORD *)this, *(char **)(this + 640), &v15, &v16) )
      return 278;
    v5 = *(_DWORD *)(this + 68) == 0;
    qmemcpy(ArgList, (const void *)(this + 632), sizeof(ArgList));
    v9 = !v5 || !sub_65B5D6((_DWORD *)this, (int)ArgList, v15, v16);
    *(_DWORD *)(this + 68) = v9;
    if ( v9 )
    {
      result = v15;
    }
    else
    {
      result = sub_65BE3E(this);
      if ( result != -1 )
      {
        v10 = 0;
LABEL_77:
        *(_DWORD *)(this + 68) = v10;
        if ( !v10 )
          return result;
        *(_DWORD *)(this + 72) = 1;
        qmemcpy((void *)(this + 632), ArgList, 0x20u);
        sub_65DD1F(this + 24, this + 632, 1518, "invalid or unsupported integer constant expression", v13);
        return 278;
      }
    }
    v10 = 1;
    goto LABEL_77;
  }
  v5 = *(_DWORD *)(this + 80) == 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 88) = 0;
  v6 = *(_BYTE **)(this + 640);
  if ( !v5 )
  {
    if ( *v6 == 100 )
    {
      if ( !strcmp(*(const char **)(this + 640), "define") )
        return 257;
      goto LABEL_63;
    }
    if ( *v6 != 101 )
    {
      if ( *v6 != 105 )
      {
        if ( *v6 == 108 )
        {
          if ( !strcmp(*(const char **)(this + 640), "line") )
            return 259;
        }
        else if ( *v6 == 112 )
        {
          if ( !strcmp(*(const char **)(this + 640), "pragma") )
            return 270;
        }
        else if ( *v6 == 117 && !strcmp(*(const char **)(this + 640), "undef") )
        {
          return 258;
        }
        goto LABEL_63;
      }
      if ( strcmp(*(const char **)(this + 640), "if") )
      {
        if ( !strcmp(*(const char **)(this + 640), "ifdef") )
          return 263;
        if ( !strcmp(*(const char **)(this + 640), "ifndef") )
          return 264;
        if ( !strcmp(*(const char **)(this + 640), "include") )
          return 260;
        goto LABEL_63;
      }
      result = 262;
LABEL_58:
      *(_DWORD *)(this + 88) = 1;
      return result;
    }
    if ( strcmp(*(const char **)(this + 640), "elif") )
    {
      if ( strcmp(*(const char **)(this + 640), "else") )
      {
        if ( strcmp(*(const char **)(this + 640), "endif") )
        {
          if ( !strcmp(*(const char **)(this + 640), "error") )
            return 261;
          goto LABEL_63;
        }
        return 267;
      }
      return 266;
    }
LABEL_57:
    result = 265;
    goto LABEL_58;
  }
  if ( *v6 != 101 )
  {
    if ( *v6 == 105
      && (!strcmp(*(const char **)(this + 640), "if")
       || !strcmp(*(const char **)(this + 640), "ifdef")
       || !strcmp(*(const char **)(this + 640), "ifndef")) )
    {
      return 268;
    }
    goto LABEL_63;
  }
  if ( !strcmp(*(const char **)(this + 640), "else") )
    return 266;
  if ( !strcmp(*(const char **)(this + 640), "endif") )
    return 267;
  if ( strcmp(*(const char **)(this + 640), "elif") )
  {
LABEL_63:
    *(_DWORD *)(this + 76) = 1;
    return 278;
  }
  v7 = *(_DWORD **)(*(_DWORD *)(this + 616) + 56);
  if ( !v7 )
  {
    *(_DWORD *)(this + 80) = 1;
    goto LABEL_57;
  }
  v8 = v7[1];
  if ( !v8 || *v7 )
    return 269;
  *(_DWORD *)(this + 80) = v8;
  *(_DWORD *)(this + 88) = 1;
  return 265;
}
