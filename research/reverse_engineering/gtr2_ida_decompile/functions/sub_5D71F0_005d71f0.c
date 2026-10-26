_DWORD *__thiscall sub_5D71F0(float *this, int a2)
{
  _DWORD *v2; // edx
  _DWORD *result; // eax
  int v4; // esi
  double v5; // st7
  double v6; // st6

  v2 = (_DWORD *)(a2 + 32);
  result = this + 2;
  v4 = 3;
  do
  {
    *(v2 - 8) = *(result - 1);
    *(v2 - 4) = *result;
    *v2 = result[1];
    result += 4;
    ++v2;
    --v4;
  }
  while ( v4 );
  *(float *)(a2 + 48) = -(this[9] * this[15] + this[5] * this[14] + this[1] * this[13]);
  *(float *)(a2 + 52) = -(this[10] * this[15] + this[6] * this[14] + this[13] * this[2]);
  v5 = this[11] * this[15] + this[7] * this[14];
  v6 = this[3] * this[13];
  *(_DWORD *)(a2 + 60) = 1065353216;
  *(float *)(a2 + 56) = -(v5 + v6);
  return result;
}
