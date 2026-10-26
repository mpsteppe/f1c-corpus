float *__thiscall sub_409B80(float *this, float *a2)
{
  double v2; // st7
  float *v3; // edx
  float v5; // [esp+4h] [ebp+4h]

  v2 = this[7];
  v3 = this + 5;
  this[5] = *a2;
  v5 = this[8];
  if ( v2 <= this[5] )
  {
    if ( *v3 > (double)v5 )
      *v3 = v5;
    return this + 5;
  }
  else
  {
    *v3 = v2;
    return this + 5;
  }
}
