char __thiscall sub_551400(int this)
{
  bool v2; // cl
  double v3; // st7
  int m; // eax
  int v5; // eax
  char v6; // bl
  int i; // edi
  int v8; // eax
  int v9; // esi
  int v10; // ecx
  int v11; // eax
  int v12; // edx
  int v13; // eax
  double v14; // st7
  long double v15; // st7
  long double v16; // st6
  long double v17; // st5
  long double v18; // st4
  long double v19; // rt0
  float *v20; // eax
  unsigned __int8 v22; // c0
  unsigned __int8 v23; // c2
  _DWORD *v24; // ecx
  int v25; // esi
  int v26; // edi
  int v27; // eax
  int v28; // edi
  int j; // eax
  char v30; // dl
  int k; // eax
  char v32; // cl
  int v33; // edi
  _DWORD *v34; // edi
  int v36; // [esp-8h] [ebp-C4h]
  int v37; // [esp+0h] [ebp-BCh]
  int v38; // [esp+4h] [ebp-B8h]
  char v39; // [esp+1Bh] [ebp-A1h]
  char v40; // [esp+1Fh] [ebp-9Dh]
  float v41; // [esp+20h] [ebp-9Ch]
  float v42; // [esp+30h] [ebp-8Ch]
  float v43; // [esp+34h] [ebp-88h]
  float v44; // [esp+38h] [ebp-84h]
  float v45; // [esp+48h] [ebp-74h]
  float v46; // [esp+4Ch] [ebp-70h]
  float v47; // [esp+50h] [ebp-6Ch] BYREF
  _BYTE v48[104]; // [esp+54h] [ebp-68h] BYREF

  v40 = 0;
  v2 = *(_DWORD *)(this + 348) == 1;
  v3 = *(float *)(this + 360) - dbl_FB1D10;
  *(float *)(this + 360) = v3;
  if ( v3 <= 0.0 )
  {
    v40 = 1;
    *(_DWORD *)(this + 360) = 1048576000;
  }
  if ( v2 || (LOBYTE(m) = v40) != 0 )
  {
    v5 = dword_757C10;
    v6 = 0;
    for ( i = 0; i < dword_757C10; ++i )
    {
      v8 = sub_5761B0(*(&dword_91E088 + i) + 16);
      v9 = *(&dword_91E088 + i);
      v10 = v8;
      v11 = *(_DWORD *)(v9 + 19288);
      if ( v11 != 2 || *(_DWORD *)(v10 + 72) )
      {
        if ( v11 || *(_DWORD *)(v10 + 72) != 2 )
        {
          v12 = *(_DWORD *)(v10 + 276);
          v13 = *(_DWORD *)(v10 + 272);
          v14 = *(float *)(v12 + 4) - *(float *)(v13 + 4);
          v12 += 4;
          v13 += 4;
          v45 = v14;
          v46 = *(float *)(v12 + 4) - *(float *)(v13 + 4);
          v47 = *(float *)(v12 + 8) - *(float *)(v13 + 8);
          v15 = v45;
          v16 = v46;
          v17 = v47;
          v18 = v17 * v17 + v16 * v16 + v15 * v15;
          if ( v18 > 0.0 )
          {
            v19 = 1.0 / sqrt(v18);
            v15 = v15 * v19;
            v16 = v16 * v19;
            v17 = v17 * v19;
          }
          v42 = *(float *)(v9 + 15988) - *(float *)(v10 + 4);
          v43 = *(float *)(v9 + 15992) - *(float *)(v10 + 8);
          v44 = *(float *)(v9 + 15996) - *(float *)(v10 + 12);
          *(float *)(v9 + 19292) = v44 * v17 + v43 * v16 + v42 * v15 + *(float *)(v10 + 76);
        }
        else
        {
          *(_DWORD *)(v9 + 19292) = 0;
        }
      }
      else
      {
        *(float *)(v9 + 19292) = flt_91BDE4;
      }
      if ( *(_DWORD *)(v10 + 304) )
        goto LABEL_23;
      v20 = (float *)*(&dword_91E088 + i);
      v41 = *(float *)(this + 324) - sqrt(v20[4003] * v20[4003] + v20[4004] * v20[4004] + v20[4005] * v20[4005]) * 5.0;
      if ( v22 | v23 )
      {
        if ( *(float *)(v9 + 19292) >= (double)*(float *)(this + 324) && flt_91BDE4 + v41 >= *(float *)(v9 + 19292) )
          goto LABEL_23;
      }
      else if ( *(float *)(v9 + 19292) >= (double)*(float *)(this + 324) || *(float *)(v9 + 19292) <= (double)v41 )
      {
        goto LABEL_23;
      }
      v6 = 1;
LABEL_23:
      v5 = dword_757C10;
    }
    if ( v6 != *(_BYTE *)(this + 328) && v40 )
    {
      v24 = (_DWORD *)off_9034A4;
      if ( dword_82F4A0 < 1023 )
      {
        ++dword_82F4A0;
        off_9034A4 += 848;
      }
      *(float *)&v38 = dbl_FB1D18;
      if ( v6 )
        sub_51B2A0(v24, 4, 29, 0, 255, v38, 0);
      else
        sub_51B2A0(v24, 4, 30, 0, 255, v38, 0);
      v5 = dword_757C10;
    }
    if ( *(_DWORD *)dword_B72314 == 7 )
    {
      v25 = 0;
      v26 = 0;
      if ( v5 > 0 )
      {
        do
        {
          v27 = *(_DWORD *)(*(&dword_91E088 + v26) + 22468);
          v48[v25] = v27;
          if ( !(unsigned __int8)sub_523BD0(dword_BE1210, (unsigned __int8)v27) )
            ++v25;
          ++v26;
        }
        while ( v26 < dword_757C10 );
      }
    }
    else
    {
      if ( *(_DWORD *)dword_B72314 != 8 )
      {
        v25 = v5;
        for ( j = 0; j < v25; ++j )
          v48[j] = *(_BYTE *)(*(&dword_91E088 + j) + 22468);
        sub_632C60(v36, v48);
        goto LABEL_47;
      }
      v25 = 0;
      v28 = 0;
      if ( v5 > 0 )
      {
        do
        {
          v48[v25] = *(_DWORD *)(*(&dword_91E088 + v28) + 22468);
          if ( !(unsigned __int8)sub_524300() )
            ++v25;
          ++v28;
        }
        while ( v28 < dword_757C10 );
      }
    }
    sub_632C60(&v47, v25);
LABEL_47:
    v30 = 0;
    for ( k = 0; k < v25; ++k )
    {
      v32 = v48[k - 4];
      if ( *(_BYTE *)(k + this + 368) != v32 )
      {
        v30 = 1;
        *(_BYTE *)(k + this + 368) = v32;
      }
    }
    v33 = *(_DWORD *)(this + 364) + 1;
    *(_DWORD *)(this + 364) = v33;
    LOBYTE(m) = v33;
    if ( v39 && (v30 || (v33 & 0xF) == 0) )
    {
      LOBYTE(m) = dword_757C10;
      if ( dword_757C10 > 0 )
      {
        *(_DWORD *)(this + 364) = 0;
        v34 = (_DWORD *)off_9034A4;
        if ( dword_82F4A0 < 1023 )
        {
          ++dword_82F4A0;
          off_9034A4 += 848;
        }
        *(float *)&v37 = dbl_FB1D18;
        sub_51B2A0(v34, 4, 7, v25 + 12, 255, v37, 0);
        if ( v25 <= 0 )
        {
          v34[2] = -1082130432;
          v34[3] = -1082130432;
          v34[4] = -1082130432;
        }
        else
        {
          v34[2] = dword_925098[5654 * *(unsigned __int8 *)(this + 368)];
          v34[3] = dword_92509C[5654 * *(unsigned __int8 *)(this + 368)];
          v34[4] = dword_9250A0[5654 * *(unsigned __int8 *)(this + 368)];
        }
        for ( m = 0; m < v25; ++m )
          *((_BYTE *)v34 + m + 20) = *(_BYTE *)(m + this + 368);
      }
    }
  }
  return m;
}
