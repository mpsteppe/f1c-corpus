int __stdcall sub_674352(int a1, int a2, float *a3, unsigned int a4, int a5)
{
  int v5; // edi
  _WORD *v6; // esi
  float *v7; // ebx
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  _DWORD *i; // edx
  unsigned int k; // eax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  bool v15; // cc
  unsigned __int16 v16; // cx
  int v17; // eax
  int v18; // ecx
  float *v19; // ecx
  float *v20; // ecx
  __int16 v21; // cx
  unsigned int v22; // ebx
  int v23; // eax
  int v24; // eax
  unsigned int v25; // esi
  int v26; // ecx
  int v27; // edx
  float *v28; // ecx
  float *v29; // eax
  _DWORD *v30; // edx
  float *v31; // edx
  bool v32; // zf
  unsigned int v33; // eax
  int v34; // [esp+Ch] [ebp-14h]
  _DWORD *v35; // [esp+10h] [ebp-10h]
  unsigned int v36; // [esp+14h] [ebp-Ch]
  _DWORD *v37; // [esp+14h] [ebp-Ch]
  float *v38; // [esp+18h] [ebp-8h]
  float *v39; // [esp+1Ch] [ebp-4h]
  unsigned int j; // [esp+1Ch] [ebp-4h]
  unsigned int v41; // [esp+1Ch] [ebp-4h]
  int v42; // [esp+28h] [ebp+8h]
  int v43; // [esp+30h] [ebp+10h]
  int v44; // [esp+30h] [ebp+10h]
  unsigned int v45; // [esp+30h] [ebp+10h]
  float *v46; // [esp+30h] [ebp+10h]
  unsigned int v47; // [esp+34h] [ebp+14h]

  v5 = a1;
  v6 = *(_WORD **)(a1 + 24);
  v7 = *(float **)(a1 + 32);
  v39 = a3;
  v38 = v7;
  switch ( *v6 )
  {
    case 0:
      v14 = (unsigned __int16)v6[4];
      v15 = a4 <= v14;
LABEL_28:
      if ( !v15 )
        a4 = v14;
LABEL_30:
      v16 = v6[1];
      if ( v16 != 2 )
      {
        v17 = a4 * *(_DWORD *)(a1 + 52);
        v18 = v16 - 1;
        if ( v18 )
        {
          if ( v18 == 2 && v17 )
          {
            v19 = v7;
            do
            {
              *v19 = (float)*(int *)((char *)v19 + (char *)v39 - (char *)v7);
              ++v19;
              --v17;
            }
            while ( v17 );
          }
        }
        else if ( v17 )
        {
          v20 = v7;
          do
          {
            *(_DWORD *)v20 = *(_DWORD *)((char *)v20 + (char *)v39 - (char *)v7) != 0;
            ++v20;
            --v17;
          }
          while ( v17 );
        }
        v39 = v7;
      }
      v21 = *(_WORD *)(a1 + 8);
      if ( v21 )
      {
        if ( *v6 == 3 )
        {
          v22 = (unsigned __int16)v6[2];
          v23 = (unsigned __int16)v6[3];
        }
        else
        {
          v22 = (unsigned __int16)v6[3];
          v23 = (unsigned __int16)v6[2];
        }
        if ( (v22 & 3) != 0 )
        {
          v35 = &unk_73AF14;
          if ( v21 != 1 )
            v35 = &unk_73AF04;
          v24 = a4 * v23;
          v25 = (v22 + 3) & 0xFFFFFFFC;
          v44 = v24;
          if ( v24 )
          {
            v26 = 4 * v24 + 4;
            v27 = v25 * v26;
            v28 = (float *)((char *)v39 + v22 * v26);
            v37 = (_DWORD *)((char *)v38 + v27);
            v29 = &v38[v22 + v25 * v24];
            v34 = v44;
            do
            {
              v37 -= v25;
              v29 -= v25;
              v28 -= v22;
              v45 = (v22 + 3) & 0xFFFFFFFC;
              if ( v25 > v22 )
              {
                v30 = v37;
                do
                  *--v30 = v35[--v45 & 3];
                while ( v45 > v22 );
              }
              if ( v22 )
              {
                v31 = v29;
                v46 = v28;
                v41 = v22;
                do
                {
                  --v46;
                  --v31;
                  v32 = v41-- == 1;
                  *v31 = *v46;
                }
                while ( !v32 );
              }
              --v34;
            }
            while ( v34 );
            v5 = a1;
          }
          v39 = v38;
        }
      }
      v33 = a4 * *(_DWORD *)(v5 + 44);
      if ( v33 > *(unsigned __int16 *)(v5 + 12) )
        v33 = *(unsigned __int16 *)(v5 + 12);
      result = (*(int (__stdcall **)(int, int, float *, float *, unsigned int))(v5 + 28))(
                 a2,
                 a5 + *(unsigned __int16 *)(v5 + 10),
                 v39,
                 v38,
                 v33);
      if ( result < 0 )
        return result;
      return 0;
    case 1:
      v13 = (unsigned __int16)v6[3];
      goto LABEL_26;
    case 2:
      v13 = (unsigned __int16)v6[2] * (unsigned __int16)v6[3];
LABEL_26:
      a4 /= v13;
      v14 = (unsigned __int16)v6[4];
      v15 = a4 <= v14;
      goto LABEL_28;
    case 3:
      v10 = (unsigned __int16)v6[2];
      a4 /= (unsigned __int16)v6[3] * v10;
      if ( a4 > (unsigned __int16)v6[4] )
        a4 = (unsigned __int16)v6[4];
      v36 = 0;
      for ( i = *(_DWORD **)(a1 + 32); v36 < a4; ++v36 )
      {
        for ( j = 0; j < (unsigned __int16)v6[3]; ++j )
        {
          for ( k = 0; k < v10; ++k )
          {
            *i = LODWORD(a3[j + (unsigned __int16)v6[3] * (k + v36 * v10)]);
            v10 = (unsigned __int16)v6[2];
            ++i;
          }
        }
      }
      v39 = v7;
      goto LABEL_30;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v47 = a4 / *(_DWORD *)(a1 + 52);
  if ( v47 > (unsigned __int16)v6[4] )
    v47 = (unsigned __int16)v6[4];
  v42 = 0;
  if ( !v47 )
    return 0;
  while ( 1 )
  {
    v43 = 0;
    if ( v6[5] )
      break;
LABEL_13:
    if ( ++v42 >= v47 )
      return 0;
  }
  while ( 1 )
  {
    v9 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 4 * v43);
    result = sub_674352(v5, a2, v39, *(_DWORD *)(v9 + 48), a5);
    if ( result < 0 )
      return result;
    v39 += *(_DWORD *)(v9 + 48);
    a5 += *(_DWORD *)(v9 + 40);
    if ( ++v43 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_13;
  }
}
