int __stdcall sub_6D4F30(int *a1, int a2)
{
  int *v2; // edx
  int v3; // ebx
  int v4; // esi
  int v5; // ecx
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int *v11; // [esp+Ch] [ebp-4h]

  v2 = a1;
  v3 = a1[50];
  v4 = a1[93];
  if ( v3 )
  {
    if ( !*(_DWORD *)(v4 + 36) )
    {
      v5 = a1[63];
      if ( v5 > 0 )
        memset((void *)(v4 + 20), 0, 4 * v5);
      *(_DWORD *)(v4 + 36) = v3;
    }
    --*(_DWORD *)(v4 + 36);
  }
  v6 = 0;
  if ( a1[70] > 0 )
  {
    v11 = a1 + 71;
    while ( 1 )
    {
      v7 = *v11;
      v8 = v2[*v11 + 64];
      sub_6D4E50(
        *(_DWORD *)(v4 + 4 * *(_DWORD *)(v8 + 20) + 76),
        *(_DWORD *)(v4 + 4 * *v11 + 20),
        v2,
        *(__int16 **)(a2 + 4 * v6),
        *(_DWORD **)(v4 + 4 * *(_DWORD *)(v8 + 24) + 92));
      v9 = a1[70];
      *(_DWORD *)(v4 + 4 * v7 + 20) = **(__int16 **)(a2 + 4 * v6++);
      ++v11;
      if ( v6 >= v9 )
        break;
      v2 = a1;
    }
  }
  return 1;
}
