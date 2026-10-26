void __thiscall sub_533800(_DWORD *this, float a2)
{
  double v2; // st7
  int v3; // eax
  double v4; // st7

  v2 = (double)(int)this[dword_B72338 + 11]++ * *(float *)&this[dword_B72338 + 47];
  v3 = dword_B72338;
  v4 = v2 + a2;
  if ( !this[dword_B72338 + 11] )
  {
    this[dword_B72338 + 11] = 1;
    v3 = dword_B72338;
  }
  *(float *)&this[v3 + 47] = v4 / (double)(int)this[v3 + 11];
  if ( *(float *)&this[dword_B72338 + 47] >= 70.0 )
  {
    if ( *(float *)&this[dword_B72338 + 47] > 120.0 )
      this[dword_B72338 + 47] = 1123024896;
  }
  else
  {
    this[dword_B72338 + 47] = 1116471296;
  }
}
