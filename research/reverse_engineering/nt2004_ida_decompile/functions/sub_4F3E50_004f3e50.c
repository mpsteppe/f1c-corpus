void __thiscall sub_4F3E50(float *this)
{
  int *v2; // eax
  double v3; // st7
  double v4; // st7
  float *v5; // ecx
  double v6; // st6
  float *v7; // edx
  double v8; // st5
  double v9; // st4
  double v10; // st4
  long double v11; // st2
  double v12; // st5
  long double v13; // st5
  float v14; // [esp+8h] [ebp-18h] BYREF
  float v15; // [esp+Ch] [ebp-14h]
  float v16; // [esp+10h] [ebp-10h]
  float v17; // [esp+14h] [ebp-Ch]
  float v18; // [esp+18h] [ebp-8h]
  float v19; // [esp+1Ch] [ebp-4h]

  v2 = (int *)sub_40C460(&dword_6291CC);
  if ( v2 )
  {
    sub_459BE0(v2, &v14);
    v3 = v14;
  }
  else
  {
    v3 = 0.0;
    v15 = 0.0;
    v16 = 0.0;
  }
  v4 = v3 * -0.03125;
  v5 = (float *)&unk_7D6D70;
  v6 = v16 * -0.03125;
  do
  {
    v7 = v5 - 1;
    *(v5 - 4) = v4;
    *(v5 - 3) = (*(v5 - 5) - v15) * 0.03125;
    *(v5 - 2) = v6;
    v17 = *(v5 - 3) * *(v5 - 6) - *(v5 - 2) * *(v5 - 7);
    v18 = *(v5 - 2) * *(v5 - 8) - *(v5 - 4) * *(v5 - 6);
    v8 = *(v5 - 4) * *(v5 - 7);
    v9 = *(v5 - 3);
    *(v5 - 1) = v17;
    v10 = v9 * *(v5 - 8);
    *v5 = v18;
    v19 = v8 - v10;
    v5[1] = v19;
    v11 = *v5 * *v5 + *(v5 - 1) * *(v5 - 1) + v5[1] * v5[1];
    if ( v11 > 0.0 )
    {
      v13 = this[4] * 0.5 / sqrt(v11);
      *v7 = v13 * *v7;
      *v5 = v13 * *v5;
      v5[1] = v13 * v5[1];
    }
    else
    {
      v12 = this[4];
      *v7 = 0.0;
      v5[1] = 0.0;
      *v5 = v12 * 0.5;
    }
    v5 += 10;
  }
  while ( (int)v5 < (int)flt_7D6FF0 );
}
