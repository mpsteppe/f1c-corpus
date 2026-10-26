_DWORD *__thiscall sub_697788(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // edi
  const char **v4; // ebx
  _DWORD *v5; // eax
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // edi
  int v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  unsigned int v13; // ebx
  int v14; // esi
  unsigned int v15; // ecx
  char v16; // al
  char v17; // cl
  char v18; // al
  unsigned int v19; // esi
  unsigned int v20; // edi
  char v21; // cl
  char v22; // al
  _DWORD *v23; // eax
  _DWORD *v24; // eax
  _DWORD *v25; // eax
  _DWORD *v26; // eax
  int i; // eax
  int v28; // edx
  int v29; // ecx
  int v30; // eax
  _DWORD *v31; // eax
  int v32; // eax
  int v33; // [esp-4h] [ebp-44h]
  _DWORD *v34; // [esp+Ch] [ebp-34h]
  int v35; // [esp+10h] [ebp-30h]
  unsigned int v36; // [esp+18h] [ebp-28h]
  const char **v37; // [esp+1Ch] [ebp-24h]
  unsigned int v38; // [esp+20h] [ebp-20h]
  _DWORD *v40; // [esp+28h] [ebp-18h]
  int v41; // [esp+28h] [ebp-18h]
  unsigned int v42; // [esp+2Ch] [ebp-14h]
  int v43; // [esp+30h] [ebp-10h]
  unsigned int v44; // [esp+34h] [ebp-Ch]
  _DWORD *v45; // [esp+38h] [ebp-8h]
  char *v46; // [esp+3Ch] [ebp-4h]
  int v47; // [esp+4Ch] [ebp+Ch]
  char *v48; // [esp+4Ch] [ebp+Ch]

  if ( !a3 || *(_DWORD *)(a3 + 4) != 3 || !a2 || a2[1] != 13 )
    return 0;
  v3 = (_DWORD *)a2[4];
  v4 = (const char **)(a3 + 16);
  v34 = v3;
  v37 = (const char **)(a3 + 16);
  v5 = (_DWORD *)sub_65B229(80);
  v45 = v5 ? sub_67F5FE(v5, 0, 23, 0, 0, 1, v4) : 0;
  if ( !v45 )
    return 0;
  if ( !v3 )
    goto LABEL_17;
  v6 = v3[1];
  if ( v6 == 1 )
  {
    v47 = 0;
    v40 = v3;
    while ( 1 )
    {
      v7 = (_DWORD *)v3[2];
      if ( v7 && v7[1] == 6 )
      {
        v8 = v7[6];
        if ( !strcmp(v4[2], *(const char **)(v7[5] + 24)) )
        {
          if ( !*(_DWORD *)(v8 + 32)
            || (v10 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v8 + 32) + 4))(*(_DWORD *)(v8 + 32)),
                (v45[4] = v10) != 0) )
          {
            v11 = (_DWORD *)sub_65B229(64);
            if ( v11 )
              v12 = sub_67F780(v11, 2, v47, v4);
            else
              v12 = 0;
            v45[9] = v12;
            goto LABEL_104;
          }
          return 0;
        }
        v47 += sub_6951CB(this, *(_DWORD **)(v8 + 32));
        v3 = v40;
      }
      v3 = (_DWORD *)v3[3];
      v40 = v3;
      if ( !v3 )
        goto LABEL_17;
    }
  }
  if ( v6 != 9 )
    goto LABEL_17;
  v13 = *(_DWORD *)(a3 + 24);
  v36 = v3[6];
  v38 = v3[7];
  v14 = v3[8] & 0x200;
  v35 = v14;
  v15 = v13 + strlen((const char *)v13);
  v16 = *(_BYTE *)v13;
  v42 = v15;
  if ( *(_BYTE *)v13 == 95 )
  {
    if ( v3[4] != 2 )
      goto LABEL_17;
    if ( v13 + 1 >= v15 || (v43 = 3, *(_BYTE *)(v13 + 1) != 109) )
      v43 = 2;
  }
  else
  {
    if ( v16 <= 96 )
      goto LABEL_17;
    if ( v16 <= 98 || v16 == 103 || v16 == 114 )
    {
      if ( v3[4] > 1u )
        goto LABEL_17;
      v43 = 1;
    }
    else
    {
      if ( v16 <= 118 || v16 > 122 || v3[4] > 1u )
        goto LABEL_17;
      v43 = 0;
    }
  }
  v44 = 0;
  v41 = (int)(v45 + 9);
  if ( v13 < v15 )
  {
    v48 = (char *)(v13 + 2);
    v46 = (char *)(v13 + 3);
    while ( 1 )
    {
      if ( v44 >= 4 )
      {
LABEL_87:
        if ( v13 >= v42 && v44 <= 4 )
        {
          v14 = v35;
          v3 = v34;
          break;
        }
LABEL_17:
        sub_694B97((int)this, (int)v37, 3018, "invalid subscript '%s'", v37[2]);
        return 0;
      }
      if ( v43 )
      {
        if ( v43 != 1 )
        {
          if ( v43 == 2 )
          {
            if ( (unsigned int)v48 >= v42 )
              goto LABEL_17;
            if ( *(_BYTE *)v13 != 95 )
              goto LABEL_17;
            v21 = *(_BYTE *)(v13 + 1);
            if ( v21 < 49 )
              goto LABEL_17;
            if ( v21 > 57 )
              goto LABEL_17;
            v22 = *v48;
            if ( *v48 < 49 || v22 > 57 )
              goto LABEL_17;
            v46 += 3;
            v19 = v21 - 49;
            v20 = v22 - 49;
            v13 += 3;
            v48 += 3;
          }
          else
          {
            if ( (unsigned int)v46 >= v42 )
              goto LABEL_17;
            if ( *(_BYTE *)v13 != 95 )
              goto LABEL_17;
            if ( *(_BYTE *)(v13 + 1) != 109 )
              goto LABEL_17;
            v17 = *v48;
            if ( *v48 < 48 )
              goto LABEL_17;
            if ( v17 > 57 )
              goto LABEL_17;
            v18 = *v46;
            if ( *v46 < 48 || v18 > 57 )
              goto LABEL_17;
            v46 += 4;
            v19 = v17 - 48;
            v20 = v18 - 48;
            v13 += 4;
            v48 += 4;
          }
          goto LABEL_76;
        }
        switch ( *(_BYTE *)v13 )
        {
          case 'a':
LABEL_73:
            v33 = 3;
            goto LABEL_74;
          case 'b':
            goto LABEL_72;
          case 'g':
            goto LABEL_67;
        }
        if ( *(_BYTE *)v13 != 114 )
          goto LABEL_17;
      }
      else
      {
        if ( *(_BYTE *)v13 == 119 )
          goto LABEL_73;
        if ( *(_BYTE *)v13 != 120 )
        {
          if ( *(_BYTE *)v13 != 121 )
          {
            if ( *(_BYTE *)v13 != 122 )
              goto LABEL_17;
LABEL_72:
            v33 = 2;
LABEL_74:
            v20 = v33;
            goto LABEL_75;
          }
LABEL_67:
          v20 = 1;
          goto LABEL_75;
        }
      }
      v20 = 0;
LABEL_75:
      v19 = 0;
      ++v13;
      ++v46;
      ++v48;
LABEL_76:
      if ( v19 >= v36 || v20 >= v38 )
        goto LABEL_17;
      v23 = (_DWORD *)sub_65B229(20);
      if ( v23 )
        v24 = sub_67ED1B(v23, 0, 0, (int)"Swizzle");
      else
        v24 = 0;
      *(_DWORD *)v41 = v24;
      if ( !v24 )
        return 0;
      v25 = (_DWORD *)sub_65B229(64);
      v26 = v25 ? sub_67F780(v25, 2, v20 + v38 * v19, v37) : 0;
      *(_DWORD *)(*(_DWORD *)v41 + 8) = v26;
      if ( !v26 )
        return 0;
      ++v44;
      v41 = *(_DWORD *)v41 + 12;
      if ( v13 >= v42 )
        goto LABEL_87;
    }
  }
  for ( i = v45[9]; i && !v14; i = v28 )
  {
    v28 = *(_DWORD *)(i + 12);
    v29 = v28;
    if ( v28 )
    {
      v30 = *(_DWORD *)(*(_DWORD *)(i + 8) + 24);
      while ( v30 != *(_DWORD *)(*(_DWORD *)(v29 + 8) + 24) )
      {
        v29 = *(_DWORD *)(v29 + 12);
        if ( !v29 )
          goto LABEL_98;
      }
      v14 = 1;
    }
LABEL_98:
    ;
  }
  v31 = (_DWORD *)sub_65B229(36);
  if ( v31 )
    v12 = sub_67F2D4(v31, v44 != 1, v3[5], 1, v44, v14 != 0 ? 0x200 : 0);
  else
    v12 = 0;
  v45[4] = v12;
LABEL_104:
  if ( !v12 )
    return 0;
  v32 = (*(int (__thiscall **)(_DWORD *))(*a2 + 4))(a2);
  v45[8] = v32;
  if ( !v32 )
    goto LABEL_17;
  sub_695BDE(this, v45);
  return v45;
}
