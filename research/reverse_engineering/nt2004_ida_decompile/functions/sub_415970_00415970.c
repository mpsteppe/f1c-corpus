char __thiscall sub_415970(int this, __int16 a2, int a3)
{
  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 32) = 7;
  *(_DWORD *)(this + 36) = a3;
  return sub_415860((_DWORD *)this, a3, 0);
}
