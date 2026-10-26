int __thiscall sub_6A800A(_DWORD *this)
{
  unsigned int v2; // ebx
  int v3; // eax
  int v4; // ebx
  int v5; // edi
  int v6; // edx
  unsigned int v7; // edx
  int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  _DWORD *v11; // ebx
  int v12; // edi
  int v13; // edx
  int v14; // edi
  unsigned int v15; // ecx
  int v16; // edi
  unsigned int v17; // edx
  int v18; // eax
  bool v19; // zf
  unsigned int v20; // eax
  unsigned int *v21; // edx
  int v22; // ecx
  int v23; // eax
  int v24; // eax
  int v25; // edi
  int v26; // eax
  _DWORD *v27; // edi
  int v28; // eax
  double v29; // st7
  unsigned int v30; // ecx
  unsigned int j; // edx
  unsigned int v32; // edx
  unsigned int v33; // eax
  float *v34; // ecx
  double v35; // st7
  unsigned int v36; // edi
  int v37; // eax
  int v38; // eax
  int v39; // ecx
  unsigned int v40; // ecx
  int v41; // eax
  int v42; // eax
  unsigned int i; // ecx
  int v44; // eax
  double v46; // [esp+0h] [ebp-180h]
  float v47[32]; // [esp+14h] [ebp-16Ch] BYREF
  _DWORD v48[32]; // [esp+94h] [ebp-ECh] BYREF
  _DWORD v49[12]; // [esp+114h] [ebp-6Ch] BYREF
  _DWORD v50[3]; // [esp+144h] [ebp-3Ch] BYREF
  int v51; // [esp+150h] [ebp-30h]
  unsigned int v52; // [esp+154h] [ebp-2Ch]
  int v53; // [esp+158h] [ebp-28h]
  unsigned int v54; // [esp+15Ch] [ebp-24h]
  _DWORD *v55; // [esp+160h] [ebp-20h]
  unsigned int v56; // [esp+164h] [ebp-1Ch]
  unsigned int v57; // [esp+168h] [ebp-18h]
  int v58; // [esp+16Ch] [ebp-14h]
  unsigned int v59; // [esp+170h] [ebp-10h]
  unsigned int v60; // [esp+174h] [ebp-Ch]
  int v61; // [esp+178h] [ebp-8h]
  unsigned int k; // [esp+17Ch] [ebp-4h]

  v2 = this[2];
  memset(v47, 0, sizeof(v47));
  memset(v48, 0, sizeof(v48));
  memset(v49, 0, 0x20u);
  v57 = v2;
  v3 = sub_681A51(this, (int)"c", 785, 8, 4);
  v59 = 0;
  v53 = v3;
  if ( v2 )
  {
    v4 = this[4];
    v5 = this[5];
    do
    {
      v6 = *(_DWORD *)(*(_DWORD *)(v4 + 4 * *(_DWORD *)(*(_DWORD *)v5 + 4)) + 4);
      if ( (v6 & 0x200) != 0 && (v6 & 0x180) == 0 )
      {
        v7 = *(_DWORD *)(*(_DWORD *)v5 + 12);
        if ( v7 > this[14] )
        {
          sub_686791((int)this, 0, 4507, "exceeded maximum constant registers");
          return -2147467259;
        }
        v8 = 4 * v7;
        v48[v8] = 1;
        v48[v8 + 1] = 1;
        v48[v8 + 2] = 1;
        v48[v8 + 3] = 1;
        v49[v7] = 1;
      }
      ++v59;
      v5 += 4;
    }
    while ( v59 < v57 );
  }
  v9 = this[137];
  v10 = this[136];
  v60 = 0;
  if ( !(v10 + v9) )
  {
LABEL_82:
    for ( i = 0; i < v57; ++i )
    {
      v44 = *(_DWORD *)(this[5] + 4 * i);
      if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v44 + 4)) + 5) & 1) != 0 )
        *(_DWORD *)(v44 + 4) = this[29];
    }
    return 0;
  }
  while ( 1 )
  {
    v11 = v60 >= v10 ? *(_DWORD **)(this[140] + 4 * (v60 - v10)) : *(_DWORD **)(this[139] + 4 * v60);
    v58 = 0;
    v55 = v11;
    if ( v11 )
    {
      if ( v11[3] )
      {
        v12 = *(_DWORD *)v11[4];
        if ( v12 != -1 )
        {
          v54 = *v11;
          if ( (v54 & 0xFFF00000) != 0 )
          {
            if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v12) + 16) != 3 && v11[3] != 4 && v60 >= v10 )
            {
              v13 = 1;
              if ( v60 - v10 + 1 < v9 )
              {
                v14 = v60 - v10 + 1;
                v15 = v14;
                do
                {
                  v16 = *(_DWORD *)(this[140] + 4 * v14);
                  if ( v16 && (*(_WORD *)(v16 + 2) & 0xFFF0) != 0 )
                    break;
                  ++v13;
                  v14 = ++v15;
                }
                while ( v15 < this[137] );
                v11 = v55;
              }
              v17 = v60 + v13 - v10;
              if ( v17 < this[137] )
              {
                v18 = *(_DWORD *)(this[140] + 4 * v17);
                v19 = *(_DWORD *)(v18 + 12) == 1;
                v58 = v18;
                if ( !v19 || *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(v18 + 16)) + 16) != 3 )
                  v58 = 0;
              }
            }
            v56 = v54 & 0xFFFFF;
            v20 = v11[1] / (v54 & 0xFFFFF);
            v54 = 0;
            v52 = v20;
            if ( v20 )
              break;
          }
        }
      }
    }
