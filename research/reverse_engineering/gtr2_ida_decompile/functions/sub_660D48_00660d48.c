int __thiscall sub_660D48(_DWORD **this, int a2, int a3)
{
  _BYTE *v3; // edx
  bool v4; // zf
  _DWORD **v5; // esi
  int v6; // edi
  _DWORD *v7; // eax
  unsigned int v8; // eax
  char *v9; // esi
  char v10; // al
  int v11; // edi
  unsigned int i; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  _DWORD *v17; // ecx
  int result; // eax
  int v19; // eax
  char String[16]; // [esp+Ch] [ebp-3Ch] BYREF
  int v21; // [esp+1Ch] [ebp-2Ch]
  int v22; // [esp+20h] [ebp-28h]
  int v23; // [esp+24h] [ebp-24h]
  int v24; // [esp+28h] [ebp-20h]
  _BYTE *v25; // [esp+2Ch] [ebp-1Ch]
  char ArgList[4]; // [esp+30h] [ebp-18h]
  _BYTE *v27; // [esp+34h] [ebp-14h]
  int v28; // [esp+38h] [ebp-10h] BYREF
  _DWORD **v29; // [esp+3Ch] [ebp-Ch]
  int v30; // [esp+40h] [ebp-8h] BYREF
  unsigned int v31; // [esp+44h] [ebp-4h] BYREF

  v3 = *(_BYTE **)(a2 + 8);
  v4 = *v3 == 0;
  v5 = this;
  v6 = a3;
  v29 = this;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v22 = 0;
  v21 = 1;
  v24 = 0;
  v23 = 0;
  *(_DWORD *)ArgList = v3;
  v25 = v3;
  v27 = v3;
  if ( v4 )
  {
LABEL_2:
    v7 = v5[30];
    if ( !v7 )
      goto LABEL_100;
    if ( v7[44] )
    {
      if ( v30 == 3 || v30 == 15 || v30 == 18 || v30 == 19 )
        goto LABEL_100;
      sub_65DD1F(
        *v5,
        a2,
        2005,
        "temporary, constant, and output registers are not allowed in vs_3_0 assembly fragments");
    }
    else
    {
      if ( v30 == 3 || v30 == 5 || v30 == 6 || v30 == 8 || v30 == 9 || v30 == 4 || v30 == 15 || v30 == 18 || v30 == 19 )
        goto LABEL_100;
      sub_65DD1F(*v5, a2, 2005, "temporary and constant registers are not allowed in assembly fragments");
    }
LABEL_118:
    v5[19] = (_DWORD *)1;
    if ( sub_65B229(44) )
      return sub_680B7C(-1, 0, 0, 0, 0);
    return 0;
  }
  while ( 1 )
  {
    while ( *v3 && *v3 != 95 )
      v27 = ++v3;
    v8 = v3 - v25;
    if ( (unsigned int)(v3 - v25) > 0xF )
      break;
    qmemcpy(String, v25, v8);
    v4 = *v3 == 0;
    String[v8] = 0;
    if ( !v4 )
      v27 = ++v3;
    v25 = v3;
    if ( v21 )
    {
      v9 = String;
      if ( !String[0] )
        goto LABEL_21;
      do
      {
        if ( !sub_633848() )
          break;
        ++v9;
      }
      while ( *v9 );
      if ( *v9 )
        v31 = j__atol(v9);
      else
LABEL_21:
        v31 = -1;
      if ( *v9 )
        *v9++ = 0;
      v10 = *v9;
      if ( *v9 )
      {
        do
        {
          if ( !isdigit(v10) )
            break;
          v10 = *++v9;
        }
        while ( *v9 );
        if ( *v9 )
        {
LABEL_97:
          v5 = v29;
          break;
        }
      }
      v11 = 0;
      for ( i = 0; i < 0x5E8; i += 72 )
      {
        if ( !strcmp(String, *(const char **)((char *)&off_7394F0 + i)) )
          break;
        ++v11;
      }
      v5 = v29;
      if ( v11 == 21 )
        break;
      v13 = (int)v29[14];
      v14 = dword_7394F8[18 * v11 + v13];
      if ( v14 == -1 )
        break;
      if ( v14 >= 0 )
      {
        if ( a3 )
          break;
      }
      else
      {
        if ( v31 == -1 )
        {
          if ( !a3 )
            break;
          v31 = *(_DWORD *)(a3 + 24);
        }
        else if ( a3 )
        {
          v31 += *(_DWORD *)(a3 + 24);
        }
        v14 = -v14;
      }
      if ( v31 == -1 )
      {
        if ( v14 )
          break;
        v31 = 0;
      }
      else if ( (!a3 || !*(_DWORD *)(a3 + 40)) && v31 >= v14 )
      {
        break;
      }
      v15 = dword_7394F4[18 * v11];
      v22 = dword_739534[18 * v11];
      v30 = v15;
      switch ( v15 )
      {
        case 2:
          v31 &= 0x1FFFu;
          if ( v31 >= 0x800 )
          {
            if ( v31 >= 0x1000 )
            {
              if ( v31 >= 0x1800 )
                v30 = 13;
              else
                v30 = 12;
            }
            else
            {
              v30 = 11;
            }
          }
          else
          {
            v30 = 2;
          }
          v31 &= 0x7FFu;
          break;
        case -3:
          v30 = 4;
          goto LABEL_58;
        case -4:
          v30 = 4;
          v31 = 2;
          break;
        case -5:
          v30 = 4;
          goto LABEL_67;
        case -6:
          v30 = 17;
LABEL_58:
          v31 = 0;
          break;
        case -7:
          v30 = 17;
LABEL_67:
          v31 = 1;
          break;
      }
      v21 = 0;
      if ( v13 >= 6 && v13 <= 9 )
        v24 = 1;
      if ( v13 >= 4 && v13 <= 5 || v13 >= 13 && v13 <= 14 )
        v23 = 1;
      v3 = v27;
      goto LABEL_77;
    }
    if ( !v24 )
    {
LABEL_93:
      if ( !v23 || strcmp(String, (const char *)&off_739CB4) )
        goto LABEL_97;
      v28 = 184549376;
      v23 = 0;
      goto LABEL_96;
    }
    if ( !strcmp(String, "bias") )
    {
      v16 = (int)&dword_2000000;
    }
    else if ( !strcmp(String, "bx2") )
    {
      v16 = 0x4000000;
    }
    else if ( !strcmp(String, "x2") )
    {
      v16 = 117440512;
    }
    else if ( !strcmp(String, "dz") || !strcmp(String, "db") )
    {
      v16 = 150994944;
    }
    else
    {
      if ( strcmp(String, "dw") && strcmp(String, "da") )
        goto LABEL_93;
      v16 = 167772160;
    }
    v28 = v16;
    v24 = 0;
LABEL_96:
    v5 = v29;
LABEL_77:
    if ( !*v3 )
    {
      v6 = a3;
      goto LABEL_2;
    }
  }
  v17 = v5[30];
  if ( !v17 )
  {
    if ( a3 )
    {
      v19 = *(_DWORD *)(a3 + 40);
      if ( v19 )
      {
        if ( *(_DWORD *)(v19 + 16) != -1 )
          sub_65DD1F(*v5, a2, 2005, "invalid register '%s[...]'", *(_DWORD *)ArgList);
      }
      else
      {
        sub_65DD1F(*v5, a2, 2005, "invalid register '%s[%u]'", *(const char **)ArgList, *(_DWORD *)(a3 + 24));
      }
    }
    else
    {
      sub_65DD1F(*v5, a2, 2005, "invalid register '%s'", *(_DWORD *)ArgList);
    }
    goto LABEL_118;
  }
  v6 = a3;
  if ( sub_6608D7(v17, *v5, (int)v5[31], a2, *(char **)ArgList, a3, &v30, (unsigned int)&v28, &v31) < 0 )
    goto LABEL_118;
LABEL_100:
  if ( sub_65B229(44) )
    result = sub_680B7C(v30, v28, v31, v22, 0);
  else
    result = 0;
  if ( !result )
    return 0;
  if ( v6 )
  {
    *(_DWORD *)(result + 40) = *(_DWORD *)(v6 + 40);
    *(_DWORD *)(v6 + 40) = 0;
  }
  return result;
}
