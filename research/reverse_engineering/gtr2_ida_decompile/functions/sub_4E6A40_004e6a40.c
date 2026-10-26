int __stdcall sub_4E6A40(int a1, int a2, float a3)
{
  long double v3; // st7
  long double v4; // st7
  float v6; // [esp+10h] [ebp+Ch]

  v3 = fmod(dbl_FB1D18 + a3, 1.0);
  if ( v3 >= 0.5 )
    v4 = 1.0 - (v3 - 0.5 + v3 - 0.5);
  else
    v4 = v3 + v3;
  v6 = v4;
  return sub_499940(a1, a2, v6);
}
