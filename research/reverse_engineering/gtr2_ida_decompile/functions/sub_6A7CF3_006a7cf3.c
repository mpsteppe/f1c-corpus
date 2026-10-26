int __thiscall sub_6A7CF3(
        _DWORD *this,
        int a2,
        unsigned int a3,
        unsigned int a4,
        int a5,
        unsigned int a6,
        int a7,
        unsigned int *a8)
{
  _DWORD *v9; // ecx
  unsigned int v10; // esi
  _DWORD *v11; // edx
  int v12; // ebx
  unsigned int v13; // eax
  int v14; // ecx
  int v15; // esi
  unsigned int v16; // edx
  unsigned int i; // edi
  unsigned int v19; // [esp+Ch] [ebp-20h]
  _DWORD *v20; // [esp+10h] [ebp-1Ch]
  unsigned int v21; // [esp+14h] [ebp-18h]
  unsigned int v22; // [esp+18h] [ebp-14h]
  unsigned int v24; // [esp+20h] [ebp-Ch]
  unsigned int v25; // [esp+24h] [ebp-8h]
  unsigned int v26; // [esp+24h] [ebp-8h]
  int v27; // [esp+28h] [ebp-4h]
  int v28; // [esp+28h] [ebp-4h]
  int v29; // [esp+38h] [ebp+Ch]

  while ( 1 )
  {
    v21 = a3;
    if ( a3 >= a4 )
      return 0;
    v9 = *(_DWORD **)(a2 + 4 * a3);
    v20 = v9;
    if ( v9 )
    {
      v10 = *v9 & 0xFFFFF;
      v22 = v10;
      if ( *v9 )
      {
        v24 = 0;
        v19 = v9[1] / v10;
        if ( v19 )
          break;
      }
    }
LABEL_29:
    a3 = v21 + 1;
  }
  v29 = 0;
  while ( 1 )
  {
    v27 = 0;
    if ( v10 )
      break;
LABEL_28:
    ++v24;
    v29 += 4 * v10;
    if ( v24 >= v19 )
      goto LABEL_29;
  }
  v11 = (_DWORD *)(v29 + v9[2]);
  v25 = v10;
  do
  {
    v12 = *(_DWORD *)(this[5] + 4 * *v11);
    v13 = 0;
    if ( a6 )
    {
      do
      {
        v14 = *(_DWORD *)(a5 + 4 * v13);
        if ( (*v11 == v14 || *(_DWORD *)(v12 + 56) == v14) && *(_DWORD *)(v12 + 12) == -1 )
          v27 = 1;
        ++v13;
      }
      while ( v13 < a6 );
      v9 = v20;
    }
    ++v11;
    --v25;
  }
  while ( v25 );
  if ( !v27 )
  {
LABEL_27:
    v10 = v22;
    goto LABEL_28;
  }
  v26 = 0;
  v28 = v29;
  while ( 1 )
  {
    v15 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v28 + v9[2])) + 56);
    if ( v15 == -1 )
      v15 = *(_DWORD *)(v28 + v9[2]);
    v16 = *a8;
    for ( i = 0; i < *a8; ++i )
    {
      if ( *(_DWORD *)(a7 + 4 * i) == v15 )
        break;
    }
    if ( i != v16 )
      goto LABEL_26;
    if ( i == 32 )
      break;
    *(_DWORD *)(a7 + 4 * v16) = v15;
    ++*a8;
LABEL_26:
    ++v26;
    v28 += 4;
    if ( v26 >= v22 )
      goto LABEL_27;
  }
  sub_686791((int)this, 0, 4803, "internal error: arguments not vectorized");
  return -2147467259;
}
