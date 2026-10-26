int __stdcall sub_675B3D(int a1, int a2, int a3, unsigned int a4, int a5)
{
  _WORD *v5; // esi
  unsigned int v6; // edx
  int result; // eax
  unsigned int v8; // ecx
  unsigned int v9; // edi
  _DWORD *jj; // edx
  int v11; // ebx
  int v12; // edi
  unsigned int v13; // edi
  unsigned int v14; // edx
  unsigned int v15; // eax
  unsigned int ii; // ecx
  int v17; // eax
  _DWORD *v18; // ebx
  _DWORD *v19; // edi
  unsigned int m; // ebx
  unsigned int v21; // eax
  unsigned int v22; // edx
  int v23; // ecx
  int v24; // eax
  _DWORD *v25; // edx
  unsigned int v26; // eax
  unsigned int k; // ecx
  int v28; // eax
  int v29; // edi
  _DWORD *v30; // ecx
  unsigned __int16 v31; // ax
  unsigned int v32; // ecx
  int v33; // eax
  unsigned int i; // eax
  float *v35; // edx
  unsigned int j; // edx
  float *v37; // edi
  __int16 v38; // ax
  unsigned int v39; // edx
  int v40; // edi
  int v41; // edi
  unsigned int v42; // esi
  int v43; // eax
  int v44; // ecx
  char *v45; // eax
  char *v46; // ebx
  char *v47; // ecx
  char *v48; // ecx
  bool v49; // zf
  unsigned int v50; // eax
  int v51; // [esp+Ch] [ebp-14h]
  unsigned int v52; // [esp+10h] [ebp-10h]
  _DWORD *v53; // [esp+14h] [ebp-Ch]
  int v54; // [esp+18h] [ebp-8h]
  _DWORD *n; // [esp+18h] [ebp-8h]
  unsigned int v56; // [esp+18h] [ebp-8h]
  unsigned int v57; // [esp+18h] [ebp-8h]
  char *v58; // [esp+18h] [ebp-8h]
  char *v59; // [esp+1Ch] [ebp-4h]
  char *v60; // [esp+30h] [ebp+10h]
  unsigned int v61; // [esp+30h] [ebp+10h]
  char *v62; // [esp+30h] [ebp+10h]
  unsigned int v63; // [esp+34h] [ebp+14h]

  v5 = *(_WORD **)(a1 + 24);
  v6 = 0;
  v59 = *(char **)(a1 + 32);
  switch ( *v5 )
  {
    case 0:
      v29 = 16 * a4;
      a4 *= 16;
      if ( a4 > (unsigned __int16)v5[4] )
      {
        v29 = (unsigned __int16)v5[4];
        a4 = v29;
      }
      v30 = *(_DWORD **)(a1 + 32);
      if ( v29 )
      {
        do
        {
          *v30++ = *(_DWORD *)(*(_DWORD *)(a3 + 4 * (v6 >> 4)) + 4 * (((v6 >> 2) & 3) + 4 * (v6 & 3)));
          ++v6;
        }
        while ( v6 < a4 );
      }
LABEL_61:
      v31 = v5[1];
      if ( v31 != 3 )
      {
        v32 = a4 * *(_DWORD *)(a1 + 52);
        v33 = v31 - 1;
        if ( v33 )
        {
          if ( v33 == 1 )
          {
            for ( i = 0; i < v32; *(_DWORD *)v35 = (int)*v35 )
              v35 = (float *)&v59[4 * i++];
          }
        }
        else
        {
          for ( j = 0; j < v32; *(_DWORD *)v37 = *v37 != 0.0 )
            v37 = (float *)&v59[4 * j++];
        }
      }
      v38 = *(_WORD *)(a1 + 8);
      if ( v38 )
      {
        if ( *v5 == 3 )
        {
          v39 = (unsigned __int16)v5[2];
          v40 = (unsigned __int16)v5[3];
        }
        else
        {
          v39 = (unsigned __int16)v5[3];
          v40 = (unsigned __int16)v5[2];
        }
        if ( (v39 & 3) != 0 )
        {
          v53 = &unk_73AF14;
          if ( v38 != 1 )
            v53 = &unk_73AF04;
          v41 = a4 * v40;
          v42 = (v39 + 3) & 0xFFFFFFFC;
          if ( v41 )
          {
            v43 = 4 * v41 + 4;
            v44 = v42 * v43;
            v45 = &v59[v39 * v43];
            v46 = &v59[4 * v39 + 4 * v42 * v41];
            v58 = &v59[v44];
            v51 = v41;
            do
            {
              v58 -= 4 * v42;
              v46 -= 4 * v42;
              v45 -= 4 * v39;
              v61 = (v39 + 3) & 0xFFFFFFFC;
              if ( v42 > v39 )
              {
                v47 = v58;
                do
                {
                  --v61;
                  v47 -= 4;
                  *(_DWORD *)v47 = v53[v61 & 3];
                }
                while ( v61 > v39 );
              }
              if ( v39 )
              {
                v48 = v46;
                v62 = v45;
                v52 = v39;
                do
                {
                  v62 -= 4;
                  v48 -= 4;
                  v49 = v52-- == 1;
                  *(_DWORD *)v48 = *(_DWORD *)v62;
                }
                while ( !v49 );
              }
              --v51;
            }
            while ( v51 );
          }
        }
      }
      v50 = a4 * *(_DWORD *)(a1 + 44);
      if ( v50 > *(unsigned __int16 *)(a1 + 12) )
        v50 = *(unsigned __int16 *)(a1 + 12);
      result = (*(int (__stdcall **)(int, int, char *, char *, unsigned int))(a1 + 28))(
                 a2,
                 a5 + *(unsigned __int16 *)(a1 + 10),
                 v59,
                 v59,
                 v50);
      if ( result < 0 )
        return result;
      return 0;
    case 1:
      a4 *= 4;
      if ( a4 > (unsigned __int16)v5[4] )
        a4 = (unsigned __int16)v5[4];
      v57 = 0;
      v25 = *(_DWORD **)(a1 + 32);
      if ( a4 )
      {
        v26 = (unsigned __int16)v5[3];
        do
        {
          for ( k = 0; k < v26; ++k )
          {
            if ( k <= 4 )
              v28 = *(_DWORD *)(*(_DWORD *)(a3 + 4 * (v57 >> 2)) + 4 * ((v57 & 3) + 4 * k));
            else
              v28 = 0;
            *v25 = v28;
            v26 = (unsigned __int16)v5[3];
            ++v25;
          }
          ++v57;
        }
        while ( v57 < a4 );
      }
      goto LABEL_61;
    case 2:
      if ( a4 > (unsigned __int16)v5[4] )
        a4 = (unsigned __int16)v5[4];
      v19 = *(_DWORD **)(a1 + 32);
      for ( m = 0; m < a4; ++m )
      {
        v56 = 0;
        if ( v5[2] )
        {
          v21 = (unsigned __int16)v5[3];
          do
          {
            v22 = 0;
            if ( v21 )
            {
              v23 = 4 * v56;
              do
              {
                if ( v56 > 4 || v22 > 4 )
                  v24 = 0;
                else
                  v24 = *(_DWORD *)(v23 + *(_DWORD *)(a3 + 4 * m));
                *v19 = v24;
                v21 = (unsigned __int16)v5[3];
                ++v19;
                ++v22;
                v23 += 16;
              }
              while ( v22 < v21 );
            }
            ++v56;
          }
          while ( v56 < (unsigned __int16)v5[2] );
        }
      }
      goto LABEL_61;
    case 3:
      if ( a4 > (unsigned __int16)v5[4] )
        a4 = (unsigned __int16)v5[4];
      v13 = 0;
      for ( n = *(_DWORD **)(a1 + 32); v13 < a4; ++v13 )
      {
        v14 = 0;
        if ( v5[3] )
        {
          v15 = (unsigned __int16)v5[2];
          do
          {
            for ( ii = 0; ii < v15; ++ii )
            {
              if ( ii > 4 || v14 > 4 )
                v17 = 0;
              else
                v17 = *(_DWORD *)(*(_DWORD *)(a3 + 4 * v13) + 4 * (ii + 4 * v14));
              v18 = n++;
              *v18 = v17;
              v15 = (unsigned __int16)v5[2];
            }
            ++v14;
          }
          while ( v14 < (unsigned __int16)v5[3] );
        }
      }
      goto LABEL_61;
  }
  if ( *v5 != 5 )
    return -2147467263;
  v8 = *(_DWORD *)(a1 + 52);
  v63 = 16 * a4 / v8;
  if ( v63 > (unsigned __int16)v5[4] )
    v63 = (unsigned __int16)v5[4];
  v9 = 0;
  for ( jj = *(_DWORD **)(a1 + 32); v9 < v63 * v8; ++v9 )
    *jj++ = *(_DWORD *)(*(_DWORD *)(a3 + 4 * (v9 >> 4)) + 4 * (((v9 >> 2) & 3) + 4 * (v9 & 3)));
  v54 = 0;
  v60 = v59;
  if ( !v63 )
    return 0;
  while ( 1 )
  {
    v11 = 0;
    if ( v5[5] )
      break;
LABEL_15:
    if ( ++v54 >= v63 )
      return 0;
  }
  while ( 1 )
  {
    v12 = *(_DWORD *)(*(_DWORD *)(a1 + 56) + 4 * v11);
    result = sub_674648(a1, a2, v60, *(_DWORD *)(v12 + 48), a5);
    if ( result < 0 )
      return result;
    v60 += 4 * *(_DWORD *)(v12 + 48);
    a5 += *(_DWORD *)(v12 + 40);
    if ( ++v11 >= (unsigned int)(unsigned __int16)v5[5] )
      goto LABEL_15;
  }
}
