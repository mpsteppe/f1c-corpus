signed int __thiscall sub_65D1E3(_DWORD *this, _DWORD *a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  signed int result; // eax
  int v7; // eax
  bool v8; // zf
  int v9; // esi
  int v10; // eax
  int v11; // ecx
  _DWORD *v12; // ebx
  _DWORD *v13; // ecx
  int v14; // ecx
  int v15; // ecx
  char v16; // [esp+0h] [ebp-14h]
  int v17; // [esp+Ch] [ebp-8h] BYREF
  int v18; // [esp+10h] [ebp-4h] BYREF

  do
  {
    while ( 1 )
    {
      if ( this[18] )
      {
        result = -2147467259;
LABEL_44:
        v12 = this + 155;
        a2[4] = *(_DWORD *)(*v12 + 24);
        a2[5] = *(_DWORD *)(*v12 + 28);
        *a2 = 13;
        return result;
      }
      v3 = this[26];
      if ( v3 && !*(_DWORD *)(v3 + 8) )
      {
        result = 0;
        goto LABEL_44;
      }
      v4 = this[25];
      if ( v4 )
      {
        v5 = (int)a2;
        qmemcpy(a2, (const void *)(v4 + 16), 0x20u);
        this[25] = *(_DWORD *)(this[25] + 12);
        *(_DWORD *)(v4 + 12) = 0;
        a2[4] = *(_DWORD *)(this[155] + 24);
        a2[5] = *(_DWORD *)(this[155] + 28);
        this[16] = 0;
      }
      else
      {
        result = sub_65E7A1(this[166], a2);
        if ( result < 0 )
          return result;
        v5 = (int)a2;
      }
      if ( *(_DWORD *)v5 == 1 && !strcmp("#", (const char *)(v5 + 8)) && this[16] )
        break;
      if ( *(_DWORD *)v5 == 13 )
      {
        if ( *(_DWORD *)(this[154] + 56) )
          sub_65DD1F((int)(this + 6), v5, 1502, "unexpected end of file", v16);
        v13 = (_DWORD *)this[154];
        if ( v13[27] )
        {
          this[154] = v13[27];
          v13[27] = 0;
          sub_659D66(v13, 1);
          this[155] = this[154];
          *a2 = 12;
          this[16] = 1;
        }
        return 0;
      }
      if ( *(_DWORD *)v5 == 9 )
      {
        if ( !sub_65B1A2(this, *(char **)(v5 + 8), &v17, &v18) || !sub_65B5D6(this, (int)a2, v17, v18) )
        {
          v5 = (int)a2;
          goto LABEL_34;
        }
      }
      else
      {
LABEL_34:
        if ( *(_DWORD *)v5 == 9 )
        {
          if ( !strcmp(*(const char **)(v5 + 8), "__FILE__") )
          {
            *(_DWORD *)v5 = 10;
            v11 = *(_DWORD *)(this[155] + 24);
            *(_DWORD *)(v5 + 8) = v11;
            if ( !v11 )
              *(_DWORD *)(v5 + 8) = WindowName;
          }
          else if ( !strcmp(*(const char **)(v5 + 8), "__LINE__") )
          {
            *(_DWORD *)v5 = 2;
            *(_DWORD *)(v5 + 8) = *(_DWORD *)(this[155] + 28);
          }
        }
        v8 = this[20] == 0;
        this[16] = *(_DWORD *)v5 == 12;
        if ( !v8 )
        {
          v14 = this[26];
          if ( v14 && *(_DWORD *)(v14 + 4) )
          {
            if ( *(_DWORD *)v5 == 1 && !*(_BYTE *)(v5 + 9) )
            {
              if ( *(_BYTE *)(v5 + 8) == 123 )
                ++*(_DWORD *)(v14 + 8);
              if ( *(_BYTE *)(v5 + 8) == 125 )
              {
                v15 = this[26];
                if ( *(_DWORD *)(v15 + 8) )
                  --*(_DWORD *)(v15 + 8);
              }
            }
            if ( !*(_DWORD *)(this[26] + 8) )
              *(_DWORD *)v5 = 13;
          }
          return 0;
        }
      }
    }
    dword_FB9260 = (int)this;
    v7 = this[20];
    this[16] = 0;
    this[17] = 0;
    this[19] = 1;
    this[21] = v7;
    if ( sub_65CBD1() )
      this[17] = 1;
    v8 = this[16] == 0;
    this[23] = 0;
    if ( v8 && !this[17] )
    {
      result = sub_65E7A1(this[166], this + 158);
      if ( result < 0 )
        return result;
      v9 = this[158];
      if ( v9 == 12 || v9 == 13 )
      {
        this[16] = 1;
      }
      else
      {
        if ( this[20] )
          sub_65DD1F((int)(this + 6), (int)a2, 1501, "unexpected tokens following preprocessor directive", v16);
        this[17] = 1;
      }
    }
    if ( !this[16] )
    {
      sub_65D86A(this[155]);
      this[25] = 0;
      result = sub_65E7A1(this[166], this + 158);
      if ( result < 0 )
        return result;
      this[16] = 1;
    }
    this[155] = this[154];
    v10 = this[21];
    this[20] = v10;
  }
  while ( !v10 );
  qmemcpy(a2, this + 158, 0x20u);
  if ( *(_DWORD *)(this[154] + 108) )
    *a2 = 12;
  return this[18] != 0 ? 0x80004005 : 0;
}
