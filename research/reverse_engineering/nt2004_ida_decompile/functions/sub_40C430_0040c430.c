int __thiscall sub_40C430(int *this, char a2)
{
  int result; // eax

  result = *this;
  *(_BYTE *)(result + 73) = a2;
  byte_762AF8 = a2;
  *(_DWORD *)(result + 80) = 0;
  *(_DWORD *)(result + 88) = 0;
  return result;
}
