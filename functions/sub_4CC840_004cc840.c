void __thiscall sub_4CC840(float *this)
{
  float *v2; // eax
  double v3; // st7
  double v4; // st6
  float *v5; // ecx
  float *v6; // edx
  double v7; // st5
  double v8; // st4
  double v9; // st4
  long double v10; // st2
  double v11; // st5
  long double v12; // st5
  float v13; // [esp+Ch] [ebp-14h]
  float v14; // [esp+14h] [ebp-Ch]
  float v15; // [esp+18h] [ebp-8h]
  float v16; // [esp+1Ch] [ebp-4h]

  v2 = (float *)(VirtualDispatchHelper(&dword_5EA510) + 36);
  v3 = *v2 * -0.03125;
  v13 = v2[1];
  v4 = v2[2] * -0.03125;
  v5 = (float *)&unk_8AC840;
  do
  {
    v6 = v5 - 1;
    *(v5 - 4) = v3;
    *(v5 - 3) = (*(v5 - 5) - v13) * 0.03125;
    *(v5 - 2) = v4;
    v14 = *(v5 - 3) * *(v5 - 6) - *(v5 - 2) * *(v5 - 7);
    v15 = *(v5 - 2) * *(v5 - 8) - *(v5 - 4) * *(v5 - 6);
    v7 = *(v5 - 4) * *(v5 - 7);
    v8 = *(v5 - 3);
    *(v5 - 1) = v14;
    v9 = v8 * *(v5 - 8);
    *v5 = v15;
    v16 = v7 - v9;
    v5[1] = v16;
    v10 = *v5 * *v5 + *(v5 - 1) * *(v5 - 1) + v5[1] * v5[1];
    if ( v10 > 0.0 )
    {
      v12 = this[4] * 0.5 / sqrt(v10);
      *v6 = v12 * *v6;
      *v5 = v12 * *v5;
      v5[1] = v12 * v5[1];
    }
    else
    {
      v11 = this[4];
      *v6 = 0.0;
      v5[1] = 0.0;
      *v5 = v11 * 0.5;
    }
    v5 += 10;
  }
  while ( (int)v5 < (int)flt_8ACAC0 );
}
