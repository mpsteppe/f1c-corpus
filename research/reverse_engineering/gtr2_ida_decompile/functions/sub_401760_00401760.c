void __thiscall sub_401760(float *this, float a2, float a3)
{
  if ( *this >= (double)a2 )
  {
    if ( *this > (double)a3 )
      *this = a3;
  }
  else
  {
    *this = a2;
  }
}
