int __thiscall sub_4DA4D0(_DWORD *this, char a2)
{
  int result; // eax

  result = this[2];
  *(_BYTE *)(result + 2140) = a2;
  return result;
}
