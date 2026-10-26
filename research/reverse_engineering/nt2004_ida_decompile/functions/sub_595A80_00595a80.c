int __thiscall sub_595A80(int this, __int16 a2, __int16 a3, __int16 a4)
{
  int result; // eax

  *(_WORD *)(this + 412) = a2;
  *(_WORD *)(this + 408) = a4;
  result = *(_DWORD *)(this + 240) | 0x10000;
  *(_WORD *)(this + 410) = a3;
  *(_DWORD *)(this + 240) = result;
  return result;
}
