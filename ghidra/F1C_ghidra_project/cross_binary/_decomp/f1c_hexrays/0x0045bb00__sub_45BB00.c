// f1c  0x0045bb00  size=50
int __thiscall sub_45BB00(float *this)
{
  int v1; // esi
  int v2; // edx
  float *v3; // ecx

  v1 = 0;
  v2 = 0;
  v3 = this + 36;
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
