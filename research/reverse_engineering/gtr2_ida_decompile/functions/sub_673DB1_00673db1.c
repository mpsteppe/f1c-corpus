int __stdcall sub_673DB1(int a1, int a2, int a3, unsigned int a4, int a5)
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
  __int16 v15; // cx
  unsigned int v16; // ebx
  int v17; // eax
  int v18; // eax
  unsigned int v19; // esi
  int v20; // ecx
  int v21; // edx
  _DWORD *v22; // ecx
  _DWORD *v23; // eax
  _DWORD *v24; // edx
  _DWORD *v25; // edx
  bool v26; // zf
  unsigned int v27; // eax
  int v28; // [esp+Ch] [ebp-14h]
  _DWORD *v29; // [esp+10h] [ebp-10h]
  unsigned int v30; // [esp+14h] [ebp-Ch]
  _DWORD *v31; // [esp+14h] [ebp-Ch]
  int v32; // [esp+18h] [ebp-8h]
  int v33; // [esp+1Ch] [ebp-4h]
  unsigned int j; // [esp+1Ch] [ebp-4h]
  unsigned int v35; // [esp+1Ch] [ebp-4h]
  int v36; // [esp+28h] [ebp+8h]
  int v37; // [esp+30h] [ebp+10h]
  int v38; // [esp+30h] [ebp+10h]
  unsigned int v39; // [esp+30h] [ebp+10h]
  _DWORD *v40; // [esp+30h] [ebp+10h]
  unsigned int v41; // [esp+34h] [ebp+14h]

  v5 = a1;
  v6 = *(_WORD **)(a1 + 24);
  v32 = *(_DWORD *)(a1 + 32);
  v33 = a3;
  switch ( *v6 )
  {
    case 0:
      v13 = (unsigned __int16)v6[4];
      v14 = a4 <= v13;
LABEL_28:
      if ( !v14 )
        a4 = v13;
LABEL_30:
      v15 = *(_WORD *)(a1 + 8);
      if ( v15 )
      {
        if ( *v6 == 3 )
        {
          v16 = (unsigned __int16)v6[2];
          v17 = (unsigned __int16)v6[3];
        }
        else
        {
          v16 = (unsigned __int16)v6[3];
          v17 = (unsigned __int16)v6[2];
        }
        if ( (v16 & 3) != 0 )
        {
          v29 = &unk_73AF14;
          if ( v15 != 1 )
            v29 = &unk_73AF04;
          v18 = a4 * v17;
          v19 = (v16 + 3) & 0xFFFFFFFC;
          v38 = v18;
          if ( v18 )
          {
            v20 = 4 * v18 + 4;
            v21 = v19 * v20;
            v22 = (_DWORD *)(v33 + v16 * v20);
            v31 = (_DWORD *)(v32 + v21);
            v23 = (_DWORD *)(v32 + 4 * (v16 + v19 * v18));
            v28 = v38;
            do
            {
              v31 -= v19;
              v23 -= v19;
              v22 -= v16;
              v39 = (v16 + 3) & 0xFFFFFFFC;
              if ( v19 > v16 )
              {
                v24 = v31;
                do
                  *--v24 = v29[--v39 & 3];
                while ( v39 > v16 );
              }
              if ( v16 )
              {
                v25 = v23;
                v40 = v22;
                v35 = v16;
                do
                {
                  --v40;
                  --v25;
                  v26 = v35-- == 1;
                  *v25 = *v40;
                }
                while ( !v26 );
              }
              --v28;
            }
            while ( v28 );
            v5 = a1;
          }
          v33 = v32;
        }
      }
      v27 = a4 * *(_DWORD *)(v5 + 44);
      if ( v27 > *(unsigned __int16 *)(v5 + 12) )
        v27 = *(unsigned __int16 *)(v5 + 12);
      result = (*(int (__stdcall **)(int, int, int, int, unsigned int))(v5 + 28))(
                 a2,
                 a5 + *(unsigned __int16 *)(v5 + 10),
                 v33,
                 v32,
                 v27);
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
      v30 = 0;
      for ( i = *(_DWORD **)(a1 + 32); v30 < a4; ++v30 )
      {
        for ( j = 0; j < (unsigned __int16)v6[3]; ++j )
        {
          for ( k = 0; k < v9; ++k )
          {
            *i = *(_DWORD *)(a3 + 4 * (j + (unsigned __int16)v6[3] * (k + v30 * v9)));
            v9 = (unsigned __int16)v6[2];
            ++i;
          }
        }
      }
      v33 = v32;
      goto LABEL_30;
  }
  if ( *v6 != 5 )
    return -2147467263;
  v41 = a4 / *(_DWORD *)(a1 + 52);
  if ( v41 > (unsigned __int16)v6[4] )
    v41 = (unsigned __int16)v6[4];
  v36 = 0;
  if ( !v41 )
    return 0;
  while ( 1 )
  {
    v37 = 0;
    if ( v6[5] )
      break;
LABEL_13:
    if ( ++v36 >= v41 )
      return 0;
  }
  while ( 1 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 4 * v37);
    result = sub_673DB1(v5, a2, v33, *(_DWORD *)(v8 + 48), a5);
    if ( result < 0 )
      return result;
    v33 += 4 * *(_DWORD *)(v8 + 48);
    a5 += *(_DWORD *)(v8 + 40);
    if ( ++v37 >= (unsigned int)(unsigned __int16)v6[5] )
      goto LABEL_13;
  }
}
