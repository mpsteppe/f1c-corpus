double __thiscall sub_51C630(float *this)
{
  long double v1; // st4

  v1 = sqrt(this[4386] * this[4386] + this[4387] * this[4387] + this[4388] * this[4388]);
  if ( v1 == 0.0 )
    return 0.0;
  else
    return (this[4388] * this[4379] + this[4387] * this[4376] + this[4373] * this[4386]) * (-1.0 / v1);
}
