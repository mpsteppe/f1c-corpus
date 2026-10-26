int __thiscall sub_4D9F80(float *this)
{
  if ( this[4] < 0.0 )
    return 1;
  this[4] = this[4] - dbl_8AFE98;
  if ( this[5] < 0.0 )
    VehicleStateUpdate();
  if ( !(unsigned __int8)TimerValueComparison(this) )
    return 1;
  sub_4DA0D0(this);
  return 0;
}

