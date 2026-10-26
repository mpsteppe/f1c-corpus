// f1c  0x004646c0  size=44
void __thiscall sub_4646C0(float *this, float a2, float a3)
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
