bool __thiscall sub_617210(int this, int a2, int a3)
{
  bool result; // al

  (*(void (__thiscall **)(int, int))(*(_DWORD *)(this + 96) + 4))(this + 96, a3);
  *(_BYTE *)(this + 132) = 0;
  result = sub_614460((_DWORD *)this, a2, 0);
  *(_BYTE *)(this + 92) = *(_BYTE *)(this + 88) && *(_DWORD *)(this + 68) == a3;
  return result;
}
