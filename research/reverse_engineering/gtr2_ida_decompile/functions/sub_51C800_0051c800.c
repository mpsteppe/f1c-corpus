double __thiscall sub_51C800(_DWORD *this)
{
  int v2; // eax
  int v3; // edx
  int i; // ecx
  double v5; // st7

  v2 = sub_51C780();
  v3 = 0;
  for ( i = 0; i < 32; ++i )
    v3 += (v2 >> i) & 1;
  v5 = *(float *)&this[(unsigned __int8)(*this)++ + 257] * 0.5;
  return (v5 + (double)(v3 - 16)) * 0.35355338;
}
