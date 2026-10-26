int __thiscall sub_6CBC33(_DWORD *this)
{
  int v1; // edx

  v1 = this[64];
  return sub_6CB29C(
           this,
           90,
           *(_DWORD **)(v1 + 16),
           *(_DWORD *)(v1 + 12),
           *(_DWORD **)(v1 + 8),
           (_DWORD *)(*(_DWORD *)(v1 + 8) + 4 * (*(_DWORD *)v1 & 0xFFFFF)),
           (_DWORD *)(*(_DWORD *)(v1 + 8) + 8 * (*(_DWORD *)v1 & 0xFFFFF)),
           *(_DWORD *)v1 & 0xFFFFF,
           0,
           0,
           0,
           0);
}
