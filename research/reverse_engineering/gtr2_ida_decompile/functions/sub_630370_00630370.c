int __fastcall sub_630370(int a1, int a2, int a3, int a4, _DWORD *a5, unsigned __int8 **a6)
{
  _BYTE *v6; // ebp
  unsigned int v7; // esi
  int *v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // eax
  int v11; // edx
  int v12; // ebx
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // eax
  int v16; // ecx
  int v17; // ecx
  int v18; // ebx
  unsigned int v19; // eax
  unsigned int i; // esi
  int v21; // edi
  unsigned __int8 *v22; // edi
  int v23; // ecx
  int v24; // edx
  unsigned int v25; // esi
  unsigned int v26; // eax
  int v27; // edx
  int v28; // ecx
  unsigned int j; // edx
  int v30; // ebx
  unsigned int v31; // ebx
  unsigned int v32; // edx
  int v33; // ecx
  _BYTE *v34; // ecx
  char v35; // bl
  _BYTE *v36; // ebp
  _BYTE *v37; // ecx
  unsigned int v38; // edi
  unsigned int v39; // ecx
  int v40; // esi
  int v41; // eax
  unsigned int v43; // edx
  int v44; // esi
  unsigned __int8 *v45; // eax
  unsigned int v46; // ecx
  unsigned int v47; // edx
  int v48; // esi
  int v49; // eax
  int v50; // esi
  int v51; // eax
  unsigned int v52; // [esp+10h] [ebp-18h]
  unsigned __int8 *v53; // [esp+14h] [ebp-14h]
  unsigned int v54; // [esp+18h] [ebp-10h]
  int v56; // [esp+1Ch] [ebp-Ch]
  int v57; // [esp+20h] [ebp-8h]
  unsigned int v58; // [esp+24h] [ebp-4h]

  v6 = (_BYTE *)a5[13];
  v7 = a5[8];
  v8 = (int *)a6;
  v52 = (unsigned int)a6[1];
  v9 = a5[12];
  v53 = *a6;
  v10 = a5[7];
  if ( (unsigned int)v6 >= v9 )
    v54 = a5[11] - (_DWORD)v6;
  else
    v54 = v9 - (_DWORD)v6 - 1;
  v56 = dword_9127F0[a1];
  v57 = dword_9127F0[a2];
  while ( 1 )
  {
    for ( ; v10 < 0x14; ++v53 )
    {
      --v52;
      v11 = *v53 << v10;
      v10 += 8;
      v7 |= v11;
    }
    v12 = *(unsigned __int8 *)(a3 + 8 * (v7 & v56));
    v13 = a3 + 8 * (v7 & v56);
    v14 = *(unsigned __int8 *)(v13 + 1);
    v7 >>= v14;
    if ( !v12 )
    {
      v10 -= v14;
      *v6 = *(_BYTE *)(v13 + 4);
LABEL_29:
      ++v6;
      --v54;
      goto LABEL_30;
    }
    v15 = v10 - *(unsigned __int8 *)(v13 + 1);
    if ( (v12 & 0x10) == 0 )
      break;
LABEL_13:
    v18 = v12 & 0xF;
    v58 = *(_DWORD *)(v13 + 4) + (v7 & dword_9127F0[v18]);
    v19 = v15 - v18;
    for ( i = v7 >> v18; v19 < 0xF; ++v53 )
    {
      --v52;
      v21 = *v53 << v19;
      v19 += 8;
      i |= v21;
    }
    v22 = (unsigned __int8 *)(a4 + 8 * (i & v57));
    v23 = v22[1];
    v24 = *v22;
    v25 = i >> v23;
    v26 = v19 - v23;
    if ( (v24 & 0x10) == 0 )
    {
      while ( (v24 & 0x40) == 0 )
      {
        v27 = *((_DWORD *)v22 + 1) + (v25 & dword_9127F0[v24]);
        v28 = v22[8 * v27 + 1];
        v22 += 8 * v27;
        v24 = *v22;
        v25 >>= v28;
        v26 -= v28;
        if ( (v24 & 0x10) != 0 )
          goto LABEL_18;
      }
      v43 = (unsigned int)&a6[1][-v52];
      a6[6] = "invalid distance code";
      if ( v26 >> 3 < v43 )
        v43 = v26 >> 3;
      a5[8] = v25;
      a5[7] = v26 - 8 * v43;
      v44 = (int)*a6;
      v45 = a6[2];
      a6[1] = (unsigned __int8 *)(v52 + v43);
      *a6 = &v53[-v43];
      a6[2] = &v53[-v43 - v44 + (_DWORD)v45];
      a5[13] = v6;
      return -3;
    }
LABEL_18:
    for ( j = v24 & 0xF; v26 < j; ++v53 )
    {
      --v52;
      v30 = *v53 << v26;
      v26 += 8;
      v25 |= v30;
    }
    v31 = *((_DWORD *)v22 + 1) + (v25 & dword_9127F0[j]);
    v7 = v25 >> j;
    v10 = v26 - j;
    v32 = v58;
    v54 -= v58;
    v33 = a5[10];
    if ( (unsigned int)&v6[-v33] < v31 )
    {
      v38 = v31 + v33 - (_DWORD)v6;
      v37 = (_BYTE *)(a5[11] - v38);
      if ( v58 > v38 )
      {
        v32 = v58 - v38;
        do
        {
          *v6++ = *v37++;
          --v38;
        }
        while ( v38 );
        v37 = (_BYTE *)a5[10];
      }
    }
    else
    {
      v34 = &v6[-v31];
      *v6 = v6[-v31];
      v35 = v6[-v31 + 1];
      v36 = v6 + 1;
      *v36 = v35;
      v6 = v36 + 1;
      v37 = v34 + 2;
      v32 = v58 - 2;
    }
    do
    {
      *v6++ = *v37++;
      --v32;
    }
    while ( v32 );
    v8 = (int *)a6;
LABEL_30:
    if ( v54 < 0x102 || v52 < 0xA )
    {
      v39 = v8[1] - v52;
      if ( v10 >> 3 < v39 )
        v39 = v10 >> 3;
      a5[8] = v7;
      a5[7] = v10 - 8 * v39;
      v40 = *v8;
      v41 = v8[2];
      v8[1] = v52 + v39;
      v8[2] = (int)&v53[-v39 - v40 + v41];
      *v8 = (int)&v53[-v39];
      a5[13] = v6;
      return 0;
    }
  }
  while ( (v12 & 0x40) == 0 )
  {
    v16 = *(_DWORD *)(v13 + 4) + (v7 & dword_9127F0[v12]);
    v12 = *(unsigned __int8 *)(v13 + 8 * v16);
    v13 += 8 * v16;
    v17 = *(unsigned __int8 *)(v13 + 1);
    v7 >>= v17;
    if ( !v12 )
    {
      v10 = v15 - v17;
      *v6 = *(_BYTE *)(v13 + 4);
      goto LABEL_29;
    }
    v15 -= *(unsigned __int8 *)(v13 + 1);
    if ( (v12 & 0x10) != 0 )
      goto LABEL_13;
  }
  v46 = v8[1] - v52;
  v47 = v15 >> 3;
  if ( (v12 & 0x20) != 0 )
  {
    if ( v47 < v46 )
      v46 = v15 >> 3;
    a5[8] = v7;
    a5[7] = v15 - 8 * v46;
    v48 = *v8;
    v49 = v8[2];
    v8[1] = v52 + v46;
    v8[2] = (int)&v53[-v46 - v48 + v49];
    *v8 = (int)&v53[-v46];
    a5[13] = v6;
    return 1;
  }
  else
  {
    v8[6] = (int)"invalid literal/length code";
    if ( v47 < v46 )
      v46 = v15 >> 3;
    a5[8] = v7;
    a5[7] = v15 - 8 * v46;
    v50 = *v8;
    v51 = v8[2];
    v8[1] = v52 + v46;
    v8[2] = (int)&v53[-v46 - v50 + v51];
    *v8 = (int)&v53[-v46];
    a5[13] = v6;
    return -3;
  }
}
