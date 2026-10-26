int __stdcall sub_674979(int a1, int a2, char *a3, unsigned int a4, int a5)
{
  _DWORD *v5; // ebx
  _WORD *v6; // esi
  int result; // eax
  int v8; // ebx
  int v9; // edi
  unsigned int v10; // ecx
  _DWORD *j; // edi
  unsigned int v12; // edx
  unsigned int v13; // eax
  unsigned int k; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  unsigned __int16 v17; // dx
  _DWORD *v18; // edi
  unsigned int v19; // ebx
  int v20; // eax
  unsigned int v21; // ecx
  int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // edi
  _DWORD *v25; // edx
  unsigned int i; // ecx
  int v27; // eax
  unsigned __int16 v28; // ax
  int v29; // ecx
  int v30; // eax
  _DWORD *v31; // eax
  _DWORD *v32; // edx
  __int16 v33; // ax
  unsigned int v34; // edx
  int v35; // edi
  int v36; // edi
  unsigned int v37; // esi
  char *v38; // eax
  _DWORD *v39; // ecx
  _DWORD *v40; // edi
  bool v41; // zf
  unsigned int v42; // eax
  int v43; // [esp+Ch] [ebp-14h]
  _DWORD *v44; // [esp+10h] [ebp-10h]
  _DWORD *v45; // [esp+14h] [ebp-Ch]
  _DWORD *v46; // [esp+18h] [ebp-8h]
  char *v47; // [esp+1Ch] [ebp-4h]
  unsigned int v48; // [esp+1Ch] [ebp-4h]
  unsigned int v49; // [esp+1Ch] [ebp-4h]
  _DWORD *v50; // [esp+1Ch] [ebp-4h]
  unsigned int v51; // [esp+1Ch] [ebp-4h]
  int v52; // [esp+30h] [ebp+10h]
  unsigned int v53; // [esp+30h] [ebp+10h]
  char *v54; // [esp+30h] [ebp+10h]
  unsigned int v55; // [esp+34h] [ebp+14h]

  v5 = *(_DWORD **)(a1 + 32);
  v6 = *(_WORD **)(a1 + 24);
  v47 = a3;
  v46 = v5;
  switch ( *v6 )
  {
    case 0:
      a4 *= 4;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      goto LABEL_56;
    case 1:
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      LOWORD(v23) = v6[3];
      if ( (_WORD)v23 != 4 )
      {
        v24 = 0;
        v25 = *(_DWORD **)(a1 + 32);
        if ( a4 )
        {
          v23 = (unsigned __int16)v23;
          do
          {
            for ( i = 0; i < v23; ++i )
            {
              if ( i <= 4 )
              {
                v27 = *(_DWORD *)&a3[16 * v24 + 4 * i];
                v5 = v46;
              }
              else
              {
                v27 = 0;
              }
              *v25 = v27;
              v23 = (unsigned __int16)v6[3];
              ++v25;
            }
            ++v24;
          }
          while ( v24 < a4 );
        }
        goto LABEL_27;
      }
      goto LABEL_56;
    case 2:
      v16 = (unsigned __int16)v6[2];
      a4 /= v16;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v17 = v6[3];
      if ( v17 != 4 )
      {
        v49 = 0;
        v18 = *(_DWORD **)(a1 + 32);
        if ( a4 )
        {
          do
          {
            v19 = 0;
            if ( v16 )
            {
              v20 = v17;
              do
              {
                v21 = 0;
                if ( v20 )
                {
                  do
                  {
                    if ( v21 <= 4 )
                      v22 = *(_DWORD *)&a3[16 * v19 + 16 * v49 * (unsigned __int16)v6[2] + 4 * v21];
                    else
                      v22 = 0;
                    *v18 = v22;
                    v17 = v6[3];
                    ++v18;
                    v20 = v17;
                    ++v21;
                  }
                  while ( v21 < v17 );
                }
                v16 = (unsigned __int16)v6[2];
                ++v19;
              }
              while ( v19 < v16 );
            }
            ++v49;
          }
          while ( v49 < a4 );
          v5 = v46;
        }
        goto LABEL_27;
      }
LABEL_56:
      v28 = v6[1];
      if ( v28 != 3 )
      {
        v29 = a4 * *(_DWORD *)(a1 + 52);
        v30 = v28 - 1;
        if ( v30 )
        {
          if ( v30 == 1 && v29 )
          {
            v31 = v5;
            do
            {
              *v31 = (int)*(float *)((char *)v31 + v47 - (char *)v5);
              ++v31;
              --v29;
            }
            while ( v29 );
          }
        }
        else if ( v29 )
        {
          v32 = v5;
          do
          {
            *v32 = *(float *)((char *)v32 + v47 - (char *)v5) != 0.0;
            ++v32;
            --v29;
          }
          while ( v29 );
        }
        v47 = (char *)v5;
      }
      v33 = *(_WORD *)(a1 + 8);
      if ( v33 )
      {
        if ( *v6 == 3 )
        {
          v34 = (unsigned __int16)v6[2];
          v35 = (unsigned __int16)v6[3];
        }
        else
        {
          v34 = (unsigned __int16)v6[3];
          v35 = (unsigned __int16)v6[2];
        }
        if ( (v34 & 3) != 0 )
        {
          v44 = &unk_73AF14;
          if ( v33 != 1 )
            v44 = &unk_73AF04;
          v36 = a4 * v35;
          v37 = (v34 + 3) & 0xFFFFFFFC;
          if ( v36 )
          {
            v38 = &v47[(4 * v36 + 4) * v34];
            v45 = &v5[v34 + v37 * v36];
            v39 = (_DWORD *)((char *)v46 + (4 * v36 + 4) * v37);
            v43 = v36;
            do
            {
              v45 -= v37;
              v39 -= v37;
              v38 -= 4 * v34;
              v53 = (v34 + 3) & 0xFFFFFFFC;
              if ( v37 > v34 )
              {
                v50 = v39;
                do
                  *--v50 = v44[--v53 & 3];
                while ( v53 > v34 );
              }
              if ( v34 )
              {
                v40 = v45;
                v54 = v38;
                v51 = v34;
                do
                {
                  v54 -= 4;
                  --v40;
                  v41 = v51-- == 1;
                  *v40 = *(_DWORD *)v54;
                }
                while ( !v41 );
              }
              --v43;
            }
            while ( v43 );
            v5 = v46;
          }
          v47 = (char *)v5;
        }
      }
      v42 = a4 * *(_DWORD *)(a1 + 44);
      if ( v42 > *(unsigned __int16 *)(a1 + 12) )
        v42 = *(unsigned __int16 *)(a1 + 12);
      result = (*(int (__stdcall **)(int, int, char *, _DWORD *, unsigned int))(a1 + 28))(
                 a2,
                 a5 + *(unsigned __int16 *)(a1 + 10),
                 v47,
                 v5,
                 v42);
      if ( result < 0 )
        return result;
      return 0;
    case 3:
      v10 = (unsigned __int16)v6[3];
      a4 /= v10;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v48 = 0;
      for ( j = *(_DWORD **)(a1 + 32); v48 < a4; ++v48 )
      {
        v12 = 0;
        if ( v10 )
        {
          v13 = (unsigned __int16)v6[2];
          do
          {
            for ( k = 0; k < v13; ++k )
            {
              if ( v12 <= 4 )
              {
                v15 = *(_DWORD *)&a3[16 * k + 16 * v48 * v13 + 4 * v12];
                v5 = v46;
              }
              else
              {
                v15 = 0;
              }
              *j = v15;
              v13 = (unsigned __int16)v6[2];
              ++j;
            }
            v10 = (unsigned __int16)v6[3];
            ++v12;
          }
          while ( v12 < v10 );
        }
      }
LABEL_27:
      v47 = (char *)v5;
      goto LABEL_56;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v55 = 4 * a4 / *(_DWORD *)(a1 + 52);
  if ( v55 > (unsigned __int16)v6[4] )
    v55 = (unsigned __int16)v6[4];
  v52 = 0;
  if ( !v55 )
    return 0;
  while ( 1 )
  {
    v8 = 0;
    if ( v6[5] )
      break;
LABEL_13:
    if ( ++v52 >= v55 )
      return 0;
  }
  while ( 1 )
  {
    v9 = *(_DWORD *)(*(_DWORD *)(a1 + 56) + 4 * v8);
    result = sub_674648(a1, a2, v47, *(_DWORD *)(v9 + 48), a5);
    if ( result < 0 )
      return result;
    v47 += 4 * *(_DWORD *)(v9 + 48);
    a5 += *(_DWORD *)(v9 + 40);
    if ( ++v8 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_13;
  }
}
