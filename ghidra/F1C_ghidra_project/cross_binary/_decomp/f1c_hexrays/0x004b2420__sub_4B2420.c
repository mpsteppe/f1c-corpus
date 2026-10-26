// f1c  0x004b2420  size=89
float *__thiscall sub_4B2420(_DWORD *this, _DWORD *a2, float *a3)
{
  float *result; // eax

  *a2 = *this;
  a2[1] = this[1];
  a2[2] = this[2];
  result = a3;
  *a3 = (double)*((__int16 *)this + 6) * 0.00048828125;
  a3[1] = (double)*((__int16 *)this + 7) * 0.00048828125;
  a3[2] = (double)*((__int16 *)this + 8) * 0.00048828125;
  return result;
}
