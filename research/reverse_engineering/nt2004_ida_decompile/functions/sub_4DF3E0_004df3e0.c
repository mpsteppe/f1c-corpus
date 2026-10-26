void __thiscall sub_4DF3E0(int this, int a2)
{
  if ( fabs(*(float *)(this + 304) - dbl_7DA9D0) > 10.0 )
  {
    *(float *)(this + 304) = dbl_7DA9D0;
    sub_41BB40(*(_DWORD *)this, a2);
  }
}
