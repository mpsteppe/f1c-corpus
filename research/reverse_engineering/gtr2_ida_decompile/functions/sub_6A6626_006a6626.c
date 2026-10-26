int __thiscall sub_6A6626(_DWORD *this)
{
  int v2; // eax
  unsigned int v3; // ecx
  _DWORD *v4; // ebx
  int v5; // ecx
  unsigned int v6; // edi
  int v7; // edx
  int v8; // ecx
  unsigned int *v9; // eax
  unsigned int v10; // ecx
  unsigned int *v11; // eax
  unsigned int v12; // edx
  _DWORD *v13; // eax
  char *v14; // edi
  int v15; // ebx
  unsigned int j; // ebx
  unsigned int v17; // ebx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  _DWORD *v21; // edi
  int v22; // edx
  int v23; // ecx
  _DWORD *v24; // eax
  int v25; // eax
  int v27; // eax
  _DWORD *v28; // eax
  char *v29; // ebx
  int v30; // ecx
  int v31; // eax
  int v32; // eax
  int v33; // edx
  int v34; // ecx
  int v35; // eax
  int v36; // edx
  int v37; // ecx
  unsigned int i; // edi
  int v39; // eax
  int *v40; // edi
  int v41; // eax
  int v42; // ecx
  int v43; // edx
  int v44; // eax
  int v45; // ecx
  int v46; // eax
  int v47; // ecx
  _DWORD *v48; // eax
  int v49; // eax
  unsigned int v50; // ebx
  int v51; // eax
  int v52; // edx
  int v53; // [esp-4h] [ebp-48h]
  unsigned int v54; // [esp+4h] [ebp-40h]
  _DWORD v55[6]; // [esp+14h] [ebp-30h] BYREF
  unsigned int v56; // [esp+2Ch] [ebp-18h]
  unsigned int v57; // [esp+30h] [ebp-14h]
  int v58; // [esp+34h] [ebp-10h]
  unsigned int v59; // [esp+38h] [ebp-Ch]
  int v60; // [esp+3Ch] [ebp-8h]
  char *v61; // [esp+40h] [ebp-4h]

  memset(v55, 0, sizeof(v55));
  v57 = this[3];
  if ( v57 )
  {
    v59 = this[6];
    v60 = v57;
    do
    {
      v2 = *(_DWORD *)v59;
      if ( *(_DWORD *)v59 )
      {
        v61 = *(char **)v2;
        if ( v61 )
        {
          v3 = *(_DWORD *)(v2 + 4);
          v58 = 0;
          v56 = v3;
          if ( v3 )
          {
            v4 = *(_DWORD **)(v2 + 8);
            do
            {
              v5 = *(_DWORD *)(this[5] + 4 * *v4);
              if ( *(_DWORD *)(v5 + 4) == this[32] )
              {
                if ( *(unsigned __int8 *)(v5 + 109) > 5u )
                  break;
                if ( *(_BYTE *)(v5 + 108) == 3 )
                {
                  v6 = (unsigned int)v61 & 0xFFF00000;
                  if ( sub_6A2293((unsigned int)v61 & 0xFFF00000) || v6 == 285212672 )
                  {
                    v11 = &v55[v7];
                    v12 = *(_DWORD *)(v8 + 16) + 1;
                    if ( v12 > *v11 && *(_DWORD *)(v8 + 60) )
                      *v11 = v12;
                  }
                  else
                  {
                    v9 = &v55[v7];
                    v10 = *(_DWORD *)(v8 + 16) + 1;
                    if ( v10 > *v9 )
                      *v9 = v10;
                  }
                }
              }
              ++v58;
              ++v4;
            }
            while ( v58 < v56 );
          }
        }
      }
      v59 += 4;
      --v60;
    }
    while ( v60 );
  }
  v60 = 0;
  v61 = (char *)v55;
  while ( !*(_DWORD *)v61 )
  {
LABEL_34:
    ++v60;
    v61 += 4;
    if ( (unsigned int)v60 >= 6 )
    {
      v61 = 0;
      if ( !v57 )
      {
LABEL_59:
        for ( i = 0; i < v57; ++i )
        {
          v15 = sub_681C03(this, *(_DWORD **)(this[6] + 4 * i));
          if ( v15 < 0 )
            return v15;
          **(_DWORD **)(this[6] + 4 * i) = 0;
        }
        v39 = this[3];
        v57 = 0;
        v58 = v39;
        if ( !v39 )
          return sub_6825A9(this);
        while ( 1 )
        {
          v40 = *(int **)(this[6] + 4 * v57);
          v41 = *v40;
          if ( *v40 )
          {
            v59 = v41 & 0xFFFFF;
            if ( sub_6A2293(v41 & 0xFFF00000) || v42 == 285212672 )
            {
              v43 = this[4];
              v44 = v42 != 285212672 ? v59 : 0;
              v45 = v40[2];
              v56 = 4 * v44;
              v46 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(4 * v44 + v45));
              v47 = *(_DWORD *)(*(_DWORD *)(v43 + 4 * *(_DWORD *)(v46 + 4)) + 4);
              if ( (v47 & 0x200) != 0 || (v47 & 0x10) != 0 && *(_BYTE *)(v46 + 108) == 1 )
              {
                v48 = (_DWORD *)sub_681186(116);
                if ( v48 )
                  v61 = (char *)sub_680CEC(v48);
                else
                  v61 = 0;
                if ( !v61 )
                  return -2147024882;
                v15 = sub_6811D1(v61, v59 & 0xFFFFF | 0x10000000, v59, v59, 0);
                if ( v15 < 0 )
                  return v15;
                v15 = sub_680D22(v61, (int)v40);
                if ( v15 < 0 )
                  return v15;
                v60 = 0;
                if ( v59 )
                {
                  v49 = v40[2];
                  v50 = v56;
                  do
                  {
                    v53 = v60;
                    *(_DWORD *)(*((_DWORD *)v61 + 2) + 4 * v60) = *(_DWORD *)(v49 + v50);
                    v51 = sub_681AAA(this, this[34], 0, v53, 0.0);
                    v52 = v60;
                    *(_DWORD *)(*((_DWORD *)v61 + 4) + 4 * v60) = v51;
                    *(_DWORD *)(v50 + v40[2]) = *(_DWORD *)(*((_DWORD *)v61 + 4) + 4 * v52);
                    v49 = v40[2];
                    if ( *(_DWORD *)(v49 + v50) == -1 )
                      return -2147024882;
                    ++v60;
                    v50 += 4;
                  }
                  while ( v60 < v59 );
                }
                sub_681997((int)this, v61);
              }
            }
            sub_681C03(this, v40);
            *v40 = 0;
          }
          if ( ++v57 >= v58 )
            return sub_6825A9(this);
        }
      }
      while ( 1 )
      {
        v21 = *(_DWORD **)(this[6] + 4 * (_DWORD)v61);
        v54 = *v21 & 0xFFF00000;
        v59 = *v21 & 0xFFFFF;
        if ( sub_6A2293(v54) || v22 == 285212672 )
        {
          v24 = (_DWORD *)v21[2];
          v25 = v22 == 285212672 ? *v24 : v24[v23];
          v27 = *(_DWORD *)(this[5] + 4 * v25);
          if ( (*(_BYTE *)(v27 + 62) & 0x1F) != 0 && *(_DWORD *)(v27 + 4) == this[34] )
          {
            v28 = (_DWORD *)sub_681186(116);
            if ( v28 )
              v29 = (char *)sub_680CEC(v28);
            else
              v29 = 0;
            if ( !v29 )
              return -2147024882;
            v58 = sub_6811D1(v29, v59 & 0xFFFFF | 0x10000000, v59, v59, 0);
            if ( v58 < 0 )
              return v58;
            v30 = *v21 & 0xFFFFF;
            if ( (*v21 & 0xFFF00000) == 0x11000000 )
              v30 = 0;
            v60 = 0;
            if ( v59 )
            {
              v58 = 4 * v30;
              do
              {
                v31 = *(_DWORD *)(v58 + v21[2]);
                v56 = *(_DWORD *)(this[5] + 4 * v31);
                *(_DWORD *)(*((_DWORD *)v29 + 2) + 4 * v60) = v31;
                v32 = sub_681AAA(this, this[34], 0, *(_DWORD *)(v56 + 16), 0.0);
                v33 = v60;
                v34 = *((_DWORD *)v29 + 4);
                ++v60;
                *(_DWORD *)(v34 + 4 * v33) = v32;
                v35 = *(_DWORD *)(*((_DWORD *)v29 + 4) + 4 * v33);
                v36 = v58;
                v37 = v21[2];
                v58 += 4;
                *(_DWORD *)(v36 + v37) = v35;
              }
              while ( v60 < v59 );
            }
            v58 = sub_681997((int)this, v29);
            if ( v58 < 0 )
              return v58;
          }
        }
        if ( (unsigned int)++v61 >= v57 )
          goto LABEL_59;
      }
    }
  }
  v13 = (_DWORD *)sub_681186(116);
  if ( v13 )
    v14 = (char *)sub_680CEC(v13);
  else
    v14 = 0;
  if ( !v14 )
    return -2147024882;
  v15 = sub_6811D1(v14, *(_DWORD *)v61 & 0xFFFFF | 0x72100000, *(_DWORD *)v61, *(_DWORD *)v61, 0);
  if ( v15 < 0 )
    return v15;
  for ( j = 0; j < *(_DWORD *)v61; ++j )
  {
    *(_DWORD *)(*((_DWORD *)v14 + 4) + 4 * j) = sub_681AAA(this, this[34], 0, j, 0.0);
    if ( *(_DWORD *)(*((_DWORD *)v14 + 4) + 4 * j) == -1 )
    {
      sub_66238F(v14, 1);
      return -2147024882;
    }
  }
  v15 = sub_6A52C6(this, this[6], this[3], 3, v60, *(_DWORD *)v61, *((_DWORD *)v14 + 4));
  if ( v15 < 0 )
  {
    sub_66238F(v14, 1);
    return v15;
  }
  v17 = 0;
  if ( !*(_DWORD *)v61 )
  {
LABEL_33:
    v15 = sub_681997((int)this, v14);
    v58 = v15;
    if ( v15 < 0 )
      return v15;
    goto LABEL_34;
  }
  while ( 1 )
  {
    v18 = sub_681AAA(this, this[32], v60, v17, 0.0);
    if ( v18 == -1 )
      break;
    v19 = *(_DWORD *)(this[5] + 4 * v18);
    v20 = v60;
    *(_DWORD *)(v19 + 60) = 0;
    *(_DWORD *)(v19 + 108) = (v20 << 8) | 3;
    *(_DWORD *)(*((_DWORD *)v14 + 2) + 4 * v17++) = v18;
    if ( v17 >= *(_DWORD *)v61 )
      goto LABEL_33;
  }
  sub_66238F(v14, 1);
  return -2147024882;
}
