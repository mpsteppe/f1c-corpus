void __thiscall sub_507330(float *this)
{
  double v2; // st7
  double v3; // st7
  float v4; // [esp+4h] [ebp-8h]
  float v5; // [esp+8h] [ebp-4h]

  v4 = flt_612DB0 * *this * this[4];
  v5 = this[4] - v4;
  if ( *this == 0.0 )
  {
    if ( *((_BYTE *)this + 21) )
    {
      sub_502060(&dword_7D7978, 1);
      *((_BYTE *)this + 21) = 0;
    }
  }
  else
  {
    if ( dword_7D7990 != -1 )
    {
      sub_502060(&dword_7D7978, 0);
      *((_BYTE *)this + 21) = 1;
    }
    sub_5A7610(dword_7E8CDC, 0, 0, (__int64)this[3], (__int64)v4, 0);
    sub_5A7610(dword_7E8CDC, 0, (__int64)v5, (__int64)this[3], (__int64)(this[4] - v5 + 1.0), 0);
  }
  if ( *this >= (double)this[1] )
  {
    if ( *this > (double)this[1] )
    {
      v3 = *this - dbl_7DA9C0 * this[2];
      *this = v3;
      if ( v3 < this[1] )
        *this = this[1];
    }
  }
  else
  {
    v2 = dbl_7DA9C0 * this[2] + *this;
    *this = v2;
    if ( v2 > this[1] )
      *this = this[1];
  }
}
