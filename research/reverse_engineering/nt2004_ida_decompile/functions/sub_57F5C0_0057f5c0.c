int __thiscall sub_57F5C0(_DWORD *this, _DWORD *a2, _DWORD *a3, int a4)
{
  _DWORD *v4; // esi
  int v5; // edi
  int i; // edx
  double *v7; // ecx
  int v8; // esi
  int v9; // ebx
  double **v10; // edi
  double *v11; // ecx
  int v12; // edx
  int v13; // edx
  unsigned int v14; // ebx
  double *v15; // ecx
  double *v16; // ecx
  int v17; // edx
  int v18; // esi
  int v19; // edi
  int v20; // ebx
  double *v21; // ecx
  int v22; // edx
  _DWORD *v23; // edx
  int v24; // ebx
  int j; // ecx
  _DWORD *v26; // eax
  int v27; // esi
  unsigned int v28; // edi
  int v29; // ebx
  int v30; // ecx
  int v31; // edx
  int v32; // ecx
  double *v33; // edx
  int v34; // ecx
  int v35; // edx
  double *v36; // edx
  int v37; // ecx
  int result; // eax
  int v39; // ebx
  int v40; // ecx
  int m; // edx
  int v42; // [esp+Ch] [ebp-1Ch]
  int k; // [esp+Ch] [ebp-1Ch]
  int v44; // [esp+10h] [ebp-18h]
  int v45; // [esp+10h] [ebp-18h]
  unsigned int v46; // [esp+14h] [ebp-14h]
  unsigned int v47; // [esp+14h] [ebp-14h]
  int v49; // [esp+1Ch] [ebp-Ch]
  double **v50; // [esp+1Ch] [ebp-Ch]
  int v51; // [esp+20h] [ebp-8h]
  int v52; // [esp+20h] [ebp-8h]
  _DWORD *v53; // [esp+20h] [ebp-8h]
  double *v54; // [esp+24h] [ebp-4h]

  sub_57FCA0();
  if ( a4 > 0 )
  {
    v4 = a2;
    v5 = a4;
    do
    {
      for ( i = 0; i < a4; ++i )
      {
        v7 = (double *)(*v4 + 8 * i);
        if ( *v7 != 0.0 )
        {
          *(_DWORD *)v7 = 0;
          *((_DWORD *)v7 + 1) = 1072693248;
        }
      }
      ++v4;
      --v5;
    }
    while ( v5 );
  }
  if ( a4 > 0 )
  {
    *a3 = 0;
    a3[1] = 1072693248;
    qmemcpy(a3 + 2, a3, 4 * ((unsigned int)(8 * a4 - 5) >> 2));
  }
  v44 = 0;
  v46 = 0;
  v42 = 0;
  if ( a4 >= 0 )
  {
    v8 = 0;
    do
    {
      v9 = v42 == a4 ? 0 : v42;
      v51 = v9;
      if ( v9 < a4 )
      {
        v49 = 8 * v9;
        v10 = (double **)&a2[v9];
        do
        {
          if ( v42 == a4 )
          {
            if ( v49 > 0 )
            {
              v11 = *v10;
              v12 = v9;
              do
              {
                if ( *v11 != 0.0 )
                  ++v46;
                ++v11;
                --v12;
              }
              while ( v12 );
            }
            ++v44;
          }
          else
          {
            v13 = 0;
            if ( v8 > 0 )
            {
              v14 = v46;
              do
              {
                v15 = *v10;
                if ( (*v10)[v13] != 0.0 && *(double *)(v8 * 8 + a2[v13]) != 0.0 )
                {
                  ++v14;
                  if ( v15[v8] == 0.0 )
                  {
                    LODWORD(v15[v8]) = 0;
                    HIDWORD(v15[v8]) = 0x40000000;
                  }
                }
                ++v13;
              }
              while ( v13 < v42 );
              v46 = v14;
            }
            v16 = &(*v10)[v8];
            if ( *v16 != 0.0 )
              ++v44;
            v17 = a2[v42];
            *(_DWORD *)(v49 + v17) = *(_DWORD *)v16;
            v9 = v51;
            *(_DWORD *)(v49 + v17 + 4) = *((_DWORD *)v16 + 1);
          }
          ++v9;
          ++v10;
          v51 = v9;
          v49 += 8;
        }
        while ( v9 < a4 );
      }
      ++v8;
      ++v42;
    }
    while ( v42 <= a4 );
  }
  v18 = a4 - 2;
  if ( a4 - 2 >= 0 )
  {
    v19 = v18 + 1;
    v20 = 8 * (v18 + 1);
    do
    {
      if ( v19 < a4 )
      {
        v21 = (double *)(v20 + a2[v18]);
        v22 = a4 - v19;
        do
        {
          if ( *v21 != 0.0 )
            ++v46;
          ++v21;
          --v22;
        }
        while ( v22 );
      }
      --v18;
      v20 -= 8;
      --v19;
    }
    while ( v18 >= 0 );
  }
  if ( a4 > 0 )
  {
    v23 = a2;
    v24 = a4;
    do
    {
      for ( j = 0; j < a4; ++j )
      {
        v26 = (_DWORD *)(*v23 + 8 * j);
        if ( !*v26 && v26[1] == 0x40000000 )
        {
          *v26 = 0;
          v26[1] = 0;
        }
      }
      ++v23;
      --v24;
    }
    while ( v24 );
  }
  *this = operator new(8 * a4 + 8);
  this[1] = operator new(8 * a4);
  this[2] = operator new(8 * v44);
  this[3] = operator new(v46);
  v27 = 0;
  v28 = 0;
  v45 = 0;
  v47 = 0;
  for ( k = 0; k <= a4; ++k )
  {
    *(_DWORD *)(v27 * 8 + *this) = 0;
    *(_DWORD *)(*this + v27 * 8 + 4) = this[2] + 8 * v45;
    v29 = k == a4 ? 0 : k;
    if ( v29 < a4 )
    {
      v52 = 8 * v29;
      v50 = (double **)&a2[v29];
      do
      {
        if ( k == a4 )
        {
          *(_DWORD *)(v27 * 8 + *this) = *(_DWORD *)(*this + v27 * 8) + 1;
          v30 = this[2] + 8 * v45;
          *(_BYTE *)v30 = v29;
          *(_BYTE *)(v30 + 1) = 0;
          ++v45;
          *(_DWORD *)(v30 + 4) = v28 + this[3];
          v31 = 0;
          if ( v52 > 0 )
          {
            do
            {
              if ( (*v50)[v31] != 0.0 )
              {
                ++*(_BYTE *)(v30 + 1);
                *(_BYTE *)(v28 + this[3]) = v31;
                ++v28;
              }
              ++v31;
            }
            while ( v31 < v29 );
            v47 = v28;
          }
        }
        else
        {
          v54 = *v50;
          if ( (*v50)[v27] == 0.0 )
          {
            v32 = 0;
            if ( v27 > 0 )
            {
              v33 = *v50;
              while ( *v33 == 0.0 || *(double *)(v27 * 8 + a2[v32]) == 0.0 )
              {
                ++v32;
                ++v33;
                if ( v32 >= k )
                  goto LABEL_67;
              }
              LODWORD(v54[v27]) = 0;
              HIDWORD(v54[v27]) = 0x40000000;
            }
          }
LABEL_67:
          if ( (*v50)[v27] != 0.0 )
          {
            *(_DWORD *)(v27 * 8 + *this) = *(_DWORD *)(*this + v27 * 8) + 1;
            v34 = this[2] + 8 * v45;
            *(_BYTE *)v34 = v29;
            *(_BYTE *)(v34 + 1) = 0;
            *(_DWORD *)(v34 + 4) = v28 + this[3];
            v35 = 0;
            ++v45;
            if ( v27 > 0 )
            {
              do
              {
                if ( (*v50)[v35] != 0.0 && *(double *)(v27 * 8 + a2[v35]) != 0.0 )
                {
                  ++*(_BYTE *)(v34 + 1);
                  *(_BYTE *)(v28 + this[3]) = v35;
                  ++v28;
                }
                ++v35;
              }
              while ( v35 < k );
              v47 = v28;
            }
          }
          v36 = *v50;
          v37 = a2[k];
          *(_DWORD *)(v52 + v37) = LODWORD((*v50)[v27]);
          v28 = v47;
          *(_DWORD *)(v52 + v37 + 4) = HIDWORD(v36[v27]);
        }
        ++v29;
        ++v50;
        v52 += 8;
      }
      while ( v29 < a4 );
    }
    ++v27;
  }
  result = a4;
  v39 = a4 - 1;
  if ( a4 - 1 >= 0 )
  {
    v53 = &a2[v39];
    do
    {
      v40 = this[1] + 8 * v39;
      result = a4;
      *(_BYTE *)v40 = v39;
      *(_BYTE *)(v40 + 1) = 0;
      *(_DWORD *)(v40 + 4) = v28 + this[3];
      for ( m = v39 + 1; m < a4; ++m )
      {
        if ( *(double *)(*v53 + 8 * m) != 0.0 )
        {
          ++*(_BYTE *)(v40 + 1);
          *(_BYTE *)(v28 + this[3]) = m;
          ++v28;
        }
        result = a4;
      }
      --v39;
      --v53;
    }
    while ( v39 >= 0 );
  }
  return result;
}
