int __thiscall sub_4B4F70(char *this)
{
  int result; // eax

  sub_4FFFA0(this + 144);
  *this = 0;
  this[1] = 0;
  this[65] = 0;
  this[97] = 0;
  result = -190986834;
  *((_DWORD *)this + 33) = -190986834;
  *((_DWORD *)this + 34) = -190986834;
  *((_DWORD *)this + 35) = -190986834;
  return result;
}
