int __thiscall sub_5C6F60(int *this, float a2)
{
  int v2; // edx

  v2 = *this;
  if ( !*this )
    return -1;
  if ( a2 > (double)*(float *)(this[2] + 8 * (v2 >> 1) + 4) )
    return sub_5C6790(v2 >> 1, v2, a2, this);
  return sub_5C6790(0, v2 >> 1, a2, this);
}
