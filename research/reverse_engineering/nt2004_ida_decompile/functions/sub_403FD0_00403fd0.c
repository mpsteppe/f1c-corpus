int __thiscall sub_403FD0(_DWORD *this, float *a2, int a3)
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

  v3 = this[89];
  v4 = 0;
  v12 = 9.9999999e36;
  if ( v3 <= 0 )
    return v4;
  v5 = this[90];
  v6 = v3;
  do
  {
    if ( a3 == *(_DWORD *)(v5 + 328) )
    {
      v7 = a2[1] - *(float *)(v5 + 200);
      v8 = a2[2] - *(float *)(v5 + 204);
      v9 = *a2 - *(float *)(v5 + 196);
      v10 = v8 * v8 + v7 * v7 + v9 * v9;
      if ( v10 < v12 )
      {
        v12 = v10;
        v4 = v5;
      }
    }
    v5 += 348;
    --v6;
  }
  while ( v6 );
  if ( v4
    && *(float *)(v4 + 220) * (*(float *)(v4 + 204) - a2[2]) + *(float *)(v4 + 212) * (*(float *)(v4 + 196) - *a2) < 0.0 )
  {
    return *(_DWORD *)(v4 + 296);
  }
  else
  {
    return v4;
  }
}
