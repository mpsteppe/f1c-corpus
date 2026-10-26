double __thiscall sub_591910(float *this, float a2)
{
  int v3; // ecx
  int v4; // ecx

  v3 = (unsigned __int64)a2;
  if ( (double)v3 >= 0.0 )
  {
    if ( v3 >= 8 )
      v3 = 7;
    return this[v3 + 60];
  }
  else
  {
    v4 = -v3;
    if ( v4 >= 8 )
      v4 = 7;
    return this[v4 + 52];
  }
}
