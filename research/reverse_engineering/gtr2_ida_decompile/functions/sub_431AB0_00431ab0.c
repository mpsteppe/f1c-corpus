double __thiscall sub_431AB0(double *this, double a2)
{
  if ( a2 <= this[4] )
    return a2 * ((a2 * *this + this[1]) * a2 + this[2]) + this[3];
  else
    return this[4] * ((this[4] * *this + this[1]) * this[4] + this[2]) + this[3];
}
