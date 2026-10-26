int __usercall sub_52A0A1@<eax>(
        unsigned int *a1@<eax>,
        _DWORD *a2,
        unsigned int a3,
        unsigned int a4,
        int a5,
        int a6,
        _DWORD *a7,
        int a8,
        unsigned int *a9,
        unsigned int *a10)
{
  _DWORD *v10; // ecx
  unsigned int v12; // edx
  unsigned int v14; // ebx
  unsigned int v15; // ecx
  unsigned int v16; // eax
  int v17; // edx
  int v18; // edx
  unsigned int v19; // esi
  int *v20; // ecx
  int v21; // ebx
  int v22; // edx
  int v23; // ecx
  unsigned int v24; // eax
  int v25; // ebx
  int *v26; // ecx
  unsigned int v27; // ebx
  int v28; // eax
  int *v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // ebx
  unsigned int v33; // eax
  unsigned int j; // ecx
  unsigned int v35; // esi
  unsigned int v36; // ecx
  unsigned int v37; // eax
  unsigned int v38; // eax
  _DWORD *v39; // edx
  unsigned int v40; // edx
  unsigned int v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // esi
  _DWORD *v44; // edx
  unsigned int v45; // esi
  unsigned int v46; // eax
  int v47; // ecx
  int v48; // edx
  unsigned int v49; // eax
  int v50; // eax
  int v51; // esi
  unsigned int v52; // eax
  _DWORD *v53; // ecx
  unsigned int v54; // esi
  unsigned int i; // eax
  int v56; // ecx
  int v57; // eax
  _DWORD v59[15]; // [esp+Ch] [ebp-A4h] BYREF
  int v60; // [esp+48h] [ebp-68h] BYREF
  _DWORD v61[15]; // [esp+4Ch] [ebp-64h]
  int v62; // [esp+88h] [ebp-28h] BYREF
  _DWORD v63[15]; // [esp+8Ch] [ebp-24h] BYREF
  unsigned int v64; // [esp+C8h] [ebp+18h]
  signed int v65; // [esp+CCh] [ebp+1Ch]
  int v66; // [esp+D0h] [ebp+20h]
  int v67; // [esp+D4h] [ebp+24h]
  signed int v68; // [esp+D8h] [ebp+28h]
  int v69; // [esp+DCh] [ebp+2Ch]
  _DWORD *v70; // [esp+E0h] [ebp+30h]
  unsigned int v71; // [esp+E4h] [ebp+34h]
  int v72; // [esp+E8h] [ebp+38h]
  int v73; // [esp+ECh] [ebp+3Ch]
  unsigned int v74; // [esp+F0h] [ebp+40h]
  unsigned int v75; // [esp+F4h] [ebp+44h]
  int v76; // [esp+F8h] [ebp+48h]
  signed int v77; // [esp+FCh] [ebp+4Ch]
  unsigned int v78; // [esp+100h] [ebp+50h]
  int *v79; // [esp+10Ch] [ebp+5Ch]
  unsigned int *v80; // [esp+10Ch] [ebp+5Ch]
  int v81; // [esp+110h] [ebp+60h]

  v10 = a2;
  v62 = 0;
  memset(v63, 0, sizeof(v63));
  v12 = a3;
  do
  {
    ++v63[*v10++ - 1];
    --v12;
  }
  while ( v12 );
  if ( v62 != a3 )
  {
    v14 = *a1;
    v78 = *a1;
    v15 = 1;
    v16 = 15;
    do
    {
      if ( v63[v15 - 1] )
        break;
      ++v15;
    }
    while ( v15 <= 0xF );
    v77 = v15;
    if ( v14 < v15 )
      v78 = v15;
    do
    {
      if ( v63[v16 - 1] )
        break;
      --v16;
    }
    while ( v16 );
    v68 = v16;
    if ( v78 > v16 )
      v78 = v16;
    *a1 = v78;
    v17 = 1 << v15;
    while ( v15 < v16 )
    {
      v18 = v17 - v63[v15 - 1];
      if ( v18 < 0 )
        return -3;
      ++v15;
      v17 = 2 * v18;
    }
    v19 = v16;
    v20 = &v63[v16 - 1];
    v21 = *v20;
    v22 = v17 - *v20;
    v66 = v22;
    if ( v22 < 0 )
      return -3;
    *v20 = v22 + v21;
    v23 = 0;
    v24 = v16 - 1;
    v61[0] = 0;
    if ( v24 )
    {
      v25 = 0;
      do
      {
        v23 += v63[v25++];
        --v24;
        v61[v25] = v23;
      }
      while ( v24 );
    }
    v26 = a2;
    v27 = 0;
    do
    {
      v28 = *v26++;
      v79 = v26;
      if ( v28 )
      {
        v29 = &v61[v28 - 1];
        v30 = *v29;
        a10[v30] = v27;
        v22 = v66;
        *v29 = v30 + 1;
        v26 = v79;
      }
      ++v27;
    }
    while ( v27 < a3 );
    v31 = v61[v19 - 1];
    v76 = -1;
    v81 = v31;
    v80 = a10;
    v32 = -v78;
    v71 = 0;
    v60 = 0;
    v59[0] = 0;
    v69 = 0;
    v75 = 0;
    if ( v77 > v68 )
    {
LABEL_68:
      if ( !v22 || v68 == 1 )
        return 0;
      return -5;
    }
    else
    {
      v67 = v77 - 1;
      v70 = &v63[v77 - 1];
      while ( 1 )
      {
        v72 = *v70;
        if ( v72 )
          break;
LABEL_67:
        ++v77;
        ++v70;
        ++v67;
        if ( v77 > v68 )
          goto LABEL_68;
      }
      while ( 1 )
      {
        --v72;
        v33 = v32 + v78;
        if ( v77 > (int)(v32 + v78) )
          break;
LABEL_50:
        BYTE1(v73) = v77 - v32;
        if ( v80 < &a10[v81] )
        {
          v49 = *v80;
          if ( *v80 >= a4 )
          {
            v50 = 4 * (v49 - a4);
            LOBYTE(v73) = *(_BYTE *)(v50 + a6) + 80;
            v49 = *(_DWORD *)(v50 + a5);
          }
          else
          {
            LOBYTE(v73) = v49 < 0x100 ? 0 : 0x60;
          }
          ++v80;
          v74 = v49;
        }
        else
        {
          LOBYTE(v73) = -64;
        }
        v51 = 1 << (v77 - v32);
        v52 = v71 >> v32;
        if ( v71 >> v32 < v75 )
        {
          v53 = (_DWORD *)(v69 + 8 * v52);
          do
          {
            *v53 = v73;
            v53[1] = v74;
            v52 += v51;
            v53 += 2 * v51;
          }
          while ( v52 < v75 );
          v22 = v66;
        }
        v54 = v71;
        for ( i = 1 << v67; (i & v54) != 0; i >>= 1 )
          v54 ^= i;
        v71 = i ^ v54;
        v56 = (i ^ v54) & ((1 << v32) - 1);
        v57 = v76;
        if ( v56 != v61[v76 - 1] )
        {
          do
          {
            v32 -= v78;
            --v57;
          }
          while ( (v71 & ((1 << v32) - 1)) != v61[v57 - 1] );
          v76 = v57;
        }
        if ( !v72 )
          goto LABEL_67;
      }
      for ( j = v32 - v78; ; j = v64 )
      {
        ++v76;
        v32 += v78;
        v35 = v68 - v32;
        v64 = v78 + j;
        v65 = v78 + v33;
        if ( v68 - v32 > v78 )
          v35 = v78;
        v36 = v77 - v32;
        v37 = 1 << (v77 - v32);
        if ( v37 > v72 + 1 )
        {
          v38 = -1 - v72 + v37;
          v39 = v70;
          if ( v36 < v35 && ++v36 < v35 )
          {
            while ( 1 )
            {
              v75 = (unsigned int)(v39 + 1);
              v40 = v39[1];
              v41 = 2 * v38;
              if ( v41 <= v40 )
                break;
              v38 = v41 - v40;
              if ( ++v36 >= v35 )
                break;
              v39 = (_DWORD *)v75;
            }
          }
        }
        v42 = *a9;
        v43 = *a9 + (1 << v36);
        v75 = 1 << v36;
        if ( v43 > 0x5A0 )
          break;
        v44 = &v59[v76];
        v69 = a8 + 8 * v42;
        *v44 = v69;
        *a9 = v43;
        if ( v76 )
        {
          v45 = v71;
          v61[v76 - 1] = v71;
          BYTE1(v73) = v78;
          LOBYTE(v73) = v36;
          v46 = v45 >> v64;
          v47 = *(v44 - 1);
          v48 = ((v69 - v47) >> 3) - (v45 >> v64);
          *(_DWORD *)(v47 + 8 * v46) = v73;
          v74 = v48;
          *(_DWORD *)(v47 + 8 * v46 + 4) = v48;
        }
        else
        {
          *a7 = v69;
        }
        v33 = v65;
        if ( v77 <= v65 )
        {
          v22 = v66;
          goto LABEL_50;
        }
      }
      return -4;
    }
  }
  *a7 = 0;
  *a1 = 0;
  return 0;
}
