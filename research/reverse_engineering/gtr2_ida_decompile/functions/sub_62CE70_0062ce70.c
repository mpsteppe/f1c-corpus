int __usercall sub_62CE70@<eax>(int result@<eax>, int *a2@<ecx>)
{
  int v2; // ebx
  int *v3; // ecx
  int v4; // ebp
  int v5; // esi
  int v6; // edi
  int v7; // ecx
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // esi
  int v12; // edi
  bool v13; // zf
  int v14; // ebp
  _WORD *v15; // esi
  int v16; // ecx
  _WORD *i; // edx
  int v18; // edx
  int v19; // esi
  int v20; // ebp
  int v21; // ecx
  int v22; // edi
  int v23; // [esp+10h] [ebp-20h]
  int *v24; // [esp+14h] [ebp-1Ch]
  int v25; // [esp+18h] [ebp-18h]
  int v26; // [esp+1Ch] [ebp-14h]
  int v27; // [esp+1Ch] [ebp-14h]
  int v28; // [esp+20h] [ebp-10h]
  int v29; // [esp+20h] [ebp-10h]
  int v30; // [esp+24h] [ebp-Ch]
  int v31; // [esp+28h] [ebp-8h]
  int v32; // [esp+2Ch] [ebp-4h]

  v30 = a2[1];
  v2 = *a2;
  v3 = (int *)a2[2];
  v32 = v3[1];
  v31 = v3[2];
  v4 = *v3;
  v5 = v3[4];
  *(_DWORD *)(result + 2866) = 0;
  *(_DWORD *)(result + 2870) = 0;
  *(_DWORD *)(result + 2874) = 0;
  *(_DWORD *)(result + 2878) = 0;
  *(_DWORD *)(result + 2882) = 0;
  *(_DWORD *)(result + 2886) = 0;
  *(_DWORD *)(result + 2890) = 0;
  *(_DWORD *)(result + 2894) = 0;
  *(_WORD *)(v2 + 4 * *(_DWORD *)(result + 4 * *(_DWORD *)(result + 5194) + 2898) + 2) = 0;
  v6 = *(_DWORD *)(result + 5194) + 1;
  v26 = v5;
  v25 = 0;
  if ( v6 < 573 )
  {
    v24 = (int *)(result + 4 * v6 + 2898);
    v7 = 573 - v6;
    v8 = 573;
    v28 = v7;
    v23 = 573;
    while ( 1 )
    {
      v9 = *v24;
      v10 = *(unsigned __int16 *)(v2 + 4 * *(unsigned __int16 *)(v2 + 4 * *v24 + 2) + 2) + 1;
      if ( v10 > v5 )
      {
        v10 = v5;
        ++v25;
      }
      *(_WORD *)(v2 + 4 * v9 + 2) = v10;
      if ( v9 <= v30 )
      {
        ++*(_WORD *)(result + 2 * v10 + 2866);
        v11 = 0;
        if ( v9 >= v31 )
          v11 = *(_DWORD *)(v32 + 4 * (v9 - v31));
        v12 = *(unsigned __int16 *)(v2 + 4 * v9);
        *(_DWORD *)(result + 5787) += v12 * (v11 + v10);
        if ( v4 )
          *(_DWORD *)(result + 5791) += v12 * (v11 + *(unsigned __int16 *)(v4 + 4 * v9 + 2));
        v8 = 573;
      }
      v13 = v28 == 1;
      ++v24;
      --v28;
      if ( v13 )
        break;
      v5 = v26;
    }
    v14 = v25;
    if ( v25 )
    {
      v15 = (_WORD *)(result + 2 * v26 + 2866);
      do
      {
        v16 = v26 - 1;
        for ( i = (_WORD *)(result + 2 * (v26 - 1) + 2866); !*i; --v16 )
          --i;
        --*(_WORD *)(result + 2 * v16 + 2866);
        *(_WORD *)(result + 2 * v16 + 2868) += 2;
        --*v15;
        v14 -= 2;
      }
      while ( v14 > 0 );
      v18 = v26;
      if ( v26 )
      {
        v29 = result + 2 * v26 + 2866;
        do
        {
          v19 = (unsigned __int16)*v15;
          v27 = v19;
          if ( v19 )
          {
            v20 = result + 4 * v8 + 2898;
            do
            {
              v21 = *(_DWORD *)(v20 - 4);
              v20 -= 4;
              --v23;
              if ( v21 <= v30 )
              {
                v22 = *(unsigned __int16 *)(v2 + 4 * v21 + 2);
                if ( v22 != v18 )
                {
                  *(_DWORD *)(result + 5787) += *(unsigned __int16 *)(v2 + 4 * v21) * (v18 - v22);
                  *(_WORD *)(v2 + 4 * v21 + 2) = v18;
                }
                v19 = --v27;
              }
            }
            while ( v19 );
            v8 = v23;
          }
          --v18;
          v15 = (_WORD *)(v29 - 2);
          v29 -= 2;
        }
        while ( v18 );
      }
    }
  }
  return result;
}
