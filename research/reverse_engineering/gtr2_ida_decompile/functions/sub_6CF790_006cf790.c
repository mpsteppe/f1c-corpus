int __stdcall sub_6CF790(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v7; // edx
  int v8; // eax
  int v9; // esi
  int v10; // ebx
  int v11; // esi
  int v12; // ecx
  int *v14; // edi
  int v15; // eax
  int v16; // [esp+8h] [ebp-4h]

  v5 = a3;
  v16 = a5;
  if ( a3 >= a5 )
  {
    v7 = a2;
  }
  else
  {
    if ( !sub_6CF670((unsigned __int8 **)a1, a2, a3, a5) )
      return -1;
    v7 = *(_DWORD *)(a1 + 8);
    v5 = *(_DWORD *)(a1 + 12);
  }
  v8 = v5 - a5;
  v9 = ((1 << a5) - 1) & (v7 >> v8);
  v10 = a4;
  if ( v9 > *(_DWORD *)(a4 + 4 * a5) )
  {
    while ( 1 )
    {
      v11 = 2 * v9;
      if ( v8 < 1 )
      {
        if ( !sub_6CF670((unsigned __int8 **)a1, v7, v8, 1) )
          return -1;
        v7 = *(_DWORD *)(a1 + 8);
        v8 = *(_DWORD *)(a1 + 12);
      }
      v9 = (v7 >> --v8) & 1 | v11;
      v10 = a4;
      v12 = v16 + 1;
      if ( v9 <= *(_DWORD *)(a4 + 4 * ++v16) )
        goto LABEL_14;
    }
  }
  v12 = a5;
LABEL_14:
  *(_DWORD *)(a1 + 8) = v7;
  *(_DWORD *)(a1 + 12) = v8;
  if ( v12 <= 16 )
    return *(unsigned __int8 *)(*(_DWORD *)(v10 + 140) + *(_DWORD *)(v10 + 4 * v12 + 72) + v9 + 17);
  v14 = *(int **)(a1 + 16);
  v15 = *v14;
  *(_DWORD *)(v15 + 20) = 118;
  (*(void (__stdcall **)(int *, int))(v15 + 4))(v14, -1);
  return 0;
}
