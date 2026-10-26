int __thiscall sub_543870(int this, __int16 a2, __int16 a3, __int16 a4)
{
  int result; // eax

  *(_WORD *)(this + 396) = a2;
  *(_WORD *)(this + 392) = a4;
  result = *(_DWORD *)(this + 236) | 0x10000;
  *(_WORD *)(this + 394) = a3;
  *(_DWORD *)(this + 236) = result;
  return result;
}
