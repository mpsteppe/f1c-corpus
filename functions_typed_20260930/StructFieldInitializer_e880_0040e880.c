char __thiscall sub_40E880(int this, __int16 a2, int a3)
{
  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 28) = 7;
  *(_DWORD *)(this + 32) = a3;
  return ShortComputation_e770((_DWORD *)this, a3, 0);
}

