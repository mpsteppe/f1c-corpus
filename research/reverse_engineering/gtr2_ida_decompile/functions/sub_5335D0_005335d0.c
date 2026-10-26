void __thiscall sub_5335D0(_DWORD *this, int a2)
{
  double v2; // st7
  int v3; // edx
  float v4; // [esp+0h] [ebp-4h]

  v2 = (double)a2;
  v3 = this[dword_B72338 + 8];
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      *(float *)&this[dword_B72338 + 38] = v2;
    }
    else
    {
      v4 = (double)(v3 - 1) * *(float *)&this[dword_B72338 + 38] + v2;
      *(float *)&this[dword_B72338 + 38] = v4 / (double)v3;
      if ( *(float *)&this[dword_B72338 + 38] >= 1.0 )
      {
        if ( *(float *)&this[dword_B72338 + 38] > 56.0 )
          this[dword_B72338 + 38] = 1113587712;
      }
      else
      {
        this[dword_B72338 + 38] = 1065353216;
      }
    }
  }
}
