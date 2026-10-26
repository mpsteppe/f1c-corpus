void __thiscall sub_544540(float *this)
{
  int v2; // eax
  float *v3; // eax
  double v4; // st7
  double v5; // st6
  float *v6; // ecx
  float *v7; // edx
  double v8; // st5
  double v9; // st4
  long double v10; // st2
  double v11; // st5
  long double v12; // st5
  float v13; // [esp+8h] [ebp-14h]
  float v14; // [esp+10h] [ebp-Ch]
  float v15; // [esp+14h] [ebp-8h]
  float v16; // [esp+18h] [ebp-4h]

  v2 = sub_40DCE0(&dword_91BF20);
  if ( v2 )
  {
    v3 = (float *)(v2 + 36);
    v4 = *v3 * -0.03125;
    v13 = v3[1];
    v5 = v3[2] * -0.03125;
    v6 = (float *)&unk_BE1D78;
    do
    {
      v7 = v6 - 1;
      *(v6 - 4) = v4;
      *(v6 - 3) = (*(v6 - 5) - v13) * 0.03125;
      *(v6 - 2) = v5;
      v14 = *(v6 - 6) * *(v6 - 3) - *(v6 - 7) * *(v6 - 2);
      v15 = *(v6 - 8) * *(v6 - 2) - *(v6 - 6) * *(v6 - 4);
      v8 = *(v6 - 7) * *(v6 - 4);
      v9 = *(v6 - 8) * *(v6 - 3);
      *(v6 - 1) = v14;
      *v6 = v15;
      v16 = v8 - v9;
      v6[1] = v16;
      v10 = *v6 * *v6 + *(v6 - 1) * *(v6 - 1) + v6[1] * v6[1];
      if ( v10 > 0.0 )
      {
        v12 = this[4] / sqrt(v10) * 0.5;
        *v7 = v12 * *v7;
        *v6 = v12 * *v6;
        v6[1] = v12 * v6[1];
      }
      else
      {
        v11 = this[4];
        *v7 = 0.0;
        v6[1] = 0.0;
        *v6 = v11 * 0.5;
      }
      v6 += 10;
    }
    while ( (int)v6 < (int)flt_BE1FF8 );
  }
}
