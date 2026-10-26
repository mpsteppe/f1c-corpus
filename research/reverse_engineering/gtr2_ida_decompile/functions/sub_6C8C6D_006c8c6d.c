int __thiscall sub_6C8C6D(_DWORD *this)
{
  int v2; // eax
  int *v4; // eax
  int *v5; // edi
  int v6; // [esp+8h] [ebp-4h]

  v6 = 1;
  if ( (*(_DWORD *)this[64] & 0xFFF00000) == 0x20500000 )
  {
    v2 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 4 * (*(_DWORD *)this[64] & 0xFFFFF)));
    if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v2 + 4)) + 5) & 1) == 0 || *(double *)(v2 + 32) != -1.0 )
      return 1;
  }
  v4 = sub_6C5028(this, *(_DWORD *)this[64] & 0xFFFFF | 0x20400000, this[64], 0, 2, 1);
  v5 = v4;
  if ( v4 )
  {
    v6 = sub_6C8AE5(this, v4);
    if ( !v6 )
      *v5 = 0;
  }
  return v6;
}
