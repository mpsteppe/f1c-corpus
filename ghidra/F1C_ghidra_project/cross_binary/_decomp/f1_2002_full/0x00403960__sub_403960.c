// f1_2002_full  0x00403960  size=217
int __thiscall sub_403960(_DWORD *this, float *a2, int a3)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // edi
  double v7; // st6
  double v8; // st5
  double v9; // st3
  double v10; // st4
  float v12; // [esp+4h] [ebp-4h]

  v3 = this[76];
  v4 = 0;
  v12 = 9.9999999e36;
  if ( v3 <= 0 )
    return v4;
  v5 = this[77];
  v6 = v3;
  do
  {
    v7 = a2[1] - *(float *)(v5 + 148);
    v8 = a2[2] - *(float *)(v5 + 152);
    v9 = *a2 - *(float *)(v5 + 144);
    v10 = v8 * v8 + v7 * v7 + v9 * v9;
    if ( v10 < v12 && (a3 == -1 || a3 == *(_DWORD *)(v5 + 300)) )
    {
      v12 = v10;
      v4 = v5;
    }
    v5 += 316;
    --v6;
  }
  while ( v6 );
  if ( v4
    && *(float *)(v4 + 168) * (*(float *)(v4 + 152) - a2[2]) + *(float *)(v4 + 160) * (*(float *)(v4 + 144) - *a2) < flt_5803E0 )
  {
    return *(_DWORD *)(v4 + 268);
  }
  else
  {
    return v4;
  }
}
