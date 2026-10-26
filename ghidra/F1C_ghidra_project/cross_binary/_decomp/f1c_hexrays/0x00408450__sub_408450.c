// f1c  0x00408450  size=55
void __thiscall sub_408450(int this, float a2)
{
  *(_DWORD *)(this + 4) = 0;
  if ( a2 > 0.0 )
  {
    *(float *)(this + 8) = 1.0 / a2;
  }
  else
  {
    *(_DWORD *)(this + 8) = 1065353216;
    sub_4082B0((float *)this);
  }
}
