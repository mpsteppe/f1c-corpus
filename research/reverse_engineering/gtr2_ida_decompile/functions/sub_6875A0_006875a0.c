BOOL __thiscall sub_6875A0(_DWORD *this)
{
  unsigned int v1; // esi
  unsigned int i; // ecx
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // eax
  int v7; // ecx
  int *v8; // esi
  int v9; // ecx
  int v10; // eax
  unsigned int v11; // ebx
  int v12; // edx
  int v13; // ecx
  _DWORD *v14; // eax
  unsigned int v15; // ebx
  unsigned int j; // ebx
  _DWORD *v17; // edx
  unsigned int v18; // ecx
  int v19; // eax
  int v20; // ecx
  _DWORD *v21; // ecx
  _DWORD *ii; // esi
  int v23; // ecx
  int v24; // eax
  int *v25; // ecx
  int v26; // esi
  unsigned int v27; // eax
  unsigned int v28; // esi
  bool v29; // zf
  int v30; // eax
  int v31; // edx
  int v32; // edx
  int v33; // eax
  int v34; // edx
  int v35; // eax
  int v36; // ebx
  int v37; // eax
  unsigned int v38; // esi
  bool v39; // zf
  _DWORD *v40; // eax
  unsigned int kk; // esi
  int v42; // ecx
  _DWORD *v43; // eax
  unsigned int v44; // edx
  int v45; // edx
  int v46; // ecx
  int v47; // ecx
  int v49; // [esp+Ch] [ebp-20h]
  unsigned int k; // [esp+14h] [ebp-18h]
  int v51; // [esp+14h] [ebp-18h]
  int v52; // [esp+14h] [ebp-18h]
  int v53; // [esp+18h] [ebp-14h]
  int v54; // [esp+18h] [ebp-14h]
  int v55; // [esp+1Ch] [ebp-10h]
  int v56; // [esp+1Ch] [ebp-10h]
  unsigned int jj; // [esp+1Ch] [ebp-10h]
  int v58; // [esp+20h] [ebp-Ch]
  int v59; // [esp+20h] [ebp-Ch]
  unsigned int v60; // [esp+20h] [ebp-Ch]
  unsigned int v61; // [esp+20h] [ebp-Ch]
  unsigned int m; // [esp+24h] [ebp-8h]
  unsigned int v63; // [esp+24h] [ebp-8h]
  unsigned int v64; // [esp+24h] [ebp-8h]
  unsigned int v65; // [esp+28h] [ebp-4h]
  unsigned int v66; // [esp+28h] [ebp-4h]
  unsigned int n; // [esp+28h] [ebp-4h]
  unsigned int v68; // [esp+28h] [ebp-4h]
  unsigned int v69; // [esp+28h] [ebp-4h]

  v1 = 0;
  v53 = 0;
  sub_686074((int)this);
  for ( i = 0;
        i < this[2];
        *(_DWORD *)(v4 + 84) = (*(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v4 + 4)) + 4) & 0x10020) != 0 ? 2 : 0 )
  {
    v4 = *(_DWORD *)(this[5] + 4 * i++);
  }
  v5 = this[3];
  while ( v5 )
  {
    --v5;
    v6 = *(_DWORD **)(this[6] + 4 * v5);
    if ( (*v6 & 0xFFF00000) == 0x20900000 && v6[3] )
    {
      do
      {
        v7 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v6[4] + 4 * v1));
        if ( *(_DWORD *)(v7 + 84) != 2 )
          *(_DWORD *)(v7 + 84) = 1;
        ++v1;
      }
      while ( v1 < v6[3] );
    }
    v1 = 0;
  }
  do
  {
    v55 = 0;
    v58 = this[3];
    if ( !v58 )
      break;
    do
    {
      --v58;
      v8 = *(int **)(this[6] + 4 * v58);
      v9 = *v8;
      if ( (*v8 & 0xFFF00000) != 0 )
      {
        if ( (v9 & 0xF0000000) < 0x10000000 || (v9 & 0xF0000000) > 0x40000000 )
        {
          v12 = v8[3];
          v66 = 0;
          if ( v12 )
          {
            v13 = this[5];
            v14 = (_DWORD *)v8[4];
            v51 = v8[3];
            do
            {
              if ( v66 < *(_DWORD *)(*(_DWORD *)(v13 + 4 * *v14) + 84) )
                v66 = *(_DWORD *)(*(_DWORD *)(v13 + 4 * *v14) + 84);
              ++v14;
              --v51;
            }
            while ( v51 );
            if ( v66 == 1 )
              v55 = 1;
          }
          v15 = 0;
          if ( v12 )
          {
            do
              sub_687542(this, *(_DWORD *)(v8[4] + 4 * v15++), v66);
            while ( v15 < v8[3] );
          }
          for ( j = 0; j < v8[1]; ++j )
            sub_687542(this, *(_DWORD *)(v8[2] + 4 * j), v66);
        }
        else
        {
          v65 = 0;
          for ( k = v8[1] / (v9 & 0xFFFFFu); v65 < v8[3]; ++v65 )
          {
            v10 = *(_DWORD *)(v8[4] + 4 * v65);
            v11 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v10) + 84);
            if ( v11 == 1 )
              v55 = 1;
            sub_687542(this, v10, v11);
            for ( m = 0; m < k; ++m )
              sub_687542(this, *(_DWORD *)(v8[2] + 4 * (v65 + m * v8[3])), v11);
          }
        }
      }
    }
    while ( v58 );
    if ( !v55 )
      break;
    v56 = 0;
    v63 = 0;
    if ( !this[3] )
      break;
    do
    {
      v17 = *(_DWORD **)(this[6] + 4 * v63);
      if ( (*v17 & 0xFFF00000) == 0x20900000 )
      {
        v18 = v17[3];
        for ( n = 0; n < v18; v18 = v17[3] )
        {
          v19 = this[5];
          v49 = *(_DWORD *)(v19 + 4 * *(_DWORD *)(v17[4] + 4 * n));
          if ( *(_DWORD *)(v49 + 84) == 1 )
          {
            v20 = *(_DWORD *)(v17[2] + 4 * (n + v18));
            if ( v20 != -1 && *(_DWORD *)(*(_DWORD *)(v19 + 4 * v20) + 56) != -1 )
              v20 = *(_DWORD *)(*(_DWORD *)(v19 + 4 * v20) + 56);
            v59 = 0;
            v52 = v20;
            v21 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(*(_DWORD *)(v19 + 4 * v20) + 72));
            if ( v21[3] )
            {
              for ( ii = (_DWORD *)v21[4]; *ii != v52; ++ii )
              {
                if ( (unsigned int)++v59 >= v21[3] )
                  break;
              }
            }
            v23 = *(_DWORD *)(v21[2] + 4 * v59);
            if ( v23 != -1 && *(_DWORD *)(*(_DWORD *)(v19 + 4 * v23) + 56) != -1 )
              v23 = *(_DWORD *)(*(_DWORD *)(v19 + 4 * v23) + 56);
            v24 = *(_DWORD *)(*(_DWORD *)(v19 + 4 * v23) + 84);
            if ( v24 != 1 )
            {
              *(_DWORD *)(v49 + 84) = v24;
              v56 = 1;
            }
          }
          ++n;
        }
      }
      ++v63;
    }
    while ( v63 < this[3] );
  }
  while ( v56 );
  for ( jj = 0; jj < this[3]; ++jj )
  {
    v25 = *(int **)(this[6] + 4 * jj);
    v26 = *v25;
    if ( (*v25 & 0xFFF00000) != 0 )
    {
      if ( (v26 & 0xF0000000) < 0x10000000 || (v26 & 0xF0000000) > 0x40000000 )
      {
        v38 = 0;
        v39 = v25[3] == 0;
        if ( v25[3] )
        {
          v40 = (_DWORD *)v25[4];
          do
          {
            if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v40) + 84) == 2 )
              break;
            ++v38;
            ++v40;
          }
          while ( v38 < v25[3] );
          v39 = v38 == v25[3];
        }
        if ( !v39 )
          continue;
        v37 = 0;
        *v25 = 0;
        v25[3] = 0;
      }
      else
      {
        v27 = v25[1] / (v26 & 0xFFFFFu);
        v28 = 0;
        v29 = v25[3] == 0;
        v68 = 0;
        v64 = v27;
        if ( v25[3] )
        {
          do
          {
            v30 = v25[4];
            v31 = *(_DWORD *)(v30 + 4 * v68);
            if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v31) + 84) == 2 )
            {
              v60 = 0;
              for ( *(_DWORD *)(v30 + 4 * v28) = v31;
                    v60 < v64;
                    *(_DWORD *)(v25[2] + 4 * (v28 + v32)) = *(_DWORD *)(v25[2] + 4 * (v32 + v68)) )
              {
                v32 = v60 * v25[3];
                ++v60;
              }
              ++v28;
            }
            ++v68;
          }
          while ( v68 < v25[3] );
          v29 = v28 == v25[3];
        }
        if ( v29 )
          continue;
        if ( v28 )
          v33 = *v25 ^ (v28 ^ *v25) & 0xFFFFF;
        else
          v33 = 0;
        *v25 = v33;
        v69 = 1;
        if ( v64 > 1 )
        {
          v54 = 4 * v28;
          do
          {
            v61 = 0;
            if ( v28 )
            {
              v34 = v54;
              do
              {
                v35 = v25[2];
                v36 = *(_DWORD *)(v35 + 4 * (v61 + v69 * v25[3]));
                ++v61;
                *(_DWORD *)(v34 + v35) = v36;
                v34 += 4;
              }
              while ( v61 < v28 );
            }
            ++v69;
            v54 += 4 * v28;
          }
          while ( v69 < v64 );
        }
        v37 = v64 * v28;
        v25[3] = v28;
      }
      v25[1] = v37;
      v53 = 1;
    }
  }
  for ( kk = 0; kk < this[2]; ++kk )
  {
    v42 = this[5];
    v43 = *(_DWORD **)(v42 + 4 * kk);
    if ( kk == -1 || (v44 = v43[14], v44 == -1) )
      v44 = kk;
    if ( *(_DWORD *)(*(_DWORD *)(v42 + 4 * v44) + 84) != 2 )
    {
      v45 = this[29];
      v46 = v43[1];
      if ( v45 != v46 && (v43[2] != -1 || (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v46) + 5) & 4) == 0) )
      {
        v47 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * v46) + 4);
        if ( (v47 & 0x100) == 0 || (v47 & 0x800) == 0 )
        {
          v43[1] = v45;
          v53 = 1;
        }
      }
    }
  }
  return v53 == 0;
}
