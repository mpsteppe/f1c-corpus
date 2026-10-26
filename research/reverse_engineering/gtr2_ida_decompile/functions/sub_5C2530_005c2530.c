void __thiscall sub_5C2530(int this, float a2, float a3)
{
  double v3; // st7
  double v4; // st7

  v3 = a2;
  if ( a2 >= 0.0 )
  {
    if ( a2 > 1.0 )
      v3 = 1.0;
  }
  else
  {
    v3 = 0.0;
  }
  *(float *)(this + 28) = v3;
  if ( a3 <= 0.0 )
  {
    *(float *)(this + 32) = v3;
    *(_DWORD *)(this + 36) = 0;
    *(_BYTE *)(this + 82) = 0;
  }
  else
  {
    v4 = v3 - *(float *)(this + 32);
    *(_BYTE *)(this + 82) = 1;
    *(float *)(this + 36) = v4 / a3;
  }
}
