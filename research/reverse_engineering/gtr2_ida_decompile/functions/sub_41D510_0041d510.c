void __thiscall sub_41D510(float *this)
{
  float v1; // edx

  v1 = *this;
  if ( *(_DWORD *)this != -1 && !byte_FAEA91 )
  {
    if ( this[1] >= 0.0 )
    {
      this[1] = this[1] - dbl_FB1D10;
      if ( LODWORD(this[LODWORD(v1) + 4]) )
      {
        if ( dword_FB2790 )
          sub_5EDDD0(dword_FB2790, 0);
      }
    }
    else
    {
      *this = NAN;
      this[1] = 3.0;
    }
  }
}
