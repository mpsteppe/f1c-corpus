int __thiscall sub_40E860(int this, __int16 a2, int a3)
{
  int result; // eax

  LOWORD(result) = a2;
  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 28) = 6;
  *(_DWORD *)(this + 32) = a3;
  return result;
}

