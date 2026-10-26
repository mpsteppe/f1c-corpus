void __thiscall sub_5074D0(int this, float a2)
{
  *(_DWORD *)(this + 4) = 0;
  if ( a2 > 0.0 )
  {
    *(float *)(this + 8) = 1.0 / a2;
  }
  else
  {
    *(_DWORD *)(this + 8) = 1065353216;
    sub_507330((float *)this);
  }
}
