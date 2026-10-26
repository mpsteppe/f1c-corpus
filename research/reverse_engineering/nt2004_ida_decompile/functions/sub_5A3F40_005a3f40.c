int __thiscall sub_5A3F40(_DWORD *this, char a2, char a3)
{
  int result; // eax

  result = a2 & 0x20;
  this[39] = result;
  this[40] = a3 & 0xC0;
  return result;
}
