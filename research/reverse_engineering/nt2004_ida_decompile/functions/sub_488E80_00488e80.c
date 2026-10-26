int __stdcall sub_488E80(int a1)
{
  double v1; // st7
  double v2; // st7
  char Buffer[32]; // [esp+10h] [ebp-20h] BYREF
  float v5; // [esp+34h] [ebp+4h]

  v1 = flt_767898;
  if ( a1 == 1 )
    v2 = v1 + 0.1;
  else
    v2 = v1 - 0.1;
  v5 = v2;
  if ( v5 >= 0.0 )
  {
    if ( v5 > 1.0 )
      v5 = 1.0;
  }
  else
  {
    v5 = 0.0;
  }
  flt_767898 = v5;
  if ( v5 >= (double)flt_7678A0 )
  {
    if ( v5 > (double)*(float *)&dword_7678A4 )
      LODWORD(flt_767898) = dword_7678A4;
  }
  else
  {
    flt_767898 = flt_7678A0;
  }
  sub_4EFDE0(LODWORD(v5));
  sprintf(Buffer, "%.1f", v5);
  return sub_4A1AC0(Buffer);
}
