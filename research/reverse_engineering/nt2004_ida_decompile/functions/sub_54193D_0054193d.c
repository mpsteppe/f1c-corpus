int __usercall sub_54193D@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, float *a3@<esi>)
{
  _DWORD *v5; // ecx
  unsigned int v6; // eax
  _DWORD *v7; // edx
  int v8; // esi
  int v9; // esi
  _DWORD *v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  int v20; // esi
  float *v21; // eax
  int v22; // esi
  char *v23; // eax
  char *v24; // eax
  int v25; // esi
  char *v26; // eax
  char *v27; // ecx
  int v28; // esi
  char *v29; // ecx
  unsigned int v30; // edx
  float *v31; // eax
  float *v32; // ecx
  double v33; // st6
  float *v34; // edi
  double v35; // st5
  double v36; // st4
  float *v37; // eax
  double v38; // st6
  double v39; // st5
  double v40; // st4
  float *v41; // eax
  float v44; // [esp+4h] [ebp-6Ch]
  float v45; // [esp+8h] [ebp-68h]
  float v46; // [esp+14h] [ebp-5Ch]
  float v47; // [esp+20h] [ebp-50h]
  float v48; // [esp+2Ch] [ebp-44h]
  float v49; // [esp+30h] [ebp-40h]
  float v50; // [esp+34h] [ebp-3Ch]
  float v51; // [esp+38h] [ebp-38h]
  float v52; // [esp+3Ch] [ebp-34h]
  float v53; // [esp+40h] [ebp-30h]
  float *v54; // [esp+44h] [ebp-2Ch]
  char *v55; // [esp+44h] [ebp-2Ch]
  char *v56; // [esp+44h] [ebp-2Ch]
  char *v57; // [esp+44h] [ebp-2Ch]
  char *v58; // [esp+48h] [ebp-28h]
  char *v59; // [esp+4Ch] [ebp-24h]
  float *v60; // [esp+50h] [ebp-20h]
  float *v61; // [esp+54h] [ebp-1Ch]
  unsigned int i; // [esp+58h] [ebp-18h]
  char *v63; // [esp+5Ch] [ebp-14h]
  char *v64; // [esp+60h] [ebp-10h]

  if ( *((_BYTE *)a1 + 8) != 5 )
    return -2147467259;
  v5 = (_DWORD *)*a1;
  v6 = *(_DWORD *)(*a1 + 4184);
  v7 = (_DWORD *)a1[1];
  v8 = v7[1046];
  if ( v8 != v6 >> 1 && (v8 != 1 || v6 != 1) )
    return -2147467259;
  v9 = v7[1047];
  if ( v9 != v5[1047] >> 1 && (v9 != 1 || v5[1047] != 1) )
    return -2147467259;
  if ( v7[1048] != 1 || v5[1048] != 1 )
    return -2147467259;
  if ( v6 > 1 && (v6 & 1) != 0 )
  {
    v5[1046] = v6 & 0xFFFFFFFE;
    *(_DWORD *)(*a1 + 4196) -= *(_DWORD *)(*a1 + 4200);
  }
  v10 = (_DWORD *)(*a1 + 4188);
  if ( *v10 > 1u )
    *v10 &= ~1u;
  if ( (*((_BYTE *)a1 + 10) & 8) != 0 )
    goto LABEL_44;
  v11 = *a1;
  v12 = *(_DWORD *)(*a1 + 4);
  if ( v12 != *(_DWORD *)(a1[1] + 4) || *(_DWORD *)(v11 + 4184) < 2u || *(_DWORD *)(v11 + 4188) < 2u )
    goto LABEL_44;
  if ( v12 <= 28 )
  {
    if ( v12 != 28 )
    {
      switch ( v12 )
      {
        case 21:
          v13 = sub_54045F();
          goto LABEL_42;
        case 22:
          v13 = sub_5406F5();
          goto LABEL_42;
        case 23:
          v13 = sub_540726(a1);
          goto LABEL_42;
        case 24:
          v13 = sub_540876(a1);
          goto LABEL_42;
        case 25:
          v13 = sub_54099A(a1);
          goto LABEL_42;
        case 26:
          v13 = sub_540AE9(a1);
          goto LABEL_42;
        case 27:
          v13 = sub_540C3C(a1);
          goto LABEL_42;
        default:
          goto LABEL_44;
      }
    }
    goto LABEL_39;
  }
  v14 = v12 - 29;
  if ( !v14 )
  {
    v13 = sub_540E16(a1);
LABEL_42:
    if ( v13 >= 0 )
      return 0;
    goto LABEL_44;
  }
  v15 = v14 - 1;
  if ( !v15 )
  {
    v13 = sub_540F62(a1);
    goto LABEL_42;
  }
  v16 = v15 - 10;
  if ( v16 )
  {
    v17 = v16 - 1;
    if ( v17 )
    {
      v18 = v17 - 9;
      if ( !v18 )
      {
LABEL_39:
        v13 = sub_540D7B(a1);
        goto LABEL_42;
      }
      v19 = v18 - 1;
      if ( !v19 )
      {
        v13 = sub_541083(a1);
        goto LABEL_42;
      }
      if ( v19 == 1 )
      {
        v13 = sub_5411CF(a1);
        goto LABEL_42;
      }
    }
  }
LABEL_44:
  v20 = *(_DWORD *)(a1[1] + 4184);
  v21 = (float *)operator new(16 * v20);
  v54 = v21;
  if ( v21 )
  {
    sub_53D688((int)v21, 16, v20, (int (__thiscall *)(int))sub_53D5B2);
    v61 = v54;
  }
  else
  {
    v61 = 0;
  }
  if ( !v61 )
    return -2147024882;
  v22 = *(_DWORD *)(*a1 + 4184);
  if ( *(_DWORD *)(*a1 + 4188) == 1 )
  {
    v23 = (char *)operator new(16 * v22);
    v55 = v23;
    if ( v23 )
    {
      sub_53D688((int)v23, 16, v22, (int (__thiscall *)(int))sub_53D5B2);
      v24 = v55;
    }
    else
    {
      v24 = 0;
    }
    v59 = v24;
    v63 = v24;
  }
  else
  {
    v25 = 2 * v22;
    v26 = (char *)operator new(16 * v25);
    v56 = v26;
    if ( v26 )
    {
      sub_53D688((int)v26, 16, v25, (int (__thiscall *)(int))sub_53D5B2);
      v27 = v56;
    }
    else
    {
      v27 = 0;
    }
    v59 = v27;
    v63 = v27;
    v24 = &v27[16 * *(_DWORD *)(*a1 + 4184)];
  }
  v64 = v24;
  if ( v59 )
  {
    if ( *(_DWORD *)(*a1 + 4184) == 1 )
    {
      v58 = v63;
      v29 = v24;
    }
    else
    {
      v58 = v63 + 16;
      v29 = v24 + 16;
    }
    v57 = v29;
    for ( i = 0; i < *(_DWORD *)(a1[1] + 4188); ++i )
    {
      (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, char *, int, float *))(*(_DWORD *)*a1 + 4))(
        *a1,
        2 * i,
        0,
        v63,
        a2,
        a3);
      if ( v64 != v63 )
        (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, char *))(*(_DWORD *)*a1 + 4))(*a1, 2 * i + 1, 0, v64);
      v30 = 0;
      if ( *(_DWORD *)(a1[1] + 4184) )
      {
        v60 = v61;
        do
        {
          v31 = (float *)&v58[32 * v30];
          v32 = (float *)&v63[32 * v30];
          v33 = *v31 + *v32;
          v34 = v60;
          v35 = v31[1];
          v60 += 4;
          v48 = v31[2] + v32[2];
          v36 = v31[3];
          v37 = (float *)&v64[32 * v30];
          v49 = v36 + v32[3];
          v46 = v33 + *v37;
          v38 = v35 + v32[1] + v37[1];
          v39 = v48 + v37[2];
          v40 = v49 + v37[3];
          v41 = (float *)&v57[32 * v30];
          v47 = v40;
          ++v30;
          v44 = v46 + *v41;
          v45 = v38 + v41[1];
          v50 = v44 * 0.25;
          v51 = v45 * 0.25;
          v52 = (v39 + v41[2]) * 0.25;
          v53 = (v47 + v41[3]) * 0.25;
          *v34++ = v50;
          *v34++ = v51;
          *v34 = v52;
          v34[1] = v53;
        }
        while ( v30 < *(_DWORD *)(a1[1] + 4184) );
      }
      a3 = v61;
      a2 = 0;
      (*(void (__thiscall **)(_DWORD, unsigned int))(*(_DWORD *)a1[1] + 8))(a1[1], i);
    }
    sub_5BE8AE();
    v28 = 0;
  }
  else
  {
    v28 = -2147024882;
  }
  sub_5BE8AE();
  return v28;
}
