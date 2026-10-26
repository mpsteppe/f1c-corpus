int __thiscall sub_5D7330(int this, float a2, float a3, float a4)
{
  int result; // eax
  bool v5; // zf
  double v6; // st7
  double v7; // st6

  *(float *)(this + 72) = a2;
  result = LODWORD(a4);
  *(float *)(this + 80) = a4;
  v5 = *(_DWORD *)(this + 68) == 2;
  *(float *)(this + 76) = a3;
  if ( v5 )
  {
    *(float *)(this + 52) = a2;
    result = *(_DWORD *)(this + 76);
    *(_DWORD *)(this + 56) = result;
    *(_DWORD *)(this + 60) = *(_DWORD *)(this + 80);
    *(_DWORD *)(this + 64) = 1065353216;
  }
  else
  {
    *(float *)(this + 52) = a3 * *(float *)(this + 20) + a2 * *(float *)(this + 4) + a4 * *(float *)(this + 36);
    *(float *)(this + 56) = *(float *)(this + 40) * *(float *)(this + 80)
                          + *(float *)(this + 24) * *(float *)(this + 76)
                          + *(float *)(this + 8) * *(float *)(this + 72);
    v6 = *(float *)(this + 44) * *(float *)(this + 80) + *(float *)(this + 28) * *(float *)(this + 76);
    v7 = *(float *)(this + 12) * *(float *)(this + 72);
    *(_DWORD *)(this + 64) = 1065353216;
    *(float *)(this + 60) = v6 + v7;
  }
  return result;
}
