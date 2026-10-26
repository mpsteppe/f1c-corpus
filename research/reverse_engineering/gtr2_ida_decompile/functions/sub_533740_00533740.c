void __thiscall sub_533740(_DWORD *this, float a2)
{
  int v2; // eax
  int v3; // edx
  double v4; // st7
  double v5; // st7
  float v6; // [esp+8h] [ebp+4h]

  v2 = dword_B72338;
  v3 = this[dword_B72338 + 8];
  v6 = a2 * 100.0;
  if ( v3 <= 1 )
  {
    if ( v3 == 1 )
      v4 = *(float *)&this[dword_B72338 + 44];
    else
      v4 = v6;
  }
  else
  {
    v4 = (double)(v3 - 1) * *(float *)&this[dword_B72338 + 44];
  }
  v5 = v4 + v6;
  if ( v3 <= 0 )
  {
    *(float *)&this[dword_B72338 + 44] = v6;
    v2 = dword_B72338;
  }
  *(float *)&this[v2 + 44] = v5 / (double)(int)this[v2 + 8];
  if ( *(float *)&this[dword_B72338 + 44] >= 5.0 )
  {
    if ( *(float *)&this[dword_B72338 + 44] > 100.0 )
      this[dword_B72338 + 44] = 1120403456;
  }
  else
  {
    this[dword_B72338 + 44] = 1084227584;
  }
}
