char __thiscall sub_456880(char *this, int a2, int a3, int a4)
{
  char *v4; // eax
  float *v5; // ecx
  double v6; // st7
  float v8; // [esp+Ch] [ebp+8h]

  v4 = this + 3472;
  if ( a3 )
    v4 = this + 4492;
  if ( (*(float *)&v4[4 * a2 + 920] - *(float *)&v4[4 * a2 + 96]) * *(float *)&v4[4 * a2 + 64] - *(float *)(a4 + 4 * a2) >= -0.34999999 )
    return 0;
  v5 = (float *)((char *)&unk_769ED0 + 864 * a3 + 108 * a2);
  v6 = v5[7];
  v8 = v5[8];
  if ( *(float *)(a4 + 4 * a2) <= 0.92500001 )
    v5[5] = 0.5;
  else
    v5[5] = 1.0;
  if ( v6 <= v5[5] )
  {
    if ( v5[5] > (double)v8 )
      v5[5] = v8;
    return 1;
  }
  else
  {
    v5[5] = v6;
    return 1;
  }
}
