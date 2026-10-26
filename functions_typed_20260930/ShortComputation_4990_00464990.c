int __thiscall sub_464990(float *this, float *a2)
{
  int result; // eax
  double v3; // st7
  double v4; // st6
  double v5; // st5

  result = *(_DWORD *)this;
  v3 = *(float *)(*(_DWORD *)this + 117) - a2[3384];
  v4 = *(float *)(*(_DWORD *)this + 121) - a2[3385];
  v5 = *(float *)(*(_DWORD *)this + 125) - a2[3386];
  this[1] = v5 * v5 + v4 * v4 + v3 * v3;
  return result;
}

