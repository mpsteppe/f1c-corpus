int __fastcall sub_53B660(
        int *a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        int a5,
        _DWORD *a6,
        unsigned int *a7,
        int a8,
        unsigned int *a9,
        unsigned int *a10)
{
  unsigned int v10; // ebx
  unsigned int v11; // ebp
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // esi
  int i; // edx
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  unsigned int v22; // esi
  int v23; // edi
  int *v24; // esi
  unsigned int v25; // edi
  int v26; // ecx
  int v27; // esi
  unsigned int v28; // edi
  signed int v29; // ecx
  int v30; // ebx
  unsigned int v31; // esi
  unsigned int k; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ecx
  unsigned int v35; // eax
  _DWORD *v36; // ebp
  unsigned int v37; // eax
  unsigned int v38; // edi
  unsigned int v39; // eax
  unsigned int v40; // edx
  int v41; // ebp
  unsigned int v42; // eax
  int v43; // ecx
  int v44; // esi
  int v45; // edx
  unsigned int v46; // eax
  _DWORD *v47; // ecx
  unsigned int j; // eax
  int v49; // eax
  unsigned int v50; // [esp+10h] [ebp-100h]
  signed int v51; // [esp+14h] [ebp-FCh]
  int v52; // [esp+18h] [ebp-F8h]
  int *v53; // [esp+1Ch] [ebp-F4h]
  unsigned int *v54; // [esp+1Ch] [ebp-F4h]
  int v55; // [esp+20h] [ebp-F0h]
  unsigned int v56; // [esp+24h] [ebp-ECh]
  signed int v57; // [esp+28h] [ebp-E8h]
  _DWORD *v58; // [esp+2Ch] [ebp-E4h]
  int *v59; // [esp+30h] [ebp-E0h]
  int v60; // [esp+30h] [ebp-E0h]
  unsigned int v61; // [esp+34h] [ebp-DCh]
  unsigned int v62; // [esp+34h] [ebp-DCh]
  int v63; // [esp+38h] [ebp-D8h]
  unsigned int v64; // [esp+3Ch] [ebp-D4h]
  unsigned int v65; // [esp+40h] [ebp-D0h]
  int v66; // [esp+40h] [ebp-D0h]
  signed int v67; // [esp+44h] [ebp-CCh]
  char v68; // [esp+48h] [ebp-C8h]
  _DWORD *v69; // [esp+4Ch] [ebp-C4h]
  int v70; // [esp+50h] [ebp-C0h]
  int v71; // [esp+54h] [ebp-BCh] BYREF
  _DWORD v72[15]; // [esp+58h] [ebp-B8h] BYREF
  int v73; // [esp+94h] [ebp-7Ch]
  _DWORD v74[15]; // [esp+98h] [ebp-78h]
  _DWORD v75[15]; // [esp+D4h] [ebp-3Ch] BYREF

  v10 = a2;
  v11 = 0;
  v65 = a2;
  v59 = a1;
  v71 = 0;
  memset(v72, 0, sizeof(v72));
  do
  {
    v12 = *a1++;
    --a2;
    ++v72[v12 - 1];
  }
  while ( a2 );
  if ( v71 == v10 )
  {
    *a6 = 0;
    *a7 = 0;
    return 0;
  }
  v14 = *a7;
  v15 = 1;
  v50 = *a7;
  do
  {
    if ( v72[v15 - 1] )
      break;
    ++v15;
  }
  while ( v15 <= 0xF );
  v51 = v15;
  if ( v14 < v15 )
  {
    v50 = v15;
    v14 = v15;
  }
  v16 = 15;
  do
  {
    if ( v72[v16 - 1] )
      break;
    --v16;
  }
  while ( v16 );
  v57 = v16;
  if ( v14 > v16 )
  {
    v50 = v16;
    v14 = v16;
  }
  *a7 = v14;
  for ( i = 1 << v15; v15 < v16; i = 2 * v18 )
  {
    v18 = i - v72[v15 - 1];
    if ( v18 < 0 )
      return -3;
    ++v15;
  }
  v61 = v16;
  v19 = v72[v16 - 1];
  v20 = i - v19;
  v70 = v20;
  if ( v20 < 0 )
    return -3;
  v74[0] = 0;
  v72[v16 - 1] = v20 + v19;
  v21 = 0;
  v22 = v16 - 1;
  if ( v22 )
  {
    v23 = 0;
    do
    {
      v21 += v72[v23++];
      --v22;
      v74[v23] = v21;
    }
    while ( v22 );
  }
  v24 = v59;
  v25 = 0;
  do
  {
    v26 = *v24++;
    v53 = v24;
    if ( v26 )
    {
      v27 = v74[v26 - 1];
      a10[v27] = v25;
      v10 = v65;
      v74[v26 - 1] = v27 + 1;
      v24 = v53;
    }
    ++v25;
  }
  while ( v25 < v10 );
  v28 = 0;
  v56 = 0;
  v66 = v74[v61 - 1];
  v54 = a10;
  v29 = v51;
  v30 = -v14;
  v73 = 0;
  v52 = -1;
  v75[0] = 0;
  v60 = 0;
  if ( v51 > v57 )
  {
LABEL_66:
    if ( !v20 || v57 == 1 )
      return 0;
    return -5;
  }
  else
  {
    v31 = v64;
    v68 = v51 - 1;
    v58 = &v72[v51 - 1];
    while ( 1 )
    {
      v55 = *v58;
      if ( *v58 )
        break;
LABEL_64:
      v51 = ++v29;
      ++v58;
      ++v68;
      if ( v29 > v57 )
      {
        v20 = v70;
        goto LABEL_66;
      }
    }
    while ( 1 )
    {
      --v55;
      if ( v51 > (int)(v30 + v14) )
        break;
LABEL_47:
      if ( v54 < &a10[v66] )
      {
        v31 = *v54;
        if ( *v54 >= a3 )
        {
          v44 = 4 * (v31 - a3);
          LOBYTE(v63) = *(_BYTE *)(v44 + a5) + 80;
          v31 = *(_DWORD *)(v44 + a4);
        }
        else
        {
          LOBYTE(v63) = v31 < 0x100 ? 0 : 96;
        }
        ++v54;
      }
      else
      {
        LOBYTE(v63) = -64;
      }
      v45 = 1 << (v51 - v30);
      v46 = v11 >> v30;
      if ( v11 >> v30 < v28 )
      {
        v47 = (_DWORD *)(v60 + 8 * v46);
        do
        {
          v47[1] = v31;
          BYTE1(v63) = v51 - v30;
          *v47 = v63;
          v46 += v45;
          v47 += 2 * v45;
        }
        while ( v46 < v28 );
        v11 = v56;
      }
      for ( j = 1 << v68; (j & v11) != 0; j >>= 1 )
        v11 ^= j;
      v11 ^= j;
      v49 = v52;
      v56 = v11;
      if ( (v11 & ((1 << v30) - 1)) != v74[v52 - 1] )
      {
        do
        {
          --v49;
          v30 -= v50;
        }
        while ( (v11 & ((1 << v30) - 1)) != v74[v49 - 1] );
        v52 = v49;
      }
      v14 = v50;
      if ( !v55 )
      {
        v29 = v51;
        goto LABEL_64;
      }
    }
    v67 = v30 + v14;
    for ( k = v30 - v14; ; k = v62 )
    {
      v30 += v14;
      ++v52;
      v33 = v57 - v30;
      v62 = v14 + k;
      v67 += v14;
      if ( v57 - v30 > v14 )
        v33 = v14;
      v34 = v51 - v30;
      v35 = 1 << (v51 - v30);
      if ( v35 > v55 + 1 )
      {
        v36 = v58;
        v37 = -1 - v55 + v35;
        if ( v34 < v33 && ++v34 < v33 )
        {
          do
          {
            v38 = v36[1];
            ++v36;
            v39 = 2 * v37;
            if ( v39 <= v38 )
              break;
            v37 = v39 - v38;
            ++v34;
          }
          while ( v34 < v33 );
        }
      }
      v28 = 1 << v34;
      v40 = *a9 + (1 << v34);
      if ( v40 > 0x5A0 )
        break;
      v41 = a8 + 8 * *a9;
      v60 = v41;
      v69 = &v75[v52];
      *v69 = v41;
      *a9 = v40;
      if ( v52 )
      {
        LOBYTE(v63) = v34;
        v74[v52 - 1] = v56;
        v42 = v56 >> v62;
        BYTE1(v63) = v50;
        v43 = *(v69 - 1);
        v31 = ((v41 - v43) >> 3) - (v56 >> v62);
        *(_DWORD *)(v43 + 8 * v42) = v63;
        *(_DWORD *)(v43 + 8 * v42 + 4) = v31;
      }
      else
      {
        *a6 = v41;
      }
      if ( v51 <= v67 )
      {
        v11 = v56;
        goto LABEL_47;
      }
      v14 = v50;
    }
    return -4;
  }
}
