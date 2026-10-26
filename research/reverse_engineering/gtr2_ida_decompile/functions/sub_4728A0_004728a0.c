int __thiscall sub_4728A0(float *this)
{
  int v1; // esi
  int v2; // edx
  float *v3; // ecx

  v1 = 0;
  v2 = 0;
  v3 = this + 38;
  do
  {
    if ( *v3 > 0.0 && ++v1 >= 4 )
      break;
    ++v2;
    v3 += 23;
  }
  while ( v2 < 8 );
  return v1;
}
