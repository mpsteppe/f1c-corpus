int __thiscall sub_552FD0(_DWORD *this, char a2, char a3)
{
  int result; // eax

  result = a2 & 0x20;
  this[19] = result;
  this[20] = a3 & 0xC0;
  return result;
}

