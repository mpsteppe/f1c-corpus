int __thiscall sub_4F2B40(_DWORD *this, _DWORD *a2)
{
  int v2; // edx
  int v3; // esi

  v2 = this[28];
  v3 = this[27] - 1;
  this[27] = v3;
  *(_DWORD *)(v2 + 4 * a2[1]) = *(_DWORD *)(v2 + 4 * v3);
  *(_DWORD *)(*(_DWORD *)(this[28] + 4 * a2[1]) + 4) = a2[1];
  a2[1] = -1;
  return sub_5B0A10(*a2);
}
