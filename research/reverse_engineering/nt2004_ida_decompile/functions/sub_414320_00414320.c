double __thiscall sub_414320(int this)
{
  double v1; // st7
  char *v3; // ecx
  double v4; // st6
  unsigned __int8 v5; // al
  int v6; // edx

  v1 = 0.0;
  v3 = *(char **)(this + 4);
  v4 = 0.0;
  if ( !v3 )
    return 0.0;
  v5 = *(_BYTE *)(this + 2);
  if ( !v5 )
    return 0.0;
  v6 = v5;
  do
  {
    if ( *v3 > 0 )
    {
      v1 = v1 + (double)*v3;
      v4 = v4 + 1.0;
    }
    ++v3;
    --v6;
  }
  while ( v6 );
  if ( v4 > 0.0 )
    return v1 / v4;
  else
    return 0.0;
}
