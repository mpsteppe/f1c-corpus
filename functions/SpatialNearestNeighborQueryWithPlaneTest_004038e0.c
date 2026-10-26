int __thiscall sub_4038E0(_DWORD *this, float *a2, int a3)
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
    v7 = a2[1] - *(float *)(v5 + 152);
    v8 = a2[2] - *(float *)(v5 + 156);
    v9 = *a2 - *(float *)(v5 + 148);
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
    && *(float *)(v4 + 172) * (*(float *)(v4 + 156) - a2[2]) + *(float *)(v4 + 164) * (*(float *)(v4 + 148) - *a2) < 0.0 )
  {
    return *(_DWORD *)(v4 + 272);
  }
  else
  {
    return v4;
  }
}
