unsigned int __thiscall sub_4D1890(float *this)
{
  unsigned int result; // eax

  sub_4CFD80(this + 2);
  result = *(_DWORD *)this & 0xFFFF003F | 0xA00;
  *(_DWORD *)this = result;
  return result;
}
