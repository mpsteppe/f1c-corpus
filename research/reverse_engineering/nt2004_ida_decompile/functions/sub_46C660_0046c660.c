int __thiscall sub_46C660(float *this, float *a2)
{
  int result; // eax
  double v3; // st7
  double v4; // st6
  double v5; // st5

  result = *(_DWORD *)this;
  v3 = *(float *)(*(_DWORD *)this + 93) - a2[4401];
  v4 = *(float *)(*(_DWORD *)this + 97) - a2[4402];
  v5 = *(float *)(*(_DWORD *)this + 101) - a2[4403];
  this[1] = v5 * v5 + v4 * v4 + v3 * v3;
  return result;
}
