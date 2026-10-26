void __thiscall sub_40E040(int this, float a2)
{
  if ( byte_B7117C != 1 )
  {
    *(_DWORD *)(this + 4) = 0;
    if ( a2 > 0.0 )
    {
      *(float *)(this + 8) = 1.0 / a2;
    }
    else
    {
      *(_DWORD *)(this + 8) = 2139095039;
      sub_40DEA0((float *)this);
    }
  }
}
