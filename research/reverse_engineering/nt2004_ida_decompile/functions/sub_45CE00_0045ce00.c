int __thiscall sub_45CE00(float *this)
{
  int v1; // esi
  int v2; // edx
  float *v3; // ecx

  v1 = 0;
  v2 = 0;
  v3 = this + 50;
  do
  {
    if ( *v3 > 0.0 && ++v1 >= 4 )
      break;
    ++v2;
    v3 += 35;
  }
  while ( v2 < 8 );
  return v1;
}
