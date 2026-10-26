char __thiscall sub_6183D0(int this, int a2, _DWORD *a3)
{
  int v4; // ecx

  sub_6180A0(this, a2);
  sub_6182E0(this);
  *(_WORD *)(*(_DWORD *)(this + 8) + 4 * *(_DWORD *)(this + 20)) = *(_WORD *)(this + 16);
  *(_WORD *)(*(_DWORD *)(this + 8) + 4 * *(_DWORD *)(this + 20) + 2) = a2;
  sub_618040((_DWORD *)this, *(unsigned __int16 *)(*(_DWORD *)(this + 8) + 4 * *(_DWORD *)(this + 20)), a2);
  *a3 = *(_DWORD *)(this + 20);
  v4 = *(_DWORD *)(this + 16);
  ++*(_DWORD *)(this + 20);
  *(_DWORD *)(this + 16) = a2 + v4;
  return 1;
}
