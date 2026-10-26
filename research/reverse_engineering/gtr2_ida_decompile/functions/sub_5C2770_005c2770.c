_DWORD *__thiscall sub_5C2770(_DWORD *this, float *a2, float *a3)
{
  _DWORD *result; // eax
  double v4; // st7
  double v5; // st6
  float v6; // [esp+8h] [ebp-8h]
  float v7; // [esp+Ch] [ebp-4h]
  float v8; // [esp+Ch] [ebp-4h]
  float v9; // [esp+14h] [ebp+4h]

  result = this;
  *this = *(_DWORD *)a2;
  this[1] = *((_DWORD *)a2 + 1);
  this[2] = *((_DWORD *)a2 + 2);
  this[3] = *(_DWORD *)a3;
  this[4] = *((_DWORD *)a3 + 1);
  this[5] = *((_DWORD *)a3 + 2);
  v4 = *a3 - *a2;
  v6 = a3[1] - a2[1];
  v5 = a3[2] - a2[2];
  v7 = v5;
  v9 = 1.0 / sqrt(v5 * v7 + v6 * v6 + v4 * v4);
  v8 = v7 * v9;
  *((float *)this + 8) = v8;
  *((float *)this + 6) = v4 * v9;
  *((float *)this + 7) = v6 * v9;
  return result;
}
