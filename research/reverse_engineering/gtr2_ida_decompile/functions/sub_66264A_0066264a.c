int __thiscall sub_66264A(_DWORD *this, int a2)
{
  unsigned int v3; // edx
  _DWORD *v4; // ebx
  int v5; // ecx
  unsigned int v6; // eax
  int v7; // eax
  int v8; // eax
  int v10; // eax
  int v11; // edx
  _DWORD *v12; // ecx
  unsigned int v14; // [esp+18h] [ebp+8h]

  v3 = 0;
  v4 = this;
  if ( *(_DWORD *)(a2 + 20) && *(_DWORD *)(a2 + 40) && !*(_DWORD *)(a2 + 56) )
  {
    *(_DWORD *)(a2 + 52) = 0;
    v5 = 4 * *(_DWORD *)(a2 + 16);
    do
    {
      v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4[2] + 20) + 4 * *(_DWORD *)(v5 + v4[6])) + 112) + 1;
      if ( *(_DWORD *)(a2 + 52) < v6 )
        *(_DWORD *)(a2 + 52) = v6;
      ++v3;
      v5 += 4;
    }
    while ( v3 < *(_DWORD *)(a2 + 20) );
    v7 = sub_67EB7E(4 * *(_DWORD *)(a2 + 52), 0x10u);
    *(_DWORD *)(a2 + 56) = v7;
    if ( !v7 )
      return -2147024882;
    v8 = sub_67EB7E(4 * *(_DWORD *)(a2 + 20), 0x10u);
    *(_DWORD *)(a2 + 60) = v8;
    if ( !v8 )
      return -2147024882;
    v14 = 0;
    memset(*(void **)(a2 + 56), 0, 4 * *(_DWORD *)(a2 + 52));
    memset(*(void **)(a2 + 60), 0, 4 * *(_DWORD *)(a2 + 20));
    v10 = *(_DWORD *)(*(_DWORD *)(a2 + 40) + 32);
    if ( *(_DWORD *)(a2 + 20) )
    {
      do
      {
        if ( !v10 )
          break;
        v11 = v4[2];
        v12 = *(_DWORD **)(*(_DWORD *)(v11 + 20) + 4 * *(_DWORD *)(v4[6] + 4 * (v14 + *(_DWORD *)(a2 + 16))));
        if ( *(char *)(*(_DWORD *)(*(_DWORD *)(v11 + 16) + 4 * v12[1]) + 4) >= 0 )
        {
          *(_DWORD *)(*(_DWORD *)(a2 + 56) + 4 * v12[28]) = *(_DWORD *)(v10 + 8) + 16;
          v4 = this;
          *(_DWORD *)(*(_DWORD *)(a2 + 60) + 4 * v12[25]) = *(_DWORD *)(v10 + 8) + 16;
        }
        ++v14;
        v10 = *(_DWORD *)(v10 + 12);
      }
      while ( v14 < *(_DWORD *)(a2 + 20) );
    }
  }
  return 0;
}
