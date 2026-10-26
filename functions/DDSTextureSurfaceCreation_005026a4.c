int __thiscall sub_5026A4(_DWORD *this, int a2, unsigned int a3)
{
  _DWORD *v3; // ebx
  int v5; // eax
  int v6; // eax
  int *v7; // edi
  int v8; // eax
  int v9; // edi
  float *v10; // eax
  _DWORD *v11; // esi
  _DWORD *v12; // eax
  unsigned int v13; // edi
  int v14; // ebx
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  float *v21; // [esp+8h] [ebp-2Ch]
  int v22; // [esp+Ch] [ebp-28h]
  int v23; // [esp+10h] [ebp-24h]
  unsigned int v24; // [esp+14h] [ebp-20h]
  unsigned int v25; // [esp+18h] [ebp-1Ch]
  _DWORD *v26; // [esp+1Ch] [ebp-18h]
  unsigned int v27; // [esp+20h] [ebp-14h]
  int v28; // [esp+24h] [ebp-10h]
  int v29; // [esp+28h] [ebp-Ch]
  int v31; // [esp+30h] [ebp-4h]
  unsigned int v32; // [esp+3Ch] [ebp+8h]
  unsigned int v33; // [esp+40h] [ebp+Ch]
  unsigned int v34; // [esp+40h] [ebp+Ch]

  v3 = this;
  if ( a3 < 4 )
    return -2147467259;
  if ( *(_DWORD *)a2 != 542327876 )
    return -2147467259;
  v33 = a3 - 4;
  if ( v33 < 0x7C )
    return -2147467259;
  v34 = v33 - 124;
  v31 = a2 + 128;
  this[3] = *(_DWORD *)(a2 + 16);
  this[4] = *(_DWORD *)(a2 + 12);
  if ( *(char *)(a2 + 10) >= 0 )
    v5 = 1;
  else
    v5 = *(_DWORD *)(a2 + 24);
  this[5] = v5;
  if ( !v5 )
    this[5] = 1;
  v6 = *(_DWORD *)(a2 + 112) & 0xFC00;
  if ( v6 == 64512 )
  {
    v27 = 6;
  }
  else
  {
    if ( v6 )
      return -2147467259;
    v27 = 1;
  }
  v24 = *(_DWORD *)(a2 + 28);
  if ( !v24 )
    v24 = 1;
  v7 = &dword_5D71F8;
  if ( dword_5D71F8 )
  {
    do
    {
      if ( *(_DWORD *)(a2 + 76) == 32 )
      {
        v8 = v7[2];
        if ( *(_DWORD *)(a2 + 80) == v8 )
        {
          if ( ((v8 & 4) == 0 || *(_DWORD *)(a2 + 84) == v7[3])
            && ((v8 & 0xC4462) == 0 || *(_DWORD *)(a2 + 88) == v7[4])
            && ((v8 & 0xE4040) == 0 || *(_DWORD *)(a2 + 92) == v7[5])
            && ((v8 & 0xC4440) == 0 || *(_DWORD *)(a2 + 96) == v7[6])
            && ((v8 & 0xC4040) == 0 || *(_DWORD *)(a2 + 100) == v7[7])
            && ((v8 & 0x80003) == 0 || *(_DWORD *)(a2 + 104) == v7[8]) )
          {
            v3 = this;
            break;
          }
          v3 = this;
        }
      }
      v7 += 9;
    }
    while ( *v7 );
  }
  v9 = *v7;
  v23 = v9;
  if ( v9 )
  {
    v10 = IDToStructTableLookup(v9);
    v21 = v10;
    if ( *(char *)(a2 + 10) >= 0 )
      v3[17] = 2 * (v27 == 6) + 3;
    else
      v3[17] = 4;
    if ( *((_DWORD *)v10 + 1) != 1 )
    {
      v22 = 0;
LABEL_43:
      v28 = 0;
      v11 = (_DWORD *)v34;
      while ( 1 )
      {
        v12 = this;
        v13 = v3[3];
        v14 = v3[4];
        v25 = v14;
        v32 = this[5];
        if ( v28 )
        {
          v15 = (_DWORD *)OperatorNewNhMallocWrapper(84);
          if ( v15 )
            v12 = F_7FieldInitializer(v15);
          else
            v12 = 0;
          if ( !v12 )
            return -2147024882;
          v26[20] = v12;
        }
        v29 = 0;
        v26 = v12;
        if ( v24 )
        {
          while ( 1 )
          {
            if ( v29 )
            {
              v16 = (_DWORD *)OperatorNewNhMallocWrapper(84);
              if ( v16 )
                v17 = F_7FieldInitializer(v16);
              else
                v17 = 0;
              if ( !v17 )
                return -2147024882;
              v11[19] = v17;
              v11 = v17;
            }
            else
            {
              v11 = v26;
            }
            if ( v23 == 827611204 )
              break;
            switch ( v23 )
            {
              case 844388420:
                goto LABEL_70;
              case 844715353:
                goto LABEL_68;
              case 861165636:
              case 877942852:
              case 894720068:
LABEL_70:
                v18 = 16 * ((v13 + 3) >> 2);
LABEL_72:
                v19 = v18 * ((unsigned int)(v14 + 3) >> 2);
                goto LABEL_73;
              case 1498831189:
LABEL_68:
                v18 = 4 * ((v13 + 1) >> 1);
                break;
              default:
                v18 = v13 * (*((_DWORD *)v21 + 2) >> 3);
                break;
            }
            v19 = v14 * v18;
LABEL_73:
            v11[14] = 0;
            v11[15] = 0;
            v20 = v32 * v19;
            *v11 = v23;
            v11[12] = v18;
            v11[1] = v31;
            v11[5] = v32;
            v11[13] = v19;
            v11[3] = v13;
            v11[4] = v25;
            v11[2] = v22;
            if ( v34 < v32 * v19 )
              return -2147467259;
            v31 += v20;
            v34 -= v20;
            if ( v13 == 1 )
              v13 = 1;
            else
              v13 >>= 1;
            if ( v25 == 1 )
              v14 = 1;
            else
              v14 = v25 >> 1;
            v25 = v14;
            if ( v32 == 1 )
              v32 = 1;
            else
              v32 >>= 1;
            if ( ++v29 >= v24 )
              goto LABEL_84;
          }
          v18 = 8 * ((v13 + 3) >> 2);
          goto LABEL_72;
        }
LABEL_84:
        if ( ++v28 >= v27 )
          return 0;
        v3 = this;
      }
    }
    if ( v34 >= 0x400 )
    {
      v31 = a2 + 1152;
      v34 -= 1024;
      v22 = a2 + 128;
      goto LABEL_43;
    }
  }
  return -2147467259;
}
