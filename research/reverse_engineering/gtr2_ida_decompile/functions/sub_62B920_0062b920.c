int __fastcall sub_62B920(int *a1, int a2)
{
  unsigned int v3; // eax
  int v4; // ecx
  bool v5; // zf
  int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // eax
  int v9; // eax
  int v10; // esi
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // edi
  int v14; // ecx
  _DWORD *v15; // eax
  unsigned int v16; // eax
  int v17; // eax
  int v18; // esi
  unsigned int v19; // edx
  int v20; // ecx
  int v21; // edi
  int v22; // ecx
  _DWORD *v23; // eax
  int v25; // eax
  int v26; // eax
  int v27; // [esp+10h] [ebp-8h]

  v27 = 0xFFFF;
  if ( (unsigned int)(a1[3] - 5) < 0xFFFF )
    v27 = a1[3] - 5;
  while ( 1 )
  {
    v3 = *(int *)((char *)a1 + 106);
    if ( v3 <= 1 )
    {
      sub_62B790(a1);
      v3 = *(int *)((char *)a1 + 106);
      if ( !v3 )
        break;
    }
    v4 = *(int *)((char *)a1 + 98);
    v5 = v3 + v4 == 0;
    *(int *)((char *)a1 + 98) = v3 + v4;
    v6 = *(int *)((char *)a1 + 82);
    v7 = *(int *)((char *)a1 + 98);
    *(int *)((char *)a1 + 106) = 0;
    v8 = v6 + v27;
    if ( !v5 && v7 < v8 )
      goto LABEL_27;
    *(int *)((char *)a1 + 106) = v7 - v8;
    *(int *)((char *)a1 + 98) = v8;
    sub_62E530(v27, 0);
    v9 = *a1;
    *(int *)((char *)a1 + 82) = *(int *)((char *)a1 + 98);
    v10 = *(_DWORD *)(v9 + 28);
    v11 = *(_DWORD *)(v10 + 20);
    if ( v11 > *(_DWORD *)(v9 + 16) )
      v11 = *(_DWORD *)(v9 + 16);
    if ( v11 )
    {
      qmemcpy(*(void **)(v9 + 12), *(const void **)(v10 + 16), v11);
      v12 = *(_DWORD *)(v9 + 28);
      *(_DWORD *)(v9 + 12) += v11;
      *(_DWORD *)(v12 + 16) += v11;
      v13 = *(_DWORD *)(v9 + 16);
      v14 = *(_DWORD *)(v9 + 28);
      *(_DWORD *)(v9 + 20) += v11;
      *(_DWORD *)(v9 + 16) = v13 - v11;
      *(_DWORD *)(v14 + 20) -= v11;
      v15 = *(_DWORD **)(v9 + 28);
      if ( !v15[5] )
        v15[4] = v15[2];
    }
    if ( *(_DWORD *)(*a1 + 16) )
    {
LABEL_27:
      v16 = *(int *)((char *)a1 + 98) - *(int *)((char *)a1 + 82);
      if ( v16 < *(int *)((char *)a1 + 34) - 262 )
        continue;
      sub_62E530(v16, 0);
      *(int *)((char *)a1 + 82) = *(int *)((char *)a1 + 98);
      v17 = *a1;
      v18 = *(_DWORD *)(*a1 + 28);
      v19 = *(_DWORD *)(v18 + 20);
      if ( v19 > *(_DWORD *)(*a1 + 16) )
        v19 = *(_DWORD *)(*a1 + 16);
      if ( v19 )
      {
        qmemcpy(*(void **)(v17 + 12), *(const void **)(v18 + 16), v19);
        v20 = *(_DWORD *)(v17 + 28);
        *(_DWORD *)(v17 + 12) += v19;
        *(_DWORD *)(v20 + 16) += v19;
        v21 = *(_DWORD *)(v17 + 16);
        v22 = *(_DWORD *)(v17 + 28);
        *(_DWORD *)(v17 + 20) += v19;
        *(_DWORD *)(v17 + 16) = v21 - v19;
        *(_DWORD *)(v22 + 20) -= v19;
        v23 = *(_DWORD **)(v17 + 28);
        if ( !v23[5] )
          v23[4] = v23[2];
      }
      if ( *(_DWORD *)(*a1 + 16) )
        continue;
    }
    return 0;
  }
  if ( !a2 )
    return 0;
  sub_62E530(*(int *)((char *)a1 + 98) - *(int *)((char *)a1 + 82), a2 == 4);
  v25 = *a1;
  *(int *)((char *)a1 + 82) = *(int *)((char *)a1 + 98);
  sub_62B1F0(v25);
  v26 = 0;
  if ( !*(_DWORD *)(*a1 + 16) )
    return a2 != 4 ? 0 : 2;
  LOBYTE(v26) = a2 == 4;
  return 2 * v26 + 1;
}
