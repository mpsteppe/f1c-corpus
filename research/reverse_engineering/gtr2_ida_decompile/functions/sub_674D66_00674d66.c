int __stdcall sub_674D66(int a1, int a2, int a3, unsigned int a4, int a5)
{
  char *v5; // ebx
  _WORD *v6; // esi
  _DWORD *v7; // edi
  int result; // eax
  int v9; // ebx
  int v10; // edi
  unsigned __int16 v11; // dx
  _DWORD *v12; // ecx
  float *v13; // eax
  unsigned int v14; // edi
  unsigned int m; // ebx
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // eax
  unsigned __int16 v19; // cx
  _DWORD *j; // edi
  unsigned int v21; // edx
  unsigned int v22; // eax
  unsigned int k; // ecx
  int v24; // eax
  unsigned int v25; // eax
  _DWORD *v26; // edx
  unsigned int v27; // edi
  unsigned int i; // ecx
  int v29; // eax
  unsigned __int16 v30; // ax
  int v31; // ecx
  int v32; // eax
  _DWORD *v33; // eax
  _DWORD *v34; // edx
  __int16 v35; // ax
  unsigned int v36; // edx
  int v37; // edi
  int v38; // edi
  unsigned int v39; // esi
  int v40; // eax
  int v41; // ecx
  char *v42; // eax
  _DWORD *v43; // ebx
  _DWORD *v44; // ecx
  _DWORD *v45; // ecx
  bool v46; // zf
  unsigned int v47; // eax
  int v48; // [esp+Ch] [ebp-14h]
  unsigned int v49; // [esp+10h] [ebp-10h]
  _DWORD *v50; // [esp+14h] [ebp-Ch]
  char *v51; // [esp+18h] [ebp-8h]
  unsigned int v52; // [esp+18h] [ebp-8h]
  unsigned int v53; // [esp+18h] [ebp-8h]
  _DWORD *v54; // [esp+18h] [ebp-8h]
  _DWORD *v55; // [esp+1Ch] [ebp-4h]
  int v56; // [esp+30h] [ebp+10h]
  unsigned int v57; // [esp+30h] [ebp+10h]
  char *v58; // [esp+30h] [ebp+10h]
  unsigned int v59; // [esp+34h] [ebp+14h]

  v5 = (char *)a3;
  v6 = *(_WORD **)(a1 + 24);
  v7 = *(_DWORD **)(a1 + 32);
  v55 = v7;
  v51 = (char *)a3;
  switch ( *v6 )
  {
    case 0:
      a4 *= 16;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      goto LABEL_65;
    case 1:
      a4 *= 4;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      LOWORD(v25) = v6[3];
      if ( (_WORD)v25 != 4 )
      {
        v26 = *(_DWORD **)(a1 + 32);
        v27 = 0;
        if ( a4 )
        {
          v25 = (unsigned __int16)v25;
          do
          {
            for ( i = 0; i < v25; ++i )
            {
              if ( i <= 4 )
                v29 = *(_DWORD *)(a3 + 4 * (i + 4 * v27));
              else
                v29 = 0;
              *v26 = v29;
              v25 = (unsigned __int16)v6[3];
              ++v26;
            }
            ++v27;
          }
          while ( v27 < a4 );
        }
        goto LABEL_22;
      }
      goto LABEL_65;
    case 2:
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v19 = v6[2];
      if ( v19 != 4 || v6[3] != 4 )
      {
        v53 = 0;
        for ( j = *(_DWORD **)(a1 + 32); v53 < a4; ++v53 )
        {
          v21 = 0;
          if ( v19 )
          {
            v22 = (unsigned __int16)v6[3];
            do
            {
              for ( k = 0; k < v22; ++k )
              {
                if ( v21 > 4 || k > 4 )
                  v24 = 0;
                else
                  v24 = *(_DWORD *)(a3 + 4 * (k + 4 * (v21 + 4 * v53)));
                *j = v24;
                v22 = (unsigned __int16)v6[3];
                ++j;
              }
              v19 = v6[2];
              ++v21;
            }
            while ( v21 < v19 );
          }
        }
        goto LABEL_22;
      }
LABEL_65:
      v30 = v6[1];
      if ( v30 != 3 )
      {
        v31 = a4 * *(_DWORD *)(a1 + 52);
        v32 = v30 - 1;
        if ( v32 )
        {
          if ( v32 == 1 && v31 )
          {
            v33 = v55;
            do
            {
              *v33 = (int)*(float *)((char *)v33 + v5 - (char *)v55);
              ++v33;
              --v31;
            }
            while ( v31 );
          }
        }
        else if ( v31 )
        {
          v34 = v55;
          do
          {
            *v34 = *(float *)((char *)v34 + v5 - (char *)v55) != 0.0;
            ++v34;
            --v31;
          }
          while ( v31 );
        }
        v51 = (char *)v55;
      }
      v35 = *(_WORD *)(a1 + 8);
      if ( v35 )
      {
        if ( *v6 == 3 )
        {
          v36 = (unsigned __int16)v6[2];
          v37 = (unsigned __int16)v6[3];
        }
        else
        {
          v36 = (unsigned __int16)v6[3];
          v37 = (unsigned __int16)v6[2];
        }
        if ( (v36 & 3) != 0 )
        {
          v50 = &unk_73AF14;
          if ( v35 != 1 )
            v50 = &unk_73AF04;
          v38 = a4 * v37;
          v39 = (v36 + 3) & 0xFFFFFFFC;
          if ( v38 )
          {
            v40 = 4 * v38 + 4;
            v41 = v39 * v40;
            v42 = &v51[v36 * v40];
            v43 = &v55[v36 + v39 * v38];
            v54 = (_DWORD *)((char *)v55 + v41);
            v48 = v38;
            do
            {
              v54 -= v39;
              v43 -= v39;
              v42 -= 4 * v36;
              v57 = (v36 + 3) & 0xFFFFFFFC;
              if ( v39 > v36 )
              {
                v44 = v54;
                do
                  *--v44 = v50[--v57 & 3];
                while ( v57 > v36 );
              }
              if ( v36 )
              {
                v45 = v43;
                v58 = v42;
                v49 = v36;
                do
                {
                  v58 -= 4;
                  --v45;
                  v46 = v49-- == 1;
                  *v45 = *(_DWORD *)v58;
                }
                while ( !v46 );
              }
              --v48;
            }
            while ( v48 );
          }
          v51 = (char *)v55;
        }
      }
      v47 = a4 * *(_DWORD *)(a1 + 44);
      if ( v47 > *(unsigned __int16 *)(a1 + 12) )
        v47 = *(unsigned __int16 *)(a1 + 12);
      result = (*(int (__stdcall **)(int, int, char *, _DWORD *, unsigned int))(a1 + 28))(
                 a2,
                 a5 + *(unsigned __int16 *)(a1 + 10),
                 v51,
                 v55,
                 v47);
      if ( result < 0 )
        return result;
      return 0;
    case 3:
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v11 = v6[2];
      if ( v11 == 4 && v6[3] == 4 )
      {
        if ( a4 )
        {
          v12 = v7 + 2;
          v13 = (float *)(a3 + 32);
          v14 = a4;
          do
          {
            *(v12 - 2) = *((_DWORD *)v13 - 8);
            *(v12 - 1) = *((_DWORD *)v13 - 4);
            *v12 = *(_DWORD *)v13;
            v12[1] = *((_DWORD *)v13 + 4);
            v12[2] = *((_DWORD *)v13 - 7);
            v12[3] = *((_DWORD *)v13 - 3);
            v12[4] = *((_DWORD *)v13 + 1);
            v12[5] = *((_DWORD *)v13 + 5);
            *(float *)((char *)v55 + (_DWORD)v13 - a3) = *(v13 - 6);
            v12[7] = *((_DWORD *)v13 - 2);
            v12[8] = *((_DWORD *)v13 + 2);
            v12[9] = *((_DWORD *)v13 + 6);
            v12[10] = *((_DWORD *)v13 - 5);
            v12[11] = *((_DWORD *)v13 - 1);
            v12[12] = *((_DWORD *)v13 + 3);
            v12[13] = *((_DWORD *)v13 + 7);
            v13 += 16;
            v12 += 16;
            --v14;
          }
          while ( v14 );
        }
      }
      else
      {
        for ( m = 0; m < a4; ++m )
        {
          v52 = 0;
          if ( v6[3] )
          {
            v16 = v11;
            do
            {
              v17 = 0;
              if ( v16 )
              {
                do
                {
                  if ( v17 > 4 || v52 > 4 )
                    v18 = 0;
                  else
                    v18 = *(_DWORD *)(a3 + 4 * (v52 + 4 * (v17 + 4 * m)));
                  *v7 = v18;
                  v11 = v6[2];
                  ++v7;
                  v16 = v11;
                  ++v17;
                }
                while ( v17 < v11 );
              }
              ++v52;
            }
            while ( v52 < (unsigned __int16)v6[3] );
          }
        }
      }
LABEL_22:
      v5 = (char *)v55;
      v51 = (char *)v55;
      goto LABEL_65;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v59 = 16 * a4 / *(_DWORD *)(a1 + 52);
  if ( v59 > (unsigned __int16)v6[4] )
    v59 = (unsigned __int16)v6[4];
  v56 = 0;
  if ( !v59 )
    return 0;
  while ( 1 )
  {
    v9 = 0;
    if ( v6[5] )
      break;
LABEL_13:
    if ( ++v56 >= v59 )
      return 0;
  }
  while ( 1 )
  {
    v10 = *(_DWORD *)(*(_DWORD *)(a1 + 56) + 4 * v9);
    result = sub_674648(a1, a2, v51, *(_DWORD *)(v10 + 48), a5);
    if ( result < 0 )
      return result;
    v51 += 4 * *(_DWORD *)(v10 + 48);
    a5 += *(_DWORD *)(v10 + 40);
    if ( ++v9 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_13;
  }
}
