int __thiscall sub_4AFAC0(_BYTE *this)
{
  int result; // eax

  result = 0;
  *(_DWORD *)this = 3;
  this[4] = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  return result;
}
