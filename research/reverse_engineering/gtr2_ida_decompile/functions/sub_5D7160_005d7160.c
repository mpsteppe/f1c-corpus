_DWORD *__thiscall sub_5D7160(int this, float *a2)
{
  _DWORD *v2; // edx
  _DWORD *result; // eax
  int v4; // edi
  double v5; // st7
  double v6; // st6

  v2 = (_DWORD *)(this + 20);
  result = a2 + 2;
  v4 = 3;
  do
  {
    *(v2 - 4) = *(result - 1);
    *v2 = *result;
    v2[4] = result[1];
    result += 4;
    ++v2;
    --v4;
  }
  while ( v4 );
  *(float *)(this + 52) = -(*(float *)(this + 4) * a2[13]
                          + *(float *)(this + 36) * a2[15]
                          + *(float *)(this + 20) * a2[14]);
  *(float *)(this + 56) = -(*(float *)(this + 8) * a2[13]
                          + *(float *)(this + 40) * a2[15]
                          + *(float *)(this + 24) * a2[14]);
  v5 = *(float *)(this + 12) * a2[13] + *(float *)(this + 44) * a2[15];
  v6 = *(float *)(this + 28) * a2[14];
  *(_DWORD *)(this + 64) = 1065353216;
  *(float *)(this + 60) = -(v5 + v6);
  return result;
}
