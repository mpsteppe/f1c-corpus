int __thiscall sub_415950(int this, __int16 a2, int a3)
{
  int result; // eax

  LOWORD(result) = a2;
  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 32) = 6;
  *(_DWORD *)(this + 36) = a3;
  return result;
}
