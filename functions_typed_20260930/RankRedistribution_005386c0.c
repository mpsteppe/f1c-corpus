__int16 __fastcall sub_5386C0(int a1, int *a2)
{
  int *v2; // eax
  int v3; // ebp
  int v4; // edx
  int v6; // ebx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ebx
  int v11; // edi
  bool v12; // zf
  _WORD *v13; // edi
  _WORD *i; // ecx
  int v15; // edx
  int v16; // ebx
  int v17; // ecx
  _WORD *v18; // edi
  int v19; // eax
  int v21; // [esp+10h] [ebp-20h]
  int *v22; // [esp+14h] [ebp-1Ch]
  int v23; // [esp+18h] [ebp-18h]
  int v24; // [esp+18h] [ebp-18h]
  int v25; // [esp+1Ch] [ebp-14h]
  int v26; // [esp+20h] [ebp-10h]
  int v27; // [esp+20h] [ebp-10h]
  int v28; // [esp+24h] [ebp-Ch]
  int v29; // [esp+28h] [ebp-8h]
  int v30; // [esp+2Ch] [ebp-4h]

  v28 = a2[1];
  v2 = (int *)a2[2];
  v3 = *a2;
  v4 = *v2;
  v30 = v2[1];
  v29 = v2[2];
  v23 = v2[4];
  v6 = 0;
  memset((void *)(a1 + 2866), 0, 0x20u);
  v21 = 0;
  *(_WORD *)(v3 + 4 * *(_DWORD *)(a1 + 4 * *(_DWORD *)(a1 + 5194) + 2898) + 2) = 0;
  v7 = *(_DWORD *)(a1 + 5194) + 1;
  if ( v7 < 573 )
  {
    v22 = (int *)(a1 + 4 * v7 + 2898);
    v26 = 573 - v7;
    v25 = 573;
    do
    {
      v8 = *v22;
      v9 = *(unsigned __int16 *)(v3 + 4 * *(unsigned __int16 *)(v3 + 4 * *v22 + 2) + 2) + 1;
      if ( v9 > v23 )
      {
        ++v6;
        v9 = v23;
        v21 = v6;
      }
      *(_WORD *)(v3 + 4 * v8 + 2) = v9;
      if ( v8 <= v28 )
      {
        ++*(_WORD *)(a1 + 2 * v9 + 2866);
        v10 = 0;
        if ( v8 >= v29 )
          v10 = *(_DWORD *)(v30 + 4 * (v8 - v29));
        v11 = *(unsigned __int16 *)(v3 + 4 * v8);
        *(_DWORD *)(a1 + 5787) += v11 * (v10 + v9);
        if ( v4 )
          *(_DWORD *)(a1 + 5791) += v11 * (v10 + *(unsigned __int16 *)(v4 + 4 * v8 + 2));
        v6 = v21;
      }
      LOWORD(v7) = v26 - 1;
      v12 = v26 == 1;
      ++v22;
      --v26;
    }
    while ( !v12 );
    if ( v6 )
    {
      v13 = (_WORD *)(a1 + 2 * v23 + 2866);
      do
      {
        v7 = v23 - 1;
        for ( i = (_WORD *)(a1 + 2 * (v23 - 1) + 2866); !*i; --v7 )
          --i;
        --*(_WORD *)(a1 + 2 * v7 + 2866);
        *(_WORD *)(a1 + 2 * v7 + 2868) += 2;
        --*v13;
        v6 -= 2;
      }
      while ( v6 > 0 );
      v15 = v23;
      if ( v23 )
      {
        v27 = a1 + 2 * v23 + 2866;
        do
        {
          v7 = (unsigned __int16)*v13;
          v24 = v7;
          if ( *v13 )
          {
            v16 = a1 + 4 * v25 + 2898;
            do
            {
              v17 = *(_DWORD *)(v16 - 4);
              v16 -= 4;
              --v25;
              if ( v17 <= v28 )
              {
                v18 = (_WORD *)(v3 + 4 * v17 + 2);
                HIWORD(v19) = 0;
                if ( (unsigned __int16)*v18 != v15 )
                {
                  LOWORD(v19) = *v18;
                  *(_DWORD *)(a1 + 5787) += *(unsigned __int16 *)(v3 + 4 * v17) * (v15 - v19);
                  *v18 = v15;
                }
                v7 = --v24;
              }
            }
            while ( v7 );
          }
          --v15;
          v13 = (_WORD *)(v27 - 2);
          v27 -= 2;
        }
        while ( v15 );
      }
    }
  }
  return v7;
}

