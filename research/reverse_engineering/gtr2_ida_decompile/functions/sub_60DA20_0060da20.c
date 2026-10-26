_WORD *__stdcall sub_60DA20(int a1, char a2, char a3)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  _WORD *result; // eax
  void *v7; // eax
  _WORD *v8; // edx
  int v9; // ecx
  int v10; // [esp+8h] [ebp-4h]

  v3 = 0;
  v10 = 0;
  if ( a3 )
  {
    v3 = *(_DWORD *)(a1 + 52);
    v10 = *(_DWORD *)(a1 + 56);
  }
  v4 = *(_DWORD *)(a1 + 44);
  if ( *(char *)v4 < 0 )
  {
    v5 = *(_DWORD *)(v4 + 24);
    if ( v5 == 4096 )
    {
      sub_5D70A0((void *)(*(_DWORD *)(v4 + 76) + (v3 << 6)), *(const void **)(a1 + 32), *(_DWORD *)(a1 + 8) << 6);
    }
    else if ( v5 == 0x8000 )
    {
      sub_5D70A0((void *)(*(_DWORD *)(v4 + 76) + 88 * v3), *(const void **)(a1 + 32), 88 * *(_DWORD *)(a1 + 8));
    }
    else
    {
      if ( (*(_BYTE *)a1 & 1) != 0 )
        qmemcpy((void *)(*(_DWORD *)(v4 + 56) + 32 * v3), *(const void **)(a1 + 12), 32 * *(_DWORD *)(a1 + 8));
      if ( (*(_BYTE *)a1 & 2) != 0 )
        qmemcpy(
          (void *)(*(_DWORD *)(*(_DWORD *)(a1 + 44) + 60) + 16 * v3),
          *(const void **)(a1 + 16),
          16 * *(_DWORD *)(a1 + 8));
      if ( (*(_BYTE *)a1 & 4) != 0 )
        qmemcpy(
          (void *)(*(_DWORD *)(*(_DWORD *)(a1 + 44) + 64) + 24 * v3),
          *(const void **)(a1 + 28),
          24 * *(_DWORD *)(a1 + 8));
      if ( (*(_BYTE *)a1 & 0x10) != 0 )
        qmemcpy(
          (void *)(*(_DWORD *)(*(_DWORD *)(a1 + 44) + 68) + 32 * v3),
          *(const void **)(a1 + 20),
          32 * *(_DWORD *)(a1 + 8));
      if ( (*(_BYTE *)a1 & 0x20) != 0 )
        qmemcpy(
          (void *)(*(_DWORD *)(*(_DWORD *)(a1 + 44) + 72) + 32 * v3),
          *(const void **)(a1 + 24),
          32 * *(_DWORD *)(a1 + 8));
    }
  }
  result = *(_WORD **)a1;
  if ( (*(_DWORD *)a1 & 0x4000) != 0 )
  {
    result = *(_WORD **)(a1 + 48);
    if ( *(char *)result < 0 )
    {
      v7 = (void *)(*((_DWORD *)result + 8) + 2 * v10);
      v8 = *(_WORD **)(a1 + 40);
      v9 = *(_DWORD *)(a1 + 36);
      if ( a2 )
        return sub_5D70D0((int)v7, v8, 2 * v9, 0);
      else
        return (_WORD *)sub_5D70A0(v7, v8, 2 * v9);
    }
  }
  return result;
}
