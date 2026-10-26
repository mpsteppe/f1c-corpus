int __thiscall sub_6A4CFF(_DWORD *this)
{
  int *v2; // eax
  int v3; // ecx
  int v4; // esi
  _DWORD *v5; // eax
  unsigned int v6; // esi
  _DWORD *v7; // edi
  unsigned int v8; // ecx
  int v9; // edx
  int v10; // edi
  int v11; // ecx
  double v12; // st7
  int v13; // ecx
  _DWORD *v14; // eax
  unsigned int v15; // edi
  int v16; // edx
  _DWORD *v17; // ecx
  int v18; // ecx
  double v19; // st7
  int v21; // edx
  unsigned int v22; // edx
  int v23; // eax
  long double v24; // st7
  int v25; // eax
  _DWORD *v26; // ecx
  _DWORD *v27; // edi
  unsigned int v28; // edx
  unsigned int *v29; // edi
  unsigned int v30; // eax
  int v31; // edx
  int v32; // esi
  int *v33; // edi
  bool v34; // zf
  _DWORD *v35; // eax
  int v36; // esi
  void *v37; // eax
  unsigned int v38; // eax
  unsigned int v39; // eax
  _DWORD *v40; // ecx
  int v41; // esi
  int v42; // ecx
  int v43; // eax
  int v44; // esi
  bool v45; // c0
  int v46; // edx
  unsigned int v47; // edx
  _BYTE v48[64]; // [esp+Ch] [ebp-90h] BYREF
  _DWORD v49[8]; // [esp+4Ch] [ebp-50h] BYREF
  _DWORD *v50; // [esp+6Ch] [ebp-30h]
  unsigned int v51; // [esp+70h] [ebp-2Ch]
  int v52; // [esp+74h] [ebp-28h]
  float v53; // [esp+78h] [ebp-24h]
  unsigned int v54; // [esp+7Ch] [ebp-20h]
  unsigned int v55; // [esp+80h] [ebp-1Ch]
  _DWORD *v56; // [esp+84h] [ebp-18h]
  unsigned int v57; // [esp+88h] [ebp-14h]
  int v58; // [esp+8Ch] [ebp-10h]
  unsigned int v59; // [esp+90h] [ebp-Ch]
  unsigned int v60; // [esp+94h] [ebp-8h]
  unsigned int v61; // [esp+98h] [ebp-4h]

  v55 = 0;
  v58 = 0;
  v2 = (int *)this[64];
  v3 = this[5];
  v4 = *v2;
  v5 = (_DWORD *)v2[2];
  v6 = v4 & 0xFFFFF;
  v7 = *(_DWORD **)(v3 + 4 * *v5);
  v60 = (unsigned int)&v5[v6];
  v8 = *(_DWORD *)(v3 + 4 * *(_DWORD *)v60);
  v9 = v7[1];
  v56 = v7;
  v10 = this[4];
  v57 = v8;
  v59 = *(_DWORD *)(v10 + 4 * v9);
  v11 = this[34];
  if ( v9 == v11
    && (*(_BYTE *)(*(_DWORD *)(v10 + 4 * *(_DWORD *)(v57 + 4)) + 5) & 1) != 0
    && (*(_DWORD *)this[64] & 0xFFF00000) == 0x20500000 )
  {
    v57 = (unsigned int)v5;
    v5 = (_DWORD *)v60;
  }
  else
  {
    v16 = *(_DWORD *)(v57 + 4);
    if ( v16 != v11 || (*(_BYTE *)(v59 + 5) & 1) == 0 || (*(_DWORD *)this[64] & 0xFFF00000) != 0x20500000 )
    {
      if ( v56[1] != v11 || v16 != v11 || (*(_DWORD *)this[64] & 0xFFF00000) != 0x20400000 )
        return 1;
      v58 = 1;
      if ( v6 )
      {
        v17 = v5;
        v59 = v6;
        do
        {
          if ( *v17 != *(_DWORD *)((char *)v17 + v60 - (_DWORD)v5) )
            v58 = 0;
          ++v17;
          --v59;
        }
        while ( v59 );
      }
      v18 = v56[15];
      if ( v18 != *(_DWORD *)(v57 + 60) )
        return 1;
      if ( v18 == 0x80000 )
      {
        v19 = -1.0;
      }
      else
      {
        if ( (v18 & 0x80000) != 0 )
          return 1;
        v19 = 1.0;
      }
      v57 = (unsigned int)v5;
      if ( !v58 )
        return 1;
      v5 = (_DWORD *)v52;
      v12 = v19 + v19;
      goto LABEL_6;
    }
    v57 = v60;
  }
  v12 = *(double *)(*(_DWORD *)(this[5] + 4 * *v5) + 32);
LABEL_6:
  v61 = 0;
  v53 = v12;
  if ( v6 )
  {
    v13 = this[5];
    v60 = (unsigned int)v5;
    v56 = (_DWORD *)(v57 - (_DWORD)v5);
    do
    {
      v14 = *(_DWORD **)(v13 + 4 * *(_DWORD *)((char *)v56 + v60));
      v15 = 0;
      v59 = v58 ? 0 : *(_DWORD *)(v13 + 4 * *(_DWORD *)v60);
      v21 = this[63];
      if ( v14[22] != v21 || v14[21] != v21 || (v14[15] & 0x1FFE00) != 0 )
        return 1;
      if ( v55 )
      {
        do
        {
          if ( v14[18] == v49[v15 + 4] )
            break;
          ++v15;
        }
        while ( v15 < v55 );
      }
      if ( v15 == v55 )
      {
        v22 = v55;
        v23 = v14[18];
        ++v55;
        v49[v22 + 4] = v23;
      }
      if ( !v58 && v53 != *(double *)(v59 + 32) )
        return 1;
      ++v61;
      v60 += 4;
    }
    while ( v61 < v6 );
  }
  v24 = fabs(v53);
  if ( 2.0 != fabs(v24) || (v25 = 1024, (this[27] & 0x400) == 0) )
  {
    if ( v24 != 4.0 || (v25 = 2048, (this[27] & 0x800) == 0) )
    {
      if ( v24 != 8.0 || (v25 = 4096, (this[27] & 0x1000) == 0) )
      {
        if ( v24 != 0.5 || (v25 = 0x2000, (this[27] & 0x2000) == 0) )
        {
          if ( v24 != 0.25 || (v25 = 0x4000, (this[27] & 0x4000) == 0) )
          {
            if ( v24 != 0.125 )
              return 1;
            v25 = 0x8000;
            if ( (this[27] & 0x8000) == 0 )
              return 1;
          }
        }
      }
    }
  }
  v58 = v25;
  if ( v53 < 0.0 )
    BYTE2(v58) |= 8u;
  memset(v49, 0, 16);
  v60 = 0;
  if ( v55 )
  {
    v56 = v48;
    v59 = 0;
    do
    {
      v26 = *(_DWORD **)(this[6] + 4 * v49[v60 + 4]);
      if ( (*v26 & 0xF0000000) == 0x60000000 || (*v26 & 0xFF000000) == 0x72000000 )
        return 1;
      v27 = v56;
      v54 = 0;
      v61 = 0;
      v28 = v26[3];
      *v56 = -1;
      *++v27 = -1;
      *++v27 = -1;
      for ( v27[1] = -1; v61 < v6; ++v61 )
      {
        v51 = 0;
        if ( v28 )
        {
          v52 = *(_DWORD *)(v57 + 4 * v61);
          v50 = (_DWORD *)v26[4];
          v29 = (unsigned int *)&v48[v59];
          do
          {
            if ( *v50 == v52 )
            {
              v30 = v61;
              ++v49[v60];
              v31 = *(_DWORD *)(this[64] + 16);
              *v29 = v30;
              if ( (*(_BYTE *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v31 + 4 * v30)) + 61) & 2) != 0 && v53 < 0.0 )
                return 1;
              ++v54;
            }
            ++v51;
            v28 = v26[3];
            ++v50;
            ++v29;
          }
          while ( v51 < v28 );
        }
      }
      if ( v54 != v28 )
        return 1;
      ++v60;
      v56 += 4;
      v59 += 16;
    }
    while ( v60 < v55 );
  }
  v60 = 0;
  if ( !v55 )
  {
LABEL_98:
    *(_DWORD *)this[64] = 0;
    return 0;
  }
  v56 = v48;
  while ( 1 )
  {
    v32 = v49[v60];
    v33 = *(int **)(4 * v49[v60 + 4] + this[6]);
    v34 = v32 == v33[3];
    v52 = 4 * v49[v60 + 4];
    v59 = (unsigned int)v33;
    v54 = v32;
    if ( !v34 )
      break;
LABEL_82:
    v61 = 0;
    if ( v32 )
    {
      v59 = (unsigned int)v56;
      do
      {
        v39 = v61;
        if ( v61 < 4 )
        {
          v40 = (_DWORD *)v59;
          do
          {
            if ( *v40 != -1 )
              break;
            ++v39;
            ++v40;
          }
          while ( v39 < 4 );
        }
        v41 = v33[4];
        v57 = 0;
        v42 = 4 * v39;
        *(_DWORD *)(v41 + 4 * v61) = *(_DWORD *)(4 * v39 + *(_DWORD *)(this[64] + 16));
        v43 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(4 * v39 + *(_DWORD *)(this[64] + 16)));
        *(_DWORD *)(v43 + 60) |= v58;
        if ( this[2] )
        {
          do
          {
            v44 = *(_DWORD *)(this[5] + 4 * v57);
            if ( *(_DWORD *)(v44 + 56) == *(_DWORD *)(v42 + *(_DWORD *)(this[64] + 16)) )
            {
              v45 = v53 < 0.0;
              *(_DWORD *)(v44 + 60) |= v58 & 0xFFF7FFFF;
              v46 = *(_DWORD *)(v44 + 60);
              if ( v45 )
              {
                if ( (v46 & 0x80000) != 0 )
                  v47 = v46 & 0xFFF7FFFF;
                else
                  v47 = v46 | 0x80000;
                *(_DWORD *)(v44 + 60) = v47;
              }
            }
            ++v57;
          }
          while ( v57 < this[2] );
        }
        ++v61;
        v59 += 4;
      }
      while ( v61 < v54 );
    }
    ++v60;
    v56 += 4;
    if ( v60 >= v55 )
      goto LABEL_98;
  }
  v35 = (_DWORD *)sub_681186(116);
  if ( v35 )
    v61 = (unsigned int)sub_680CEC(v35);
  else
    v61 = 0;
  if ( !v61 )
    return -2147024882;
  v36 = sub_6811D1((char *)v61, *v33, v33[1], v32, 0);
  if ( v36 >= 0 )
  {
    v36 = sub_680D22((_DWORD *)v61, (int)v33);
    if ( v36 >= 0 )
    {
      v37 = (void *)v59;
      qmemcpy(*(void **)(v61 + 8), *(const void **)(v59 + 8), 4 * *(_DWORD *)(v59 + 4));
      sub_66238F(v37, 1);
      v38 = v61;
      v32 = v54;
      *(_DWORD *)(v52 + this[6]) = v61;
      v59 = v38;
      v33 = (int *)v38;
      goto LABEL_82;
    }
  }
  sub_66238F((void *)v61, 1);
  return v36;
}
