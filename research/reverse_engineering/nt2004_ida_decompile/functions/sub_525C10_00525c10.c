void __thiscall sub_525C10(int this)
{
  double v1; // st7

  v1 = *(float *)(this + 128) - *(float *)(this + 132);
  if ( v1 <= 0.0 )
    *(_DWORD *)(this + 136) = 0;
  else
    *(float *)(this + 136) = 1.0 / v1;
}
