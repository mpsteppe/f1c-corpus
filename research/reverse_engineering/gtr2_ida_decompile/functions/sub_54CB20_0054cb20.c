int __thiscall sub_54CB20(float *this, float a2)
{
  int result; // eax

  result = *((_DWORD *)this + 4);
  *((_DWORD *)this + 6) = result;
  this[4] = a2 * 0.60000002;
  return result;
}
