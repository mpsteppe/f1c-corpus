void __thiscall sub_5BC480(float *this, float *a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  double v5; // st7
  double v6; // st7

  if ( *this >= (double)*a2 )
    v2 = *a2;
  else
    v2 = *this;
  *this = v2;
  if ( this[1] >= (double)a2[1] )
    v3 = a2[1];
  else
    v3 = this[1];
  this[1] = v3;
  if ( this[2] >= (double)a2[2] )
    v4 = a2[2];
  else
    v4 = this[2];
  this[2] = v4;
  if ( this[3] <= (double)*a2 )
    v5 = *a2;
  else
    v5 = this[3];
  this[3] = v5;
  if ( this[4] <= (double)a2[1] )
    v6 = a2[1];
  else
    v6 = this[4];
  this[4] = v6;
  if ( this[5] <= (double)a2[2] )
    this[5] = a2[2];
  else
    this[5] = this[5];
}
