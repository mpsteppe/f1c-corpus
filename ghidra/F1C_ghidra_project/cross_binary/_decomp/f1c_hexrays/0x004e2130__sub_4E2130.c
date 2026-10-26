// f1c  0x004e2130  size=156
_DWORD *__thiscall sub_4E2130(float *this, float *a2, _DWORD *a3)
{
  double v3; // st7
  float *v4; // ecx
  _DWORD *result; // eax

  v3 = this[10] * this[584];
  v4 = this + 5;
  *a2 = v3 + v4[4] * v4[578] + v4[577] * v4[3];
  a2[1] = v4[8] * v4[579] + v4[7] * v4[578] + v4[6] * v4[577];
  a2[2] = v4[11] * v4[579] + v4[10] * v4[578] + v4[9] * v4[577];
  *a2 = *(v4 - 3) + *a2;
  a2[1] = *(v4 - 2) + a2[1];
  a2[2] = *(v4 - 1) + a2[2];
  result = a3;
  *a3 = *(_DWORD *)v4;
  a3[1] = *((_DWORD *)v4 + 1);
  a3[2] = *((_DWORD *)v4 + 2);
  return result;
}
