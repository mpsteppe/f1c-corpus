unsigned int __usercall sub_62B790@<eax>(int *a1@<ebx>)
{
  unsigned int result; // eax
  unsigned int v2; // ecx
  int v3; // esi
  unsigned int v4; // edx
  unsigned int v5; // esi
  unsigned int v6; // ecx
  int v7; // edi
  int v8; // ecx
  _WORD *v9; // esi
  unsigned int v10; // ecx
  __int16 v11; // cx
  unsigned int v12; // edi
  _WORD *v13; // esi
  unsigned int v14; // ecx
  __int16 v15; // cx
  int v16; // ebp
  void *v17; // edi
  unsigned int v18; // esi
  unsigned int v19; // ecx
  int v20; // edx
  int v21; // edx
  unsigned int v22; // edi
  unsigned __int8 *v23; // esi
  int v24; // edx
  int v25; // ecx
  unsigned int v26; // [esp+Ch] [ebp-8h]
  unsigned int v27; // [esp+10h] [ebp-4h]

  result = *(int *)((char *)a1 + 34);
  v27 = result;
  do
  {
    v2 = *(int *)((char *)a1 + 98);
    v3 = *(int *)((char *)a1 + 106);
    v4 = *(int *)((char *)a1 + 50) - v2 - v3;
    if ( v4 )
    {
      if ( v4 == -1 )
      {
        v4 = -2;
        goto LABEL_20;
      }
    }
    else if ( !v2 && !v3 )
    {
      v4 = result;
      goto LABEL_20;
    }
    if ( v2 >= result + *(int *)((char *)a1 + 34) - 262 )
    {
      qmemcpy(*(void **)((char *)a1 + 46), (const void *)(*(int *)((char *)a1 + 46) + result), result);
      v5 = *(int *)((char *)a1 + 98) - result;
      v6 = *(int *)((char *)a1 + 82) - result;
      *(int *)((char *)a1 + 102) -= result;
      v7 = *(int *)((char *)a1 + 66);
      *(int *)((char *)a1 + 82) = v6;
      v8 = *(int *)((char *)a1 + 58);
      *(int *)((char *)a1 + 98) = v5;
      v9 = (_WORD *)(v8 + 2 * v7);
      do
      {
        v10 = (unsigned __int16)*--v9;
        if ( v10 < result )
          v11 = 0;
        else
          v11 = v10 - result;
        --v7;
        *v9 = v11;
      }
      while ( v7 );
      v12 = result;
      v13 = (_WORD *)(*(int *)((char *)a1 + 54) + 2 * result);
      do
      {
        v14 = (unsigned __int16)*--v13;
        if ( v14 < result )
          v15 = 0;
        else
          v15 = v14 - result;
        --v12;
        *v13 = v15;
      }
      while ( v12 );
      v4 += result;
    }
LABEL_20:
    v16 = *a1;
    if ( !*(_DWORD *)(*a1 + 4) )
      break;
    v17 = (void *)(*(int *)((char *)a1 + 46) + *(int *)((char *)a1 + 98) + *(int *)((char *)a1 + 106));
    v18 = *(_DWORD *)(v16 + 4);
    v26 = v18;
    if ( v18 > v4 )
    {
      v26 = v4;
      v18 = v4;
    }
    if ( v18 )
    {
      v20 = *(_DWORD *)(v16 + 28);
      *(_DWORD *)(v16 + 4) -= v18;
      if ( !*(_DWORD *)(v20 + 24) )
      {
        *(_DWORD *)(v16 + 48) = sub_62CC00(v18);
        result = v27;
      }
      qmemcpy(v17, *(const void **)v16, v18);
      v19 = v26;
      v21 = *(_DWORD *)(v16 + 8);
      *(_DWORD *)v16 += v26;
      *(_DWORD *)(v16 + 8) = v26 + v21;
    }
    else
    {
      v19 = 0;
    }
    v22 = v19 + *(int *)((char *)a1 + 106);
    *(int *)((char *)a1 + 106) = v22;
    if ( v22 >= 3 )
    {
      v23 = (unsigned __int8 *)(*(int *)((char *)a1 + 98) + *(int *)((char *)a1 + 46));
      v24 = *v23;
      v25 = *(int *)((char *)a1 + 78);
      *(int *)((char *)a1 + 62) = v24;
      *(int *)((char *)a1 + 62) = *(int *)((char *)a1 + 74) & (v23[1] ^ (v24 << v25));
    }
  }
  while ( v22 < 0x106 && *(_DWORD *)(*a1 + 4) );
  return result;
}
