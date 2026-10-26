// Address: 0x0050e0d9
// Size: 155 bytes
// Name: sub_50E0D9
// Type: float *__stdcall(float *, float *)
// Source: IDA Hex-Rays decompilation

float *__stdcall sub_50E0D9(float *a1, float *a2)
{
  float *v2; // ecx
  double v3; // st7
  float v5; // [esp+10h] [ebp-4h]
  float v6; // [esp+20h] [ebp+Ch]

  v5 = sqrt(*a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2]);
  a1[3] = cos(v5);
  v6 = sin(v5);
  if ( sub_50C042(v6, 0.0) )
  {
    if ( a1 != v2 )
    {
      *a1 = *v2;
      a1[1] = v2[1];
      a1[2] = v2[2];
    }
  }
  else
  {
    v3 = v6 / v5;
    *a1 = v3 * *v2;
    a1[1] = v3 * v2[1];
    a1[2] = v3 * v2[2];
  }
  return a1;
}
