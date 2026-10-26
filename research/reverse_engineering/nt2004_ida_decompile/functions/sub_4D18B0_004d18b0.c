unsigned int __thiscall sub_4D18B0(unsigned int *this)
{
  unsigned int result; // eax

  sub_4CFDE0(this + 2);
  result = *this & 0xFFFF003F | 0xD00;
  *this = result;
  return result;
}
