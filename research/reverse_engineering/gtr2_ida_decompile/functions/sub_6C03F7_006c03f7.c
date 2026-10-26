int __thiscall sub_6C03F7(_DWORD *this)
{
  _DWORD *v2; // eax
  int result; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  _DWORD *v7; // ebx
  int v8; // edi
  int v9; // [esp+14h] [ebp-4h]

  v2 = (_DWORD *)this[64];
  if ( (*v2 & 0xFFFFF) != 1 )
    return 1;
  v4 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v2[2] + 4));
  if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v4 + 4)) + 5) & 1) == 0
    || *(_DWORD *)(v4 + 8) != -1
    || *(double *)(v4 + 32) != 0.0 )
  {
    return 1;
  }
  v5 = sub_681AAA(this, 0, 0, 0, 0.0);
  v9 = v5;
  if ( v5 == -1 )
    return -2147024882;
  v6 = this[5];
  v7 = *(_DWORD **)(v6 + 4 * **(_DWORD **)(this[64] + 8));
  v8 = *(_DWORD *)(v6 + 4 * v5);
  result = sub_6815D6((double *)v8, (int)v7);
  if ( result >= 0 )
  {
    result = sub_681692((_DWORD *)v8, v7);
    if ( result >= 0 )
    {
      *(_DWORD *)(v8 + 60) ^= 0x80000u;
      if ( *(_DWORD *)(v8 + 56) == -1 )
        *(_DWORD *)(v8 + 56) = **(_DWORD **)(this[64] + 8);
      *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 4) = v9;
      return 0;
    }
  }
  return result;
}
