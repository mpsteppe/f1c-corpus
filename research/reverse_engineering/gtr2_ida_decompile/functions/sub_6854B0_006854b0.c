BOOL __thiscall sub_6854B0(_DWORD *this, int a2, int a3)
{
  return *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a2) + 4) == *(_DWORD *)(*(_DWORD *)(4 * a3 + this[5]) + 4)
      && *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a2) + 8) == *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a3) + 8)
      && *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a2) + 12) == *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a3) + 12);
}
