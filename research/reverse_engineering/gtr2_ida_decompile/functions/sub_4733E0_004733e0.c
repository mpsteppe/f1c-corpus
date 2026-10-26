int __thiscall sub_4733E0(_BYTE *this)
{
  int result; // eax

  result = 0;
  *(_DWORD *)this = 0;
  this[8] = 0;
  this[40] = 0;
  this[64] = 0;
  this[384] = 0;
  this[128] = 0;
  this[96] = 0;
  this[512] = -1;
  this[513] = 0;
  this[514] = -1;
  this[515] = -1;
  *((_WORD *)this + 258) = 0;
  *((_WORD *)this + 259) = 0;
  *((_WORD *)this + 260) = 0;
  *((_WORD *)this + 261) = 0;
  this[524] = 0;
  return result;
}
