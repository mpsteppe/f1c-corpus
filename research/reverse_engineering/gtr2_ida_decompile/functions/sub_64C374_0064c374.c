int __usercall sub_64C374@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, float *a3@<esi>)
{
  _DWORD *v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // esi
  int v8; // edi
  int v9; // ecx
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  int v14; // esi
  float *v15; // eax
  int v16; // esi
  char *v17; // eax
  char *v18; // esi
  char *v19; // eax
  int v20; // esi
  char *v21; // eax
  int v22; // esi
  unsigned int v23; // edx
  float *v24; // eax
  float *v25; // ecx
  double v26; // st6
  float *v27; // edi
  double v28; // st5
  double v29; // st4
  float *v30; // eax
  double v31; // st6
  double v32; // st5
  double v33; // st4
  float *v34; // eax
  float v37; // [esp+4h] [ebp-5Ch]
  float v38; // [esp+8h] [ebp-58h]
  float v39; // [esp+14h] [ebp-4Ch]
  float v40; // [esp+20h] [ebp-40h]
  float v41; // [esp+2Ch] [ebp-34h]
  float v42; // [esp+30h] [ebp-30h]
  float v43; // [esp+34h] [ebp-2Ch]
  float v44; // [esp+38h] [ebp-28h]
  float v45; // [esp+3Ch] [ebp-24h]
  float v46; // [esp+40h] [ebp-20h]
  float *Block; // [esp+44h] [ebp-1Ch]
  char *Blocka; // [esp+44h] [ebp-1Ch]
  char *Blockb; // [esp+44h] [ebp-1Ch]
  char *Blockc; // [esp+44h] [ebp-1Ch]
  char *v51; // [esp+48h] [ebp-18h]
  float *v52; // [esp+4Ch] [ebp-14h]
  float *v53; // [esp+50h] [ebp-10h]
  unsigned int v54; // [esp+54h] [ebp-Ch]
  char *v55; // [esp+58h] [ebp-8h]
  char *v56; // [esp+5Ch] [ebp-4h]

  if ( *((_BYTE *)a1 + 8) != 5 )
    return -2147467259;
  v5 = (_DWORD *)*a1;
  v6 = *(_DWORD *)(*a1 + 104);
  v7 = (_DWORD *)a1[1];
  v8 = v7[26];
  if ( v8 != v6 >> 1 && (v8 != 1 || v6 != 1) )
    return -2147467259;
  v9 = v7[27];
  if ( v9 != v5[27] >> 1 && (v9 != 1 || v5[27] != 1) )
    return -2147467259;
  if ( v7[28] != 1 || v5[28] != 1 )
    return -2147467259;
  if ( v6 > 1 && (v6 & 1) != 0 )
  {
    v5[26] &= ~1u;
    *(_DWORD *)(*a1 + 116) -= *(_DWORD *)(*a1 + 120);
  }
  if ( *(_DWORD *)(*a1 + 108) > 1u )
    *(_DWORD *)(*a1 + 108) &= ~1u;
  if ( (*((_BYTE *)a1 + 10) & 8) == 0 )
  {
    v10 = (_DWORD *)*a1;
    v11 = a1[1];
    v12 = *(_DWORD *)(*a1 + 4);
    if ( v12 == *(_DWORD *)(v11 + 4) && v10[26] >= 2u && v10[27] >= 2u && !*(_DWORD *)(v11 + 16) && !v10[4] )
    {
      if ( v12 <= 29 )
      {
        if ( v12 != 29 )
        {
          switch ( v12 )
          {
            case 21:
              goto LABEL_37;
            case 22:
              goto LABEL_36;
            case 23:
              v13 = sub_64B328(a1);
              goto LABEL_45;
            case 24:
              v13 = sub_64B45C(a1);
              goto LABEL_45;
            case 25:
              v13 = sub_64B561(a1);
              goto LABEL_45;
            case 26:
              v13 = sub_64B68A(a1);
              goto LABEL_45;
            case 27:
              v13 = sub_64B7C1(a1);
              goto LABEL_45;
            case 28:
              goto LABEL_44;
            default:
              goto LABEL_47;
          }
        }
        v13 = sub_64B96B(a1);
LABEL_45:
        if ( v13 >= 0 )
          return 0;
        goto LABEL_47;
      }
      if ( v12 > 41 )
      {
        switch ( v12 )
        {
          case '2':
LABEL_44:
            v13 = sub_64B8DF(a1);
            goto LABEL_45;
          case '3':
            v13 = sub_64BBA2(a1);
            goto LABEL_45;
          case '4':
            v13 = sub_64BCD0(a1);
            goto LABEL_45;
        }
      }
      else if ( *(_DWORD *)(*a1 + 4) != 41 )
      {
        switch ( v12 )
        {
          case 30:
            v13 = sub_64BA99(a1);
            goto LABEL_45;
          case 32:
LABEL_37:
            v13 = sub_64B073();
            goto LABEL_45;
          case 33:
LABEL_36:
            v13 = sub_64B306(a1);
            goto LABEL_45;
        }
      }
    }
  }
LABEL_47:
  v14 = *(_DWORD *)(a1[1] + 104);
  v15 = (float *)operator new(16 * v14);
  Block = v15;
  if ( v15 )
  {
    sub_41D1B0((int)v15, 16, v14, (int)sub_681563);
    v53 = Block;
  }
  else
  {
    v53 = 0;
  }
  if ( !v53 )
    return -2147024882;
  v16 = *(_DWORD *)(*a1 + 104);
  if ( *(_DWORD *)(*a1 + 108) == 1 )
  {
    v17 = (char *)operator new(16 * v16);
    Blocka = v17;
    if ( v17 )
    {
      sub_41D1B0((int)v17, 16, v16, (int)sub_681563);
      v18 = Blocka;
      v56 = Blocka;
    }
    else
    {
      v56 = 0;
      v18 = 0;
    }
    v19 = v18;
    v55 = v18;
  }
  else
  {
    v20 = 2 * v16;
    v21 = (char *)operator new(16 * v20);
    Blockb = v21;
    if ( v21 )
    {
      sub_41D1B0((int)v21, 16, v20, (int)sub_681563);
      v56 = Blockb;
    }
    else
    {
      v56 = 0;
    }
    v18 = v56;
    v19 = &v56[16 * *(_DWORD *)(*a1 + 104)];
    v55 = v19;
  }
  if ( v18 )
  {
    if ( *(_DWORD *)(*a1 + 104) == 1 )
    {
      v51 = v18;
    }
    else
    {
      v51 = v18 + 16;
      v19 += 16;
    }
    v54 = 0;
    for ( Blockc = v19; v54 < *(_DWORD *)(a1[1] + 108); ++v54 )
    {
      (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, char *, int, float *))(*(_DWORD *)*a1 + 4))(
        *a1,
        2 * v54,
        0,
        v18,
        a2,
        a3);
      if ( v55 != v18 )
        (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, char *))(*(_DWORD *)*a1 + 4))(*a1, 2 * v54 + 1, 0, v55);
      v23 = 0;
      if ( *(_DWORD *)(a1[1] + 104) )
      {
        v52 = v53;
        do
        {
          v24 = (float *)&v51[32 * v23];
          v25 = (float *)&v56[32 * v23];
          v26 = *v24 + *v25;
          v27 = v52;
          v28 = v24[1];
          v52 += 4;
          v41 = v24[2] + v25[2];
          v29 = v24[3];
          v30 = (float *)&v55[32 * v23];
          v42 = v29 + v25[3];
          v39 = v26 + *v30;
          v31 = v28 + v25[1] + v30[1];
          v32 = v41 + v30[2];
          v33 = v42 + v30[3];
          v34 = (float *)&Blockc[32 * v23];
          v40 = v33;
          ++v23;
          v37 = v39 + *v34;
          v38 = v31 + v34[1];
          v43 = v37 * 0.25;
          v44 = v38 * 0.25;
          v45 = (v32 + v34[2]) * 0.25;
          v46 = (v40 + v34[3]) * 0.25;
          *v27++ = v43;
          *v27++ = v44;
          *v27 = v45;
          v27[1] = v46;
        }
        while ( v23 < *(_DWORD *)(a1[1] + 104) );
        v18 = v56;
      }
      a3 = v53;
      a2 = 0;
      (*(void (__thiscall **)(_DWORD, unsigned int))(*(_DWORD *)a1[1] + 8))(a1[1], v54);
    }
    j__free(v18);
    v22 = 0;
  }
  else
  {
    v22 = -2147024882;
  }
  j__free(v53);
  return v22;
}
