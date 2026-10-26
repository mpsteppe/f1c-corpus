char *__thiscall sub_6C42BB(_DWORD *this, int a2, int a3)
{
  unsigned int v4; // edx
  int v5; // esi
  int v6; // esi
  int v7; // ecx
  int v8; // edi
  int v9; // ecx
  int v10; // ecx
  int v11; // edi
  _DWORD *v12; // eax
  char *v13; // edi
  int v14; // eax
  char *v15; // ecx
  int v16; // esi
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // esi
  unsigned int v22; // eax
  int v23; // ebx
  unsigned int v25; // [esp+14h] [ebp-10h]
  int v26; // [esp+18h] [ebp-Ch]
  int v27; // [esp+1Ch] [ebp-8h]
  int v28; // [esp+20h] [ebp-4h]
  int v29; // [esp+20h] [ebp-4h]
  char *v30; // [esp+20h] [ebp-4h]
  unsigned int v31; // [esp+2Ch] [ebp+8h]

  v27 = 0;
  v4 = *(_DWORD *)a2 & 0xFFF00000;
  v5 = *(_DWORD *)a2 & 0xFFFFF;
  v25 = v4;
  v26 = v5;
  if ( !a3 )
  {
    if ( v4 != 284164096 )
    {
      switch ( v4 )
      {
        case 0x73500000u:
          v6 = v5 & 0xFFFFF | 0x73D00000;
          break;
        case 0x73600000u:
          v6 = v5 & 0xFFFFF | 0x73E00000;
          break;
        case 0x73700000u:
          v6 = v5 & 0xFFFFF | 0x73F00000;
          break;
        case 0x73800000u:
          v6 = v5 & 0xFFFFF | 0x74000000;
          break;
        default:
          return 0;
      }
      goto LABEL_45;
    }
    v10 = v5;
    v11 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(a2 + 8)) + 4));
    v6 = v5 & 0xFFFFF | 0x73100000;
    v29 = v10;
    if ( (*(_WORD *)(v11 + 4) & 0x208) == 0 )
      goto LABEL_43;
    if ( *(_DWORD *)v11 )
    {
      if ( !strchr(*(const char **)v11, 105)
        && !strchr(*(const char **)v11, 73)
        && !strchr(*(const char **)v11, 98)
        && !strchr(*(const char **)v11, 66)
        && (*(_BYTE *)(v11 + 5) & 8) != 0 )
      {
        v10 = v29;
LABEL_43:
        v9 = v10 | 0x73F00000;
        goto LABEL_44;
      }
      v10 = v29;
    }
    if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(a2 + 8)) + 8) == -1 )
      goto LABEL_45;
    goto LABEL_43;
  }
  switch ( v4 )
  {
    case 0x10F00000u:
      v7 = v5;
      v8 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(a2 + 8)) + 4));
      v6 = v5 & 0xFFFFF | 0x73000000;
      v28 = v7;
      if ( (*(_WORD *)(v8 + 4) & 0x208) != 0 )
      {
        if ( !*(_DWORD *)v8 )
          goto LABEL_19;
        if ( strchr(*(const char **)v8, 105)
          || strchr(*(const char **)v8, 73)
          || strchr(*(const char **)v8, 98)
          || strchr(*(const char **)v8, 66)
          || (*(_BYTE *)(v8 + 5) & 8) == 0 )
        {
          v7 = v28;
LABEL_19:
          if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(a2 + 8)) + 8) == -1 )
            break;
          goto LABEL_22;
        }
        v7 = v28;
      }
LABEL_22:
      v9 = v7 | 0x73B00000;
LABEL_44:
      v6 = v9;
      v27 = 1;
      break;
    case 0x73500000u:
      v6 = v5 & 0xFFFFF | 0x73900000;
      break;
    case 0x73600000u:
      v6 = v5 & 0xFFFFF | 0x73A00000;
      break;
    case 0x73700000u:
      v6 = v5 & 0xFFFFF | 0x73B00000;
      break;
    case 0x73800000u:
      v6 = v5 & 0xFFFFF | 0x73C00000;
      break;
    default:
      return 0;
  }
LABEL_45:
  v12 = (_DWORD *)sub_681186(116);
  if ( v12 )
  {
    v13 = (char *)sub_680CEC(v12);
    v30 = v13;
  }
  else
  {
    v30 = 0;
    v13 = 0;
  }
  if ( !v13 )
    return 0;
  if ( v25 != 284164096 || v27 )
    v14 = sub_6811D1(v13, v6, 2 * v26, v26, 0);
  else
    v14 = sub_6811D1(v13, v6, v26, v26, 0);
  v15 = v13;
  if ( v14 < 0 )
    goto LABEL_71;
  v16 = a2;
  if ( sub_680D22(v13, a2) < 0 )
  {
    v15 = v13;
LABEL_71:
    sub_66238F(v15, 1);
    return 0;
  }
  if ( a3 )
  {
    qmemcpy(*((void **)v13 + 4), *(const void **)(a2 + 16), 4 * *(_DWORD *)(a2 + 12));
    v13 = v30;
    v16 = a2;
    goto LABEL_60;
  }
  **((_DWORD **)v13 + 4) = sub_681AAA(this, this[42], 0, 0, 0.0);
  if ( **((_DWORD **)v13 + 4) == -1 )
    return 0;
  v17 = this[5];
  v18 = *(_DWORD *)(v17 + 4 * **((_DWORD **)v13 + 4));
  v19 = *(_DWORD *)(v17 + 4 * **(_DWORD **)(a2 + 16));
  *(_DWORD *)(v18 + 24) = *(_DWORD *)(v19 + 24);
  *(_DWORD *)(v18 + 20) = *(_DWORD *)(v19 + 20);
LABEL_60:
  qmemcpy(*((void **)v13 + 2), *(const void **)(v16 + 8), 4 * *(_DWORD *)(v16 + 4));
  if ( v27 )
  {
    v31 = 0;
    if ( this[2] )
    {
      v20 = this[5];
      v21 = this[2];
      do
      {
        if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)v20 + 4)) + 5) & 1) != 0 )
        {
          v22 = *(_DWORD *)(*(_DWORD *)v20 + 12);
          if ( v22 >= v31 )
            v31 = v22 + 1;
        }
        v20 += 4;
        --v21;
      }
      while ( v21 );
    }
    if ( this[98] == -1 )
      this[98] = sub_681AAA(this, this[30], v31, 0, 0.0);
    v23 = this[98];
    if ( v23 == -1 )
    {
      v15 = v30;
      goto LABEL_71;
    }
    *(_DWORD *)(*((_DWORD *)v30 + 2) + 4) = v23;
  }
  return v30;
}
