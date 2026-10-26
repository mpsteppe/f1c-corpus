int __thiscall sub_4CB5A0(_DWORD *this, _DWORD *a2)
{
  int v2; // edx
  int v3; // esi

  v2 = this[26];
  v3 = this[25] - 1;
  this[25] = v3;
  *(_DWORD *)(v2 + 4 * a2[1]) = *(_DWORD *)(v2 + 4 * v3);
  *(_DWORD *)(*(_DWORD *)(this[26] + 4 * a2[1]) + 4) = a2[1];
  a2[1] = -1;
  return sub_558B30(*a2);
}
