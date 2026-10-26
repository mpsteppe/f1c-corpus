int __stdcall sub_674648(int a1, int a2, char *a3, unsigned int a4, int a5)
{
  int v5; // ebx
  _WORD *v6; // esi
  int result; // eax
  int v8; // edi
  unsigned int v9; // ecx
  _DWORD *i; // edx
  unsigned int k; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  bool v14; // cc
  unsigned __int16 v15; // ax
  int v16; // ecx
  int v17; // eax
  _DWORD *v18; // eax
  _DWORD *v19; // edx
  __int16 v20; // ax
  unsigned int v21; // edx
  int v22; // edi
  int v23; // edi
  unsigned int v24; // esi
  int v25; // eax
  int v26; // ecx
  char *v27; // eax
  _DWORD *v28; // edi
  _DWORD *v29; // ecx
  _DWORD *v30; // ecx
  bool v31; // zf
  unsigned int v32; // eax
  int v33; // [esp+Ch] [ebp-14h]
  _DWORD *v34; // [esp+10h] [ebp-10h]
  unsigned int v35; // [esp+14h] [ebp-Ch]
  _DWORD *v36; // [esp+14h] [ebp-Ch]
  _DWORD *v37; // [esp+18h] [ebp-8h]
  char *v38; // [esp+1Ch] [ebp-4h]
  unsigned int j; // [esp+1Ch] [ebp-4h]
  unsigned int v40; // [esp+1Ch] [ebp-4h]
  int v41; // [esp+28h] [ebp+8h]
  int v42; // [esp+30h] [ebp+10h]
  int v43; // [esp+30h] [ebp+10h]
  unsigned int v44; // [esp+30h] [ebp+10h]
  char *v45; // [esp+30h] [ebp+10h]
  unsigned int v46; // [esp+34h] [ebp+14h]

  v5 = a1;
  v37 = *(_DWORD **)(a1 + 32);
  v6 = *(_WORD **)(a1 + 24);
  v38 = a3;
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
      if ( v15 != 3 )
      {
        v16 = a4 * *(_DWORD *)(a1 + 52);
        v17 = v15 - 1;
        if ( v17 )
        {
          if ( v17 == 1 && v16 )
          {
            v18 = v37;
            do
            {
              *v18 = (int)*(float *)((char *)v18 + v38 - (char *)v37);
              ++v18;
              --v16;
            }
            while ( v16 );
          }
        }
        else if ( v16 )
        {
          v19 = v37;
          do
          {
            *v19 = *(float *)((char *)v19 + v38 - (char *)v37) != 0.0;
            ++v19;
            --v16;
          }
          while ( v16 );
        }
        v38 = (char *)v37;
      }
      v20 = *(_WORD *)(a1 + 8);
      if ( v20 )
      {
        if ( *v6 == 3 )
        {
          v21 = (unsigned __int16)v6[2];
          v22 = (unsigned __int16)v6[3];
        }
        else
        {
          v21 = (unsigned __int16)v6[3];
          v22 = (unsigned __int16)v6[2];
        }
        if ( (v21 & 3) != 0 )
        {
          v34 = &unk_73AF14;
          if ( v20 != 1 )
            v34 = &unk_73AF04;
          v23 = a4 * v22;
          v24 = (v21 + 3) & 0xFFFFFFFC;
          v43 = v23;
          if ( v23 )
          {
            v25 = 4 * v23 + 4;
            v26 = v24 * v25;
            v27 = &v38[v21 * v25];
            v36 = (_DWORD *)((char *)v37 + v26);
            v28 = &v37[v21 + v24 * v23];
            v33 = v43;
            do
            {
              v36 -= v24;
              v28 -= v24;
              v27 -= 4 * v21;
              v44 = (v21 + 3) & 0xFFFFFFFC;
              if ( v24 > v21 )
              {
                v29 = v36;
                do
                  *--v29 = v34[--v44 & 3];
                while ( v44 > v21 );
              }
              if ( v21 )
              {
                v30 = v28;
                v45 = v27;
                v40 = v21;
                do
                {
                  v45 -= 4;
                  --v30;
                  v31 = v40-- == 1;
                  *v30 = *(_DWORD *)v45;
                }
                while ( !v31 );
              }
              --v33;
            }
            while ( v33 );
            v5 = a1;
          }
          v38 = (char *)v37;
        }
      }
      v32 = a4 * *(_DWORD *)(v5 + 44);
      if ( v32 > *(unsigned __int16 *)(v5 + 12) )
        v32 = *(unsigned __int16 *)(v5 + 12);
      result = (*(int (__stdcall **)(int, int, char *, _DWORD *, unsigned int))(v5 + 28))(
                 a2,
                 a5 + *(unsigned __int16 *)(v5 + 10),
                 v38,
                 v37,
                 v32);
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
      v35 = 0;
      for ( i = *(_DWORD **)(a1 + 32); v35 < a4; ++v35 )
      {
        for ( j = 0; j < (unsigned __int16)v6[3]; ++j )
        {
          for ( k = 0; k < v9; ++k )
          {
            *i = *(_DWORD *)&a3[4 * j + 4 * (unsigned __int16)v6[3] * (k + v35 * v9)];
            v9 = (unsigned __int16)v6[2];
            ++i;
          }
        }
      }
      v38 = (char *)v37;
      goto LABEL_30;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v46 = a4 / *(_DWORD *)(a1 + 52);
  if ( v46 > (unsigned __int16)v6[4] )
    v46 = (unsigned __int16)v6[4];
  v41 = 0;
  if ( !v46 )
    return 0;
  while ( 1 )
  {
    v42 = 0;
    if ( v6[5] )
      break;
LABEL_13:
    if ( ++v41 >= v46 )
      return 0;
  }
  while ( 1 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 4 * v42);
    result = sub_674648(v5, a2, v38, *(_DWORD *)(v8 + 48), a5);
    if ( result < 0 )
      return result;
    v38 += 4 * *(_DWORD *)(v8 + 48);
    a5 += *(_DWORD *)(v8 + 40);
    if ( ++v42 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_13;
  }
}
