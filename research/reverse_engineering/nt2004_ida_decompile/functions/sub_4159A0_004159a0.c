int __thiscall sub_4159A0(int this, __int16 a2, int a3)
{
  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 32) = 8;
  *(_DWORD *)(this + 36) = a3;
  sub_415570(a3, (float *)(this + 16), (float *)(this + 28));
  return sub_4E09C0(this);
}
