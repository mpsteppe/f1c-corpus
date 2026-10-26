int __thiscall sub_5672A0(float *this)
{
  if ( this[4] < 0.0 )
    return 1;
  this[4] = this[4] - dbl_FB1D10;
  if ( this[5] < 0.0 )
    sub_565890((int)this);
  if ( !sub_565930((int)this) )
    return 1;
  sub_565980((int)this);
  return 0;
}
