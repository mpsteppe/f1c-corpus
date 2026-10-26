// f1c  0x004ba140  size=16
int __thiscall sub_4BA140(_DWORD *this, char a2)
{
  int result; // eax

  result = this[2];
  *(_BYTE *)(result + 3960) = a2;
  return result;
}
