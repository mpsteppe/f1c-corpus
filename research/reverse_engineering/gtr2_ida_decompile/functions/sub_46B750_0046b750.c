void __thiscall sub_46B750(int this, int a2)
{
  double v2; // st7
  float v3; // edx

  v2 = *(float *)(this + 132);
  v3 = *(float *)(this + 136);
  *(_DWORD *)(this + 176) = a2;
  if ( v2 <= *(float *)(this + 176) )
  {
    if ( *(float *)(this + 176) > (double)v3 )
      *(float *)(this + 176) = v3;
  }
  else
  {
    *(float *)(this + 176) = v2;
  }
}