LABEL_81:
    v9 = this[137];
    v10 = this[136];
    if ( ++v60 >= v10 + v9 )
      goto LABEL_82;
  }
  v59 = 0;
  while ( 1 )
  {
    memset(v50, 0, sizeof(v50));
    v51 = 0;
    v21 = (unsigned int *)(v11[2] + v59);
    v22 = this[5];
    v11 = v55;
    if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(v22 + 4 * *v21) + 4)) + 5) & 1) != 0
      && *v21 < v57 )
    {
      break;
    }
LABEL_80:
    ++v54;
    v59 += 4 * v56;
    if ( v54 >= v52 )
      goto LABEL_81;
  }
  v23 = 0;
  v61 = 0;
  if ( v56 )
  {
    k = *v55 & 0xFFF00000;
    do
    {
      if ( k != 1342177280 )
        v23 = *(_DWORD *)(*(_DWORD *)(v22 + 4 * *(_DWORD *)(v11[4] + 4 * v23)) + 16);
      v24 = v23;
      *(float *)&v49[v24 + 8] = *(double *)(*(_DWORD *)(v22 + 4 * *v21) + 32);
      v50[v24] = 1;
      v23 = v61 + 1;
      ++v21;
      ++v61;
    }
    while ( v61 < v56 );
  }
  v25 = v58;
  if ( v58 )
  {
    v26 = *(_DWORD *)(v58 + 4);
    if ( v26 )
    {
      v27 = *(_DWORD **)(v58 + 8);
      k = (unsigned int)v27;
      v61 = v26;
      do
      {
        v28 = *(_DWORD *)(v22 + 4 * *v27);
        if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v28 + 4)) + 5) & 1) != 0 && *(_DWORD *)k < v57 )
        {
          v29 = *(double *)(v28 + 32);
          v51 = 1;
          *(float *)&v49[11] = v29;
        }
        v27 = (_DWORD *)(k + 4);
        v19 = v61-- == 1;
        k += 4;
      }
      while ( !v19 );
      v25 = v58;
    }
  }
  v30 = 0;
  v61 = 0;
  for ( j = 0; j < 32; j += 4 )
  {
    if ( !v49[v61] )
    {
      k = 1;
      do
      {
        if ( v50[v30] && *(float *)&v49[v30 + 8] != v47[j + v30] && v48[j + v30] )
          k = 0;
        ++v30;
      }
      while ( v30 < 4 );
      v30 = 0;
      if ( k )
        break;
    }
    ++v61;
  }
  if ( v61 != 8 )
  {
    v32 = 0;
    k = 0;
    do
    {
      if ( v50[v32] )
      {
        v33 = v32 + 4 * v61;
        v34 = (float *)&v49[v32 + 8];
        v35 = *v34;
        v48[v33] = 1;
        v47[v33] = v35;
        if ( *v34 > 1.0 || *v34 < -1.0 )
          k = 1;
      }
      ++v32;
    }
    while ( v32 < 4 );
    if ( k )
      sub_686816(
        (int)this,
        v11[15],
        (const char *)0x1260,
        "literal values outside range -1 to 1 are clamped on all ps_1_x shading models");
    k = 0;
    if ( v56 )
    {
      v36 = v59;
      do
      {
        v37 = this[5];
        v46 = *(double *)(*(_DWORD *)(v37 + 4 * *(_DWORD *)(v36 + v11[2])) + 32);
        if ( (*v11 & 0xFFF00000) == 0x50000000 )
          v38 = sub_681AAA(this, v53, v61, k, v46);
        else
          v38 = sub_681AAA(this, v53, v61, *(_DWORD *)(*(_DWORD *)(v37 + 4 * *(_DWORD *)(v11[4] + 4 * k)) + 16), v46);
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v38) + 60) = 0;
        v39 = v11[2];
        ++k;
        *(_DWORD *)(v36 + v39) = v38;
        v36 += 4;
      }
      while ( k < v56 );
      v25 = v58;
    }
    if ( v25 )
    {
      for ( k = 0; k < *(_DWORD *)(v25 + 4); ++k )
      {
        v40 = *(_DWORD *)(*(_DWORD *)(v25 + 8) + 4 * k);
        v41 = *(_DWORD *)(this[5] + 4 * v40);
        if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v41 + 4)) + 5) & 1) != 0 && v40 < v57 )
        {
          v42 = sub_681AAA(this, v53, v61, 3, *(double *)(v41 + 32));
          v25 = v58;
          *(_DWORD *)(*(_DWORD *)(v58 + 8) + 4 * k) = v42;
        }
        else
        {
          v25 = v58;
        }
      }
    }
    goto LABEL_80;
  }
  sub_686791((int)this, 0, 4507, "program too complex: exceeded available constant registers.");
  return -2147467259;
}
