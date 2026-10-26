int __thiscall sub_648CDA(_DWORD *this, int a2, unsigned int a3)
{
  _DWORD *v3; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int *v8; // eax
  int v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // esi
  unsigned int v12; // edi
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  int v15; // ebx
  int v16; // eax
  _DWORD *v17; // eax
  _DWORD *v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  _DWORD *v22; // [esp+8h] [ebp-2Ch]
  int v23; // [esp+Ch] [ebp-28h]
  unsigned int v25; // [esp+14h] [ebp-20h]
  int v26; // [esp+18h] [ebp-1Ch]
  unsigned int v27; // [esp+1Ch] [ebp-18h]
  int v28; // [esp+20h] [ebp-14h]
  unsigned int v29; // [esp+24h] [ebp-10h]
  unsigned int v30; // [esp+28h] [ebp-Ch]
  int v31; // [esp+2Ch] [ebp-8h]
  int v32; // [esp+30h] [ebp-4h]
  unsigned int v33; // [esp+3Ch] [ebp+8h]
  unsigned int v34; // [esp+40h] [ebp+Ch]
  unsigned int v35; // [esp+40h] [ebp+Ch]

  v3 = this;
  if ( a3 < 4 )
    return -2147467259;
  if ( *(_DWORD *)a2 != 542327876 )
    return -2147467259;
  v34 = a3 - 4;
  if ( v34 < 0x7C )
    return -2147467259;
  v35 = v34 - 124;
  v32 = a2 + 128;
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
  v25 = *(_DWORD *)(a2 + 28);
  if ( !v25 )
    v25 = 1;
  v7 = *(_DWORD *)(a2 + 80);
  if ( (v7 & 4) != 0 )
    v7 = 4;
  v26 = v7 & 0xC4040;
  v8 = &dword_913C58;
  if ( dword_913C58 )
  {
    do
    {
      if ( *(_DWORD *)(a2 + 76) == 32
        && v8[2] == v7
        && ((v7 & 4) == 0 || *(_DWORD *)(a2 + 84) == v8[3])
        && ((v7 & 0xC4462) == 0 || *(_DWORD *)(a2 + 88) == v8[4])
        && ((v7 & 0xE4040) == 0 || *(_DWORD *)(a2 + 92) == v8[5])
        && ((v7 & 0xC4440) == 0 || *(_DWORD *)(a2 + 96) == v8[6])
        && (!v26 || *(_DWORD *)(a2 + 100) == v8[7])
        && ((v7 & 0x80003) == 0 || *(_DWORD *)(a2 + 104) == v8[8]) )
      {
        break;
      }
      v8 += 9;
    }
    while ( *v8 );
    v3 = this;
  }
  v9 = *v8;
  v31 = v9;
  if ( v9 )
  {
    v10 = sub_644568(v9);
    v22 = v10;
    if ( *(char *)(a2 + 10) >= 0 )
      v3[17] = 2 * (v27 == 6) + 3;
    else
      v3[17] = 4;
    if ( v10[1] != 1 )
    {
      v23 = 0;
LABEL_43:
      v28 = 0;
      v11 = (_DWORD *)v35;
      while ( 1 )
      {
        v12 = v3[3];
        v30 = v3[4];
        v33 = v3[5];
        if ( v28 )
        {
          v13 = operator new(0x54u);
          if ( v13 )
            v14 = sub_6464A7(v13);
          else
            v14 = 0;
          if ( !v14 )
            return -2147024882;
          *(_DWORD *)(v26 + 80) = v14;
          v26 = (int)v14;
        }
        else
        {
          v26 = (int)v3;
        }
        v29 = 0;
        if ( !v25 )
          goto LABEL_89;
        v15 = v30;
        do
        {
          v16 = v31;
          if ( v29 )
          {
            v17 = operator new(0x54u);
            if ( v17 )
              v18 = sub_6464A7(v17);
            else
              v18 = 0;
            if ( !v18 )
              return -2147024882;
            v11[19] = v18;
            v11 = v18;
            v16 = v31;
          }
          else
          {
            v11 = (_DWORD *)v26;
          }
          if ( v16 > 877942852 )
          {
            if ( v16 == 894720068 )
            {
LABEL_67:
              v19 = 16 * ((v12 + 3) >> 2);
LABEL_68:
              v20 = v19 * ((unsigned int)(v15 + 3) >> 2);
              goto LABEL_69;
            }
            if ( v16 == 1111970375 || v16 == 1195525970 || v16 == 1498831189 )
            {
LABEL_78:
              v19 = 4 * ((v12 + 1) >> 1);
              goto LABEL_79;
            }
          }
          else
          {
            switch ( v16 )
            {
              case 877942852:
                goto LABEL_67;
              case 827611204:
                v19 = 8 * ((v12 + 3) >> 2);
                goto LABEL_68;
              case 844388420:
                goto LABEL_67;
              case 844715353:
                goto LABEL_78;
              case 861165636:
                goto LABEL_67;
            }
          }
          v19 = v12 * (v22[2] >> 3);
LABEL_79:
          v20 = v15 * v19;
LABEL_69:
          v11[14] = 0;
          v11[15] = 0;
          v21 = v33 * v20;
          *v11 = v31;
          v11[12] = v19;
          v11[1] = v32;
          v11[5] = v33;
          v11[13] = v20;
          v11[3] = v12;
          v11[4] = v30;
          v11[2] = v23;
          if ( v35 < v33 * v20 )
            return -2147467259;
          v32 += v21;
          v35 -= v21;
          if ( v12 == 1 )
            v12 = 1;
          else
            v12 >>= 1;
          if ( v30 == 1 )
            v15 = 1;
          else
            v15 = v30 >> 1;
          v30 = v15;
          if ( v33 == 1 )
            v33 = 1;
          else
            v33 >>= 1;
          ++v29;
        }
        while ( v29 < v25 );
        v3 = this;
LABEL_89:
        if ( ++v28 >= v27 )
          return 0;
      }
    }
    if ( v35 >= 0x400 )
    {
      v32 = a2 + 1152;
      v35 -= 1024;
      v23 = a2 + 128;
      goto LABEL_43;
    }
  }
  return -2147467259;
}
