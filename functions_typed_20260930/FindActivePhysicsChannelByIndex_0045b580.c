int __thiscall sub_45B580(float *this, int a2)
{
  int v2; // esi
  int v3; // edx
  float *i; // ecx

  v2 = 0;
  v3 = 0;
  for ( i = this + 36; *i <= 0.0; i += 23 )
  {
LABEL_5:
    if ( ++v3 >= 8 )
      return 0;
  }
  if ( a2 != v2 )
  {
    ++v2;
    goto LABEL_5;
  }
  return v3;
}

