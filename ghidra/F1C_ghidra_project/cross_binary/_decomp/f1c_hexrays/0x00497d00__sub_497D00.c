// f1c  0x00497d00  size=20
int __thiscall sub_497D00(int this, int a2)
{
  int result; // eax

  result = a2;
  *(_DWORD *)(this + 6312) = a2;
  *(_BYTE *)(this + 6380) = 1;
  return result;
}
