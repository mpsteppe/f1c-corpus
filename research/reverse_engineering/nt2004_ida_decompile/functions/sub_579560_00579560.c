char __thiscall sub_579560(float *this, float *a2, float *a3)
{
  float *v3; // eax
  float v5[9]; // [esp+0h] [ebp-24h] BYREF

  sub_579100(this, v5);
  if ( v3 )
  {
    *v3 = -v5[2];
    v3[1] = -v5[5];
    v3[2] = -v5[8];
  }
  if ( a2 )
  {
    *a2 = v5[1];
    a2[1] = v5[4];
    a2[2] = v5[7];
  }
  if ( a3 )
  {
    *a3 = -v5[0];
    a3[1] = -v5[3];
    a3[2] = -v5[6];
  }
  return 1;
}
