int __stdcall sub_675635(int a1, int a2, int a3, unsigned int a4, int a5)
{
  char *v5; // ebx
  _WORD *v6; // esi
  int result; // eax
  unsigned int v8; // ecx
  _DWORD *v9; // edx
  unsigned int n; // edi
  int v11; // ebx
  int v12; // edi
  unsigned __int16 v13; // dx
  _DWORD *v14; // edi
  unsigned int m; // ebx
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // eax
  unsigned __int16 v19; // cx
  _DWORD *v20; // ecx
  float *v21; // eax
  unsigned int v22; // edi
  _DWORD *j; // edi
  unsigned int v24; // edx
  unsigned int v25; // eax
  unsigned int k; // ecx
  int v27; // eax
  _DWORD *v28; // edx
  unsigned int v29; // edi
  unsigned int v30; // eax
  unsigned int i; // ecx
  int v32; // eax
  int v33; // edi
  _DWORD *v34; // ecx
  unsigned int v35; // edx
  unsigned __int16 v36; // ax
  int v37; // ecx
  int v38; // eax
  _DWORD *v39; // eax
  _DWORD *v40; // edx
  __int16 v41; // ax
  unsigned int v42; // edx
  int v43; // edi
  int v44; // edi
  unsigned int v45; // esi
  int v46; // eax
  int v47; // ecx
  _DWORD *v48; // eax
  _DWORD *v49; // ebx
  _DWORD *v50; // ecx
  _DWORD *v51; // ecx
  bool v52; // zf
  unsigned int v53; // eax
  int v54; // [esp+Ch] [ebp-14h]
  unsigned int v55; // [esp+10h] [ebp-10h]
  _DWORD *v56; // [esp+14h] [ebp-Ch]
  _DWORD *v57; // [esp+18h] [ebp-8h]
  char *v58; // [esp+18h] [ebp-8h]
  unsigned int v59; // [esp+18h] [ebp-8h]
  unsigned int v60; // [esp+18h] [ebp-8h]
  _DWORD *v61; // [esp+18h] [ebp-8h]
  _DWORD *v62; // [esp+1Ch] [ebp-4h]
  int v63; // [esp+30h] [ebp+10h]
  unsigned int v64; // [esp+30h] [ebp+10h]
  _DWORD *v65; // [esp+30h] [ebp+10h]
  unsigned int v66; // [esp+34h] [ebp+14h]

  v5 = (char *)a3;
  v6 = *(_WORD **)(a1 + 24);
  v62 = *(_DWORD **)(a1 + 32);
  v57 = (_DWORD *)a3;
  switch ( *v6 )
  {
    case 0:
      v33 = 16 * a4;
      a4 *= 16;
      if ( a4 > (unsigned __int16)v6[4] )
      {
        v33 = (unsigned __int16)v6[4];
        a4 = v33;
      }
      v34 = *(_DWORD **)(a1 + 32);
      v35 = 0;
      if ( v33 )
      {
        do
        {
          *v34++ = *(_DWORD *)(a3 + 4 * (((v35 >> 2) & 3) + 4 * ((v35 & 3) + 4 * (v35 >> 4))));
          ++v35;
        }
        while ( v35 < a4 );
      }
      goto LABEL_68;
    case 1:
      a4 *= 4;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v28 = *(_DWORD **)(a1 + 32);
      v29 = 0;
      if ( a4 )
      {
        v30 = (unsigned __int16)v6[3];
        do
        {
          for ( i = 0; i < v30; ++i )
          {
            if ( i <= 4 )
              v32 = *(_DWORD *)(a3 + 4 * ((v29 & 3) + 4 * (i + 4 * (v29 >> 2))));
            else
              v32 = 0;
            *v28 = v32;
            v30 = (unsigned __int16)v6[3];
            ++v28;
          }
          ++v29;
        }
        while ( v29 < a4 );
      }
      goto LABEL_68;
    case 2:
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v19 = v6[2];
      if ( v19 == 4 && v6[3] == 4 )
      {
        if ( a4 )
        {
          v20 = v62 + 2;
          v21 = (float *)(a3 + 32);
          v22 = a4;
          do
          {
            *(v20 - 2) = *((_DWORD *)v21 - 8);
            *(v20 - 1) = *((_DWORD *)v21 - 4);
            *v20 = *(_DWORD *)v21;
            v20[1] = *((_DWORD *)v21 + 4);
            v20[2] = *((_DWORD *)v21 - 7);
            v20[3] = *((_DWORD *)v21 - 3);
            v20[4] = *((_DWORD *)v21 + 1);
            v20[5] = *((_DWORD *)v21 + 5);
            *(float *)((char *)v21 + (_DWORD)v62 - a3) = *(v21 - 6);
            v20[7] = *((_DWORD *)v21 - 2);
            v20[8] = *((_DWORD *)v21 + 2);
            v20[9] = *((_DWORD *)v21 + 6);
            v20[10] = *((_DWORD *)v21 - 5);
            v20[11] = *((_DWORD *)v21 - 1);
            v20[12] = *((_DWORD *)v21 + 3);
            v20[13] = *((_DWORD *)v21 + 7);
            v21 += 16;
            v20 += 16;
            --v22;
          }
          while ( v22 );
        }
      }
      else
      {
        v60 = 0;
        for ( j = *(_DWORD **)(a1 + 32); v60 < a4; ++v60 )
        {
          v24 = 0;
          if ( v19 )
          {
            v25 = (unsigned __int16)v6[3];
            do
            {
              for ( k = 0; k < v25; ++k )
              {
                if ( v24 > 4 || k > 4 )
                  v27 = 0;
                else
                  v27 = *(_DWORD *)(a3 + 4 * (v24 + 4 * (k + 4 * v60)));
                *j = v27;
                v25 = (unsigned __int16)v6[3];
                ++j;
              }
              v19 = v6[2];
              ++v24;
            }
            while ( v24 < v19 );
          }
        }
      }
      goto LABEL_68;
    case 3:
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v13 = v6[2];
      if ( v13 == 4 && v6[3] == 4 )
      {
LABEL_69:
        v36 = v6[1];
        if ( v36 != 3 )
        {
          v37 = a4 * *(_DWORD *)(a1 + 52);
          v38 = v36 - 1;
          if ( v38 )
          {
            if ( v38 == 1 && v37 )
            {
              v39 = v62;
              do
              {
                *v39 = (int)*(float *)((char *)v39 + v5 - (char *)v62);
                ++v39;
                --v37;
              }
              while ( v37 );
            }
          }
          else if ( v37 )
          {
            v40 = v62;
            do
            {
              *v40 = *(float *)((char *)v40 + v5 - (char *)v62) != 0.0;
              ++v40;
              --v37;
            }
            while ( v37 );
          }
          v5 = (char *)v62;
          v57 = v62;
        }
        v41 = *(_WORD *)(a1 + 8);
        if ( v41 )
        {
          if ( *v6 == 3 )
          {
            v42 = (unsigned __int16)v6[2];
            v43 = (unsigned __int16)v6[3];
          }
          else
          {
            v42 = (unsigned __int16)v6[3];
            v43 = (unsigned __int16)v6[2];
          }
          if ( (v42 & 3) != 0 )
          {
            v56 = &unk_73AF14;
            if ( v41 != 1 )
              v56 = &unk_73AF04;
            v44 = a4 * v43;
            v45 = (v42 + 3) & 0xFFFFFFFC;
            if ( v44 )
            {
              v46 = 4 * v44 + 4;
              v47 = v45 * v46;
              v48 = (_DWORD *)((char *)v57 + v42 * v46);
              v49 = &v62[v42 + v45 * v44];
              v61 = (_DWORD *)((char *)v62 + v47);
              v54 = v44;
              do
              {
                v61 -= v45;
                v49 -= v45;
                v48 -= v42;
                v64 = (v42 + 3) & 0xFFFFFFFC;
                if ( v45 > v42 )
                {
                  v50 = v61;
                  do
                    *--v50 = v56[--v64 & 3];
                  while ( v64 > v42 );
                }
                if ( v42 )
                {
                  v51 = v49;
                  v65 = v48;
                  v55 = v42;
                  do
                  {
                    --v65;
                    --v51;
                    v52 = v55-- == 1;
                    *v51 = *v65;
                  }
                  while ( !v52 );
                }
                --v54;
              }
              while ( v54 );
            }
            v5 = (char *)v62;
          }
        }
        v53 = a4 * *(_DWORD *)(a1 + 44);
        if ( v53 > *(unsigned __int16 *)(a1 + 12) )
          v53 = *(unsigned __int16 *)(a1 + 12);
        result = (*(int (__stdcall **)(int, int, char *, _DWORD *, unsigned int))(a1 + 28))(
                   a2,
                   a5 + *(unsigned __int16 *)(a1 + 10),
                   v5,
                   v62,
                   v53);
        if ( result < 0 )
          return result;
        return 0;
      }
      v14 = *(_DWORD **)(a1 + 32);
      for ( m = 0; m < a4; ++m )
      {
        v59 = 0;
        if ( v6[3] )
        {
          v16 = v13;
          do
          {
            v17 = 0;
            if ( v16 )
            {
              do
              {
                if ( v17 > 4 || v59 > 4 )
                  v18 = 0;
                else
                  v18 = *(_DWORD *)(a3 + 4 * (v17 + 4 * (v59 + 4 * m)));
                *v14 = v18;
                v13 = v6[2];
                ++v14;
                v16 = v13;
                ++v17;
              }
              while ( v17 < v13 );
            }
            ++v59;
          }
          while ( v59 < (unsigned __int16)v6[3] );
        }
      }
LABEL_68:
      v5 = (char *)v62;
      v57 = v62;
      goto LABEL_69;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v8 = *(_DWORD *)(a1 + 52);
  v66 = 16 * a4 / v8;
  if ( v66 > (unsigned __int16)v6[4] )
    v66 = (unsigned __int16)v6[4];
  v9 = *(_DWORD **)(a1 + 32);
  for ( n = 0; n < v66 * v8; ++n )
    *v9++ = *(_DWORD *)(a3 + 4 * (((n >> 2) & 3) + 4 * ((n & 3) + 4 * (n >> 4))));
  v63 = 0;
  v58 = (char *)v62;
  if ( !v66 )
    return 0;
  while ( 1 )
  {
    v11 = 0;
    if ( v6[5] )
      break;
LABEL_15:
    if ( ++v63 >= v66 )
      return 0;
  }
  while ( 1 )
  {
    v12 = *(_DWORD *)(*(_DWORD *)(a1 + 56) + 4 * v11);
    result = sub_674648(a1, a2, v58, *(_DWORD *)(v12 + 48), a5);
    if ( result < 0 )
      return result;
    v58 += 4 * *(_DWORD *)(v12 + 48);
    a5 += *(_DWORD *)(v12 + 40);
    if ( ++v11 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_15;
  }
}
