int __thiscall sub_5DB150(_DWORD *this, float a2, float a3, float a4)
{
  int result; // eax

  result = sub_5D7330((int)(this + 18), a2, a3, a4);
  *this |= 0x40u;
  return result;
}
