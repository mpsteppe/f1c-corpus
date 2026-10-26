int __thiscall sub_6A4BC7(_DWORD *this, int a2, unsigned int a3)
{
  _DWORD *v3; // edi
  unsigned int v4; // edx
  _DWORD *v5; // eax
  unsigned int j; // ecx
  int v7; // esi
  unsigned int k; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  _DWORD *v12; // ebx
  unsigned int v13; // esi
  bool v14; // zf
  int v15; // eax
  unsigned int m; // ecx
  int result; // eax
  int v18; // eax
  void *v19; // edi
  unsigned int v20; // eax
  _DWORD v21[256]; // [esp+Ch] [ebp-410h] BYREF
  _DWORD *i; // [esp+40Ch] [ebp-10h]
  unsigned int v23; // [esp+410h] [ebp-Ch]
  int v24; // [esp+414h] [ebp-8h]
  int v25; // [esp+418h] [ebp-4h]

  v3 = this;
  v4 = 0;
  for ( i = this; v4 < a3; ++v4 )
  {
    v5 = *(_DWORD **)(a2 + 4 * v4);
    if ( v5 )
    {
      for ( j = 0; j < v5[3]; *(_DWORD *)(v7 + 72) = v4 )
        v7 = *(_DWORD *)(v3[5] + 4 * *(_DWORD *)(v5[4] + 4 * j++));
      v5[7] = 0;
      v5[5] = 0;
    }
  }
  for ( k = 0; k < v3[2]; ++k )
  {
    v9 = v3[5];
    v10 = *(_DWORD *)(v9 + 4 * k);
    v11 = *(_DWORD *)(v10 + 56);
    if ( v11 != -1 )
      *(_DWORD *)(v10 + 72) = *(_DWORD *)(*(_DWORD *)(v9 + 4 * v11) + 72);
  }
  v25 = 0;
  if ( !a3 )
    return 0;
  while ( 1 )
  {
    v12 = *(_DWORD **)(a2 + 4 * v25);
    v13 = 0;
    if ( !v12 )
      goto LABEL_24;
    v14 = v12[1] == 0;
    v23 = 0;
    v24 = 0;
    if ( !v14 )
      break;
LABEL_22:
    v18 = sub_681169(v13);
    v12[6] = v18;
    if ( !v18 )
      return -2147024882;
    v19 = (void *)v18;
    v20 = v23;
    qmemcpy(v19, v21, 4 * v13);
    v3 = i;
    v12[5] = v20;
LABEL_24:
    if ( ++v25 >= a3 )
      return 0;
  }
  while ( 1 )
  {
    v15 = *(_DWORD *)(*(_DWORD *)(v3[5] + 4 * *(_DWORD *)(v12[2] + 4 * v24)) + 72);
    if ( v15 != -1 )
    {
      for ( m = 0; m < v13; ++m )
      {
        if ( v21[m] == v15 )
          break;
      }
      if ( m == v13 )
      {
        v21[v13++] = v15;
        v23 = v13;
      }
      result = sub_6A4B6D(*(_DWORD *)(a2 + 4 * v15), v25);
      if ( result < 0 )
        return result;
    }
    if ( (unsigned int)++v24 >= v12[1] )
      goto LABEL_22;
  }
}
