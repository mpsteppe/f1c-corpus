int __cdecl sub_51A87E(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v7; // edx
  int v8; // eax
  int v9; // esi
  int v10; // ebx
  int v11; // esi
  int v12; // [esp+8h] [ebp-4h]
  int *v13; // [esp+24h] [ebp+18h]

  v5 = a3;
  v12 = a5;
  if ( a3 >= a5 )
  {
    v7 = a2;
  }
  else
  {
    if ( !sub_51A794((unsigned __int8 **)a1, a2, a3, a5) )
      return -1;
    v7 = *(_DWORD *)(a1 + 12);
    v5 = *(_DWORD *)(a1 + 24);
  }
  v8 = v5 - a5;
  v9 = ((1 << a5) - 1) & (v7 >> v8);
  v10 = a4;
  if ( v9 > *(_DWORD *)(a4 + 4 * a5 + 68) )
  {
    v13 = (int *)(a4 + 4 * a5 + 68);
    while ( 1 )
    {
      v11 = 2 * v9;
      if ( v8 < 1 )
      {
        if ( !sub_51A794((unsigned __int8 **)a1, v7, v8, 1) )
          return -1;
        v7 = *(_DWORD *)(a1 + 12);
        v8 = *(_DWORD *)(a1 + 24);
      }
      ++v13;
      v9 = (v7 >> --v8) & 1 | v11;
      ++v12;
      if ( v9 <= *v13 )
      {
        v10 = a4;
        break;
      }
    }
  }
  *(_DWORD *)(a1 + 24) = v8;
  *(_DWORD *)(a1 + 12) = v7;
  if ( v12 <= 16 )
    return *(unsigned __int8 *)(*(_DWORD *)(v10 + 208)
                              + *(_DWORD *)(v10 + 4 * v12 + 140)
                              - *(_DWORD *)(v10 + 4 * v12)
                              + v9
                              + 17);
  *(_DWORD *)(**(_DWORD **)(a1 + 28) + 20) = 114;
  (*(void (__cdecl **)(_DWORD, int))(**(_DWORD **)(a1 + 28) + 4))(*(_DWORD *)(a1 + 28), -1);
  return 0;
}
