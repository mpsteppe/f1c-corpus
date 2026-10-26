// positive sp value has been detected, the output may be wrong!
int __userpurge sub_62FB16@<eax>(
        unsigned int *a1@<eax>,
        _DWORD *a2@<ecx>,
        unsigned int a3,
        unsigned int a4,
        int a5,
        int a6,
        _DWORD *a7,
        int a8,
        unsigned int *a9,
        unsigned int *a10)
{
  unsigned int v10; // ebp
  _DWORD *v13; // eax
  unsigned int v14; // edx
  unsigned int v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // esi
  int v19; // edx
  int v20; // edx
  int *v21; // edi
  int v22; // edx
  int v23; // ecx
  unsigned int v24; // esi
  int v25; // edi
  int *v26; // esi
  unsigned int v27; // edi
  int v28; // ecx
  int v29; // esi
  signed int v30; // ecx
  unsigned int v31; // edi
  int v32; // ebx
  unsigned int v33; // esi
  unsigned int j; // ecx
  unsigned int v35; // edx
  unsigned int v36; // ecx
  unsigned int v37; // eax
  int *v38; // ebp
  unsigned int v39; // eax
  unsigned int v40; // edi
  unsigned int v41; // eax
  unsigned int v42; // edx
  int v43; // ebp
  unsigned int v44; // eax
  int v45; // ecx
  int v46; // esi
  int v47; // edx
  unsigned int v48; // eax
  _DWORD *v49; // ecx
  unsigned int i; // eax
  int v51; // eax
  int v52; // ecx
  unsigned int v53; // [esp-ECh] [ebp-FCh]
  signed int v54; // [esp-E8h] [ebp-F8h]
  int v55; // [esp-E4h] [ebp-F4h]
  int v56; // [esp-E0h] [ebp-F0h]
  int *v57; // [esp-DCh] [ebp-ECh]
  unsigned int *v58; // [esp-DCh] [ebp-ECh]
  int *v59; // [esp-D8h] [ebp-E8h]
  signed int v60; // [esp-D4h] [ebp-E4h]
  unsigned int v61; // [esp-D0h] [ebp-E0h]
  unsigned int v62; // [esp-CCh] [ebp-DCh]
  int v63; // [esp-CCh] [ebp-DCh]
  int v64; // [esp-C8h] [ebp-D8h]
  unsigned int v65; // [esp-C4h] [ebp-D4h]
  signed int v66; // [esp-C0h] [ebp-D0h]
  char v67; // [esp-BCh] [ebp-CCh]
  unsigned int v68; // [esp-B8h] [ebp-C8h]
  _DWORD *v69; // [esp-B4h] [ebp-C4h]
  int v70; // [esp-B0h] [ebp-C0h]
  int v71; // [esp-ACh] [ebp-BCh] BYREF
  int v72; // [esp-A8h] [ebp-B8h]
  int v73; // [esp-A4h] [ebp-B4h]
  int v74; // [esp-A0h] [ebp-B0h]
  _DWORD v75[11]; // [esp-9Ch] [ebp-ACh] BYREF
  int v76; // [esp-70h] [ebp-80h]
  int v77; // [esp-6Ch] [ebp-7Ch]
  _DWORD v78[15]; // [esp-68h] [ebp-78h]
  _DWORD v79[15]; // [esp-2Ch] [ebp-3Ch] BYREF
  int v80; // [esp+14h] [ebp+4h]

  v10 = 0;
  v71 = 0;
  v72 = 0;
  v73 = 0;
  v74 = 0;
  memset(v75, 0, sizeof(v75));
  v76 = 0;
  v13 = a2;
  v14 = a3;
  do
  {
    ++*(&v71 + *v13++);
    --v14;
  }
  while ( v14 );
  if ( v71 == a3 )
  {
    *a7 = 0;
    *a1 = 0;
    return 0;
  }
  v16 = *a1;
  v53 = *a1;
  v17 = 1;
  while ( !*(&v71 + v17) )
  {
    if ( *(&v72 + v17) )
    {
      ++v17;
      break;
    }
    if ( *(&v73 + v17) )
    {
      v17 += 2;
      break;
    }
    if ( v75[v17 - 1] )
    {
      v17 += 3;
      break;
    }
    if ( v75[v17] )
    {
      v17 += 4;
      break;
    }
    v17 += 5;
    if ( v17 > 0xF )
      break;
  }
  v54 = v17;
  if ( v16 < v17 )
  {
    v53 = v17;
    v16 = v17;
  }
  v18 = 15;
  do
  {
    if ( *(&v71 + v18) )
      break;
    --v18;
  }
  while ( v18 );
  v60 = v18;
  if ( v16 > v18 )
  {
    v53 = v18;
    v16 = v18;
  }
  v19 = 1 << v17;
  for ( *a1 = v16; v17 < v18; v19 = 2 * v20 )
  {
    v20 = v19 - *(&v71 + v17);
    if ( v20 < 0 )
      return -3;
    ++v17;
  }
  v21 = &v71 + v18;
  v62 = v18;
  v22 = v19 - *v21;
  v70 = v22;
  if ( v22 < 0 )
    return -3;
  *v21 += v22;
  v23 = 0;
  v24 = v18 - 1;
  v78[0] = 0;
  if ( v24 )
  {
    v25 = 0;
    do
    {
      v23 += *(int *)((char *)&v72 + v25 * 4);
      ++v25;
      --v24;
      v78[v25] = v23;
    }
    while ( v24 );
  }
  v26 = a2;
  v27 = 0;
  do
  {
    v28 = *v26++;
    v57 = v26;
    if ( v28 )
    {
      v29 = v78[v28 - 1];
      a10[v29] = v27;
      v78[v28 - 1] = v29 + 1;
      v26 = v57;
    }
    ++v27;
  }
  while ( v27 < a3 );
  v80 = v78[v62 - 1];
  v58 = a10;
  v30 = v54;
  v31 = 0;
  v32 = -v16;
  v61 = 0;
  v77 = 0;
  v55 = -1;
  v79[0] = 0;
  v63 = 0;
  if ( v54 > v60 )
  {
LABEL_75:
    if ( !v22 || v60 == 1 )
      return 0;
    return -5;
  }
  else
  {
    v33 = v65;
    v67 = v54 - 1;
    v59 = &v71 + v54;
    while ( 1 )
    {
      v56 = *v59;
      if ( *v59 )
        break;
LABEL_73:
      ++v59;
      ++v30;
      ++v67;
      v54 = v30;
      if ( v30 > v60 )
      {
        v22 = v70;
        goto LABEL_75;
      }
    }
    while ( 1 )
    {
      --v56;
      if ( v54 > (int)(v32 + v16) )
        break;
LABEL_56:
      if ( v58 < &a10[v80] )
      {
        v33 = *v58;
        if ( *v58 >= a4 )
        {
          v46 = 4 * (v33 - a4);
          LOBYTE(v64) = *(_BYTE *)(v46 + a6) + 80;
          v33 = *(_DWORD *)(v46 + a5);
        }
        else
        {
          LOBYTE(v64) = v33 < 0x100 ? 0 : 0x60;
        }
        ++v58;
      }
      else
      {
        LOBYTE(v64) = -64;
      }
      v47 = 1 << (v54 - v32);
      v48 = v10 >> v32;
      if ( v10 >> v32 < v31 )
      {
        v49 = (_DWORD *)(v63 + 8 * v48);
        do
        {
          BYTE1(v64) = v54 - v32;
          *v49 = v64;
          v49[1] = v33;
          v48 += v47;
          v49 += 2 * v47;
        }
        while ( v48 < v31 );
        v10 = v61;
      }
      for ( i = 1 << v67; (i & v10) != 0; i >>= 1 )
        v10 ^= i;
      v10 ^= i;
      v51 = v55;
      v61 = v10;
      if ( (v10 & ((1 << v32) - 1)) != v78[v55 - 1] )
      {
        do
        {
          v32 -= v53;
          v52 = *(&v76 + v51--);
        }
        while ( (v10 & ((1 << v32) - 1)) != v52 );
        v55 = v51;
      }
      v16 = v53;
      if ( !v56 )
      {
        v30 = v54;
        goto LABEL_73;
      }
    }
    v66 = v32 + v16;
    for ( j = v32 - v16; ; j = v68 )
    {
      ++v55;
      v32 += v16;
      v35 = v60 - v32;
      v68 = v16 + j;
      v66 += v16;
      if ( v60 - v32 > v16 )
        v35 = v16;
      v36 = v54 - v32;
      v37 = 1 << (v54 - v32);
      if ( v37 > v56 + 1 )
      {
        v38 = v59;
        v39 = -1 - v56 + v37;
        if ( v36 < v35 && ++v36 < v35 )
        {
          do
          {
            v40 = v38[1];
            ++v38;
            v41 = 2 * v39;
            if ( v41 <= v40 )
              break;
            v39 = v41 - v40;
            ++v36;
          }
          while ( v36 < v35 );
        }
      }
      v31 = 1 << v36;
      v42 = *a9 + (1 << v36);
      if ( v42 > 0x5A0 )
        break;
      v43 = a8 + 8 * *a9;
      v69 = &v79[v55];
      *v69 = v43;
      *a9 = v42;
      v63 = v43;
      if ( v55 )
      {
        v78[v55 - 1] = v61;
        LOBYTE(v64) = v36;
        v44 = v61 >> v68;
        v45 = *(v69 - 1);
        BYTE1(v64) = v53;
        v33 = ((v43 - v45) >> 3) - (v61 >> v68);
        *(_DWORD *)(v45 + 8 * v44) = v64;
        *(_DWORD *)(v45 + 8 * v44 + 4) = v33;
      }
      else
      {
        *a7 = v43;
      }
      if ( v54 <= v66 )
      {
        v10 = v61;
        goto LABEL_56;
      }
      v16 = v53;
    }
    return -4;
  }
}
