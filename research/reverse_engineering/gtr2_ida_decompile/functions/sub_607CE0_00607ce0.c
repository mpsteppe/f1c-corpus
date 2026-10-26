bool __thiscall sub_607CE0(float *this, float *a2)
{
  int v2; // edx
  float *v3; // ecx

  v2 = 0;
  v3 = this + 16;
  do
  {
    if ( -v3[2] < *(v3 - 1) * *a2 + v3[1] * a2[2] + a2[1] * *v3 )
      break;
    ++v2;
    v3 += 4;
  }
  while ( v2 < 4 );
  return v2 == 4;
}
