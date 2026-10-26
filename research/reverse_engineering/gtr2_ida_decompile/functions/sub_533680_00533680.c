void __thiscall sub_533680(_DWORD *this, int a2)
{
  int v2; // eax
  double v3; // st7
  int v4; // edx
  double v5; // st6
  double v6; // st7
  float v7; // [esp+8h] [ebp+4h]

  v2 = dword_B72338;
  v3 = 0.0;
  v4 = this[dword_B72338 + 8];
  if ( v4 <= 1 )
  {
    if ( v4 == 1 )
      v3 = *(float *)&this[dword_B72338 + 41];
  }
  else
  {
    v3 = (double)(v4 - 1) * *(float *)&this[dword_B72338 + 41];
  }
  v5 = (double)a2;
  v6 = v3 + v5;
  if ( v4 <= 0 )
  {
    v7 = v5;
    *(float *)&this[dword_B72338 + 41] = v7;
    v2 = dword_B72338;
  }
  *(float *)&this[v2 + 41] = v6 / (double)(int)this[v2 + 8];
  if ( *(float *)&this[dword_B72338 + 41] >= 1.0 )
  {
    if ( *(float *)&this[dword_B72338 + 41] > 56.0 )
      this[dword_B72338 + 41] = 1113587712;
  }
  else
  {
    this[dword_B72338 + 41] = 1065353216;
  }
}
