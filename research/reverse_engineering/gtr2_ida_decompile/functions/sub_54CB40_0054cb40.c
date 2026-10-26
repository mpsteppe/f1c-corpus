int __thiscall sub_54CB40(float *this, float a2)
{
  int result; // eax

  result = *((_DWORD *)this + 5);
  *((_DWORD *)this + 7) = result;
  this[5] = a2 * 0.60000002;
  return result;
}
