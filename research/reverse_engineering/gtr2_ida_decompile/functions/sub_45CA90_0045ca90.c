void __thiscall sub_45CA90(double *this, int *a2)
{
  double v2; // st7
  float **v3; // esi
  int v4; // edi
  float *v5; // edx
  float *v6; // edx
  float *v7; // edx
  double v8; // st7
  float v9; // [esp+0h] [ebp-18h]
  double v10; // [esp+0h] [ebp-18h]
  float v11; // [esp+8h] [ebp-10h]
  double v12; // [esp+8h] [ebp-10h]
  float v13; // [esp+10h] [ebp-8h]
  double v14; // [esp+10h] [ebp-8h]

  v2 = 3.4028235e38;
  v9 = 3.4028235e38;
  v11 = -3.4028235e38;
  v13 = -3.4028235e38;
  if ( *a2 > 0 )
  {
    v3 = (float **)(a2[2] + 16);
    v4 = *a2;
    do
    {
      v5 = *(v3 - 4);
      if ( v9 > (double)*v5 )
        v9 = *v5;
      if ( v11 < (double)*v5 )
        v11 = *v5;
      if ( v2 > v5[4] )
        v2 = v5[4];
      if ( v13 < (double)v5[4] )
        v13 = v5[4];
      v6 = *(v3 - 2);
      if ( v9 > (double)*v6 )
        v9 = *v6;
      if ( v11 < (double)*v6 )
        v11 = *v6;
      if ( v2 > v6[4] )
        v2 = v6[4];
      if ( v13 < (double)v6[4] )
        v13 = v6[4];
      v7 = *v3;
      if ( v9 > (double)**v3 )
        v9 = *v7;
      if ( v11 < (double)*v7 )
        v11 = *v7;
      if ( v2 > v7[4] )
        v2 = v7[4];
      if ( v13 < (double)v7[4] )
        v13 = v7[4];
      v3 += 8;
      --v4;
    }
    while ( v4 );
  }
  v10 = v9;
  v12 = (v11 - v10) * 0.03125;
  v14 = (v13 - v2) * 0.03125;
  this[1] = v12 * 0.5 + v10;
  this[3] = v14 * 0.5 + v2;
  if ( v12 == 0.0 )
    v8 = 0.0;
  else
    v8 = 1.0 / v12;
  this[2] = v8;
  if ( v14 == 0.0 )
    this[4] = 0.0;
  else
    this[4] = 1.0 / v14;
}
