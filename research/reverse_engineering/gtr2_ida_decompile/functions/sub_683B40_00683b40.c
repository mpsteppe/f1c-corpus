BOOL __thiscall sub_683B40(_DWORD *this, int a2, int a3)
{
  return a2 == a3
      || (*(_DWORD *)(*(_DWORD *)(this[5] + 4 * a2) + 64) & *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a3) + 64)) != 0;
}
