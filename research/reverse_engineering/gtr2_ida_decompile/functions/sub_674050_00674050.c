int __stdcall sub_674050(int a1, int a2, float *a3, unsigned int a4, int a5)
{
  int v5; // edi
  _WORD *v6; // esi
  int result; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  _DWORD *i; // edx
  unsigned int k; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  bool v14; // cc
  unsigned __int16 v15; // cx
  int v16; // eax
  int v17; // ecx
  int v18; // ecx
  float *v19; // ecx
  double v20; // st7
  float *v21; // ecx
  __int16 v22; // cx
  unsigned int v23; // ebx
  int v24; // eax
  int v25; // eax
  unsigned int v26; // esi
  int v27; // ecx
  int v28; // edx
  float *v29; // ecx
  float *v30; // eax
  _DWORD *v31; // edx
  float *v32; // edx
  bool v33; // zf
  unsigned int v34; // eax
  int v35; // [esp+Ch] [ebp-14h]
  _DWORD *v36; // [esp+10h] [ebp-10h]
  unsigned int v37; // [esp+14h] [ebp-Ch]
  _DWORD *v38; // [esp+14h] [ebp-Ch]
  float *v39; // [esp+18h] [ebp-8h]
  float *v40; // [esp+1Ch] [ebp-4h]
  unsigned int j; // [esp+1Ch] [ebp-4h]
  unsigned int v42; // [esp+1Ch] [ebp-4h]
  int v43; // [esp+28h] [ebp+8h]
  int v44; // [esp+30h] [ebp+10h]
  int v45; // [esp+30h] [ebp+10h]
  unsigned int v46; // [esp+30h] [ebp+10h]
  float *v47; // [esp+30h] [ebp+10h]
  unsigned int v48; // [esp+34h] [ebp+14h]

  v5 = a1;
  v6 = *(_WORD **)(a1 + 24);
  v39 = *(float **)(a1 + 32);
  v40 = a3;
  switch ( *v6 )
  {
    case 0:
      v13 = (unsigned __int16)v6[4];
      v14 = a4 <= v13;
LABEL_28:
      if ( !v14 )
        a4 = v13;
LABEL_30:
      v15 = v6[1];
      if ( v15 != 1 )
      {
        v16 = a4 * *(_DWORD *)(a1 + 52);
        v17 = v15 - 1;
        if ( v17 )
        {
          v18 = v17 - 1;
          if ( v18 )
          {
            if ( v18 == 1 && v16 )
            {
              v19 = v39;
              do
              {
                if ( *(_DWORD *)((char *)v19 + (char *)v40 - (char *)v39) )
                  v20 = 1.0;
                else
                  v20 = 0.0;
                *v19++ = v20;
                --v16;
              }
              while ( v16 );
            }
          }
          else if ( v16 )
          {
            v21 = v39;
            do
            {
              *(_DWORD *)v21 = *(_DWORD *)((char *)v21 + (char *)v40 - (char *)v39) != 0;
              ++v21;
              --v16;
            }
            while ( v16 );
          }
        }
        v40 = v39;
      }
      v22 = *(_WORD *)(a1 + 8);
      if ( v22 )
      {
        if ( *v6 == 3 )
        {
          v23 = (unsigned __int16)v6[2];
          v24 = (unsigned __int16)v6[3];
        }
        else
        {
          v23 = (unsigned __int16)v6[3];
          v24 = (unsigned __int16)v6[2];
        }
        if ( (v23 & 3) != 0 )
        {
          v36 = &unk_73AF14;
          if ( v22 != 1 )
            v36 = &unk_73AF04;
          v25 = a4 * v24;
          v26 = (v23 + 3) & 0xFFFFFFFC;
          v45 = v25;
          if ( v25 )
          {
            v27 = 4 * v25 + 4;
            v28 = v26 * v27;
            v29 = (float *)((char *)v40 + v23 * v27);
            v38 = (_DWORD *)((char *)v39 + v28);
            v30 = &v39[v23 + v26 * v25];
            v35 = v45;
            do
            {
              v38 -= v26;
              v30 -= v26;
              v29 -= v23;
              v46 = (v23 + 3) & 0xFFFFFFFC;
              if ( v26 > v23 )
              {
                v31 = v38;
                do
                  *--v31 = v36[--v46 & 3];
                while ( v46 > v23 );
              }
              if ( v23 )
              {
                v32 = v30;
                v47 = v29;
                v42 = v23;
                do
                {
                  --v47;
                  --v32;
                  v33 = v42-- == 1;
                  *v32 = *v47;
                }
                while ( !v33 );
              }
              --v35;
            }
            while ( v35 );
            v5 = a1;
          }
          v40 = v39;
        }
      }
      v34 = a4 * *(_DWORD *)(v5 + 44);
      if ( v34 > *(unsigned __int16 *)(v5 + 12) )
        v34 = *(unsigned __int16 *)(v5 + 12);
      result = (*(int (__stdcall **)(int, int, float *, float *, unsigned int))(v5 + 28))(
                 a2,
                 a5 + *(unsigned __int16 *)(v5 + 10),
                 v40,
                 v39,
                 v34);
      if ( result < 0 )
        return result;
      return 0;
    case 1:
      v12 = (unsigned __int16)v6[3];
      goto LABEL_26;
    case 2:
      v12 = (unsigned __int16)v6[2] * (unsigned __int16)v6[3];
LABEL_26:
      a4 /= v12;
      v13 = (unsigned __int16)v6[4];
      v14 = a4 <= v13;
      goto LABEL_28;
    case 3:
      v9 = (unsigned __int16)v6[2];
      a4 /= (unsigned __int16)v6[3] * v9;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v37 = 0;
      for ( i = *(_DWORD **)(a1 + 32); v37 < a4; ++v37 )
      {
        for ( j = 0; j < (unsigned __int16)v6[3]; ++j )
        {
          for ( k = 0; k < v9; ++k )
          {
            *i = LODWORD(a3[j + (unsigned __int16)v6[3] * (k + v37 * v9)]);
            v9 = (unsigned __int16)v6[2];
            ++i;
          }
        }
      }
      v40 = v39;
      goto LABEL_30;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v48 = a4 / *(_DWORD *)(a1 + 52);
  if ( v48 > (unsigned __int16)v6[4] )
    v48 = (unsigned __int16)v6[4];
  v43 = 0;
  if ( !v48 )
    return 0;
  while ( 1 )
  {
    v44 = 0;
    if ( v6[5] )
      break;
LABEL_13:
    if ( ++v43 >= v48 )
      return 0;
  }
  while ( 1 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 4 * v44);
    result = sub_674050(v5, a2, v40, *(_DWORD *)(v8 + 48), a5);
    if ( result < 0 )
      return result;
    v40 += *(_DWORD *)(v8 + 48);
    a5 += *(_DWORD *)(v8 + 40);
    if ( ++v44 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_13;
  }
}
