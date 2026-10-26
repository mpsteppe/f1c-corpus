void __thiscall sub_4B1DE0(int this, int a2)
{
  double v2; // st7
  float v3; // edx

  v2 = *(float *)(this + 28);
  v3 = *(float *)(this + 32);
  *(_DWORD *)(this + 20) = a2;
  if ( v2 <= *(float *)(this + 20) )
  {
    if ( *(float *)(this + 20) > (double)v3 )
      *(float *)(this + 20) = v3;
  }
  else
  {
    *(float *)(this + 20) = v2;
  }
}
