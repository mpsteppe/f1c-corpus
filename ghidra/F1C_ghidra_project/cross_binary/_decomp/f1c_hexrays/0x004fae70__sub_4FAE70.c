// f1c  0x004fae70  size=79
double __thiscall sub_4FAE70(float *this, float a2)
{
  int v3; // ecx
  int v4; // ecx

  v3 = sub_587BDC(a2);
  if ( (double)v3 >= 0.0 )
  {
    if ( v3 >= 8 )
      v3 = 7;
    return this[v3 + 59];
  }
  else
  {
    v4 = -v3;
    if ( v4 >= 8 )
      v4 = 7;
    return this[v4 + 51];
  }
}
