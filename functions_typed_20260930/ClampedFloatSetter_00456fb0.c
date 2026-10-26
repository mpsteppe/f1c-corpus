void __thiscall sub_456FB0(int this, int a2)
{
  double v2; // st7
  float v3; // edx

  v2 = *(float *)(this + 128);
  v3 = *(float *)(this + 132);
  *(_DWORD *)(this + 172) = a2;
  if ( v2 <= *(float *)(this + 172) )
  {
    if ( *(float *)(this + 172) > (double)v3 )
      *(float *)(this + 172) = v3;
  }
  else
  {
    *(float *)(this + 172) = v2;
  }
}

