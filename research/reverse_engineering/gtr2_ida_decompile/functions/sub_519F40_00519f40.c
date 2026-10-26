int __thiscall sub_519F40(unsigned __int16 *this, _DWORD *a2, int *a3, float *a4, float *a5)
{
  int result; // eax

  *a2 = *((unsigned __int8 *)this + 2);
  *a3 = *this >> 14;
  *a4 = (double)((*this >> 9) & 0x1F) * 0.032258064;
  result = *this & 0x1FF;
  *a5 = (double)result * 0.0073385518 + 0.25;
  return result;
}
