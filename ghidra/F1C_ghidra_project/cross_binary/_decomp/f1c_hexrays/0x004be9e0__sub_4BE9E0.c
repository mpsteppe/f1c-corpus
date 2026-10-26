// f1c  0x004be9e0  size=43
int __thiscall sub_4BE9E0(int this, char a2, char a3, int a4, int a5)
{
  int result; // eax

  *(_BYTE *)(this + 832) = a2;
  result = a4;
  *(_BYTE *)(this + 833) = a3;
  *(_DWORD *)(this + 836) = a4;
  *(_DWORD *)(this + 848) = a5;
  return result;
}
