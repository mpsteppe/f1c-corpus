double __thiscall sub_552900(int this)
{
  char v3; // al
  double v4; // st7
  float v5; // [esp+4h] [ebp-4h]

  if ( 0.0 == dbl_FB1D18 || *(_DWORD *)(this + 220) == 2139095039 )
    return fmod(*(float *)(this + 268), 86400.0);
  v3 = sub_4735A0();
  v4 = dbl_FB1D18;
  if ( !v3 )
    v4 = dbl_FB1D18 * *(float *)(this + 2272);
  v5 = v4 + *(float *)(this + 268);
  return fmod(v5, 86400.0);
}
