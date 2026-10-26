float *__thiscall sub_519C90(float *this, float a2)
{
  float *result; // eax
  float *v3; // ecx
  float *v4; // edx
  int v5; // esi
  long double v6; // st7
  long double v7; // st7
  __int16 v8; // fps
  double v9; // st7
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  bool v13; // c0
  char v14; // c2
  bool v15; // c3
  float v16; // [esp+4h] [ebp-8h]
  float v17; // [esp+8h] [ebp-4h]

  result = this + 4446;
  v3 = this + 578;
  v17 = flt_7DAB0C + 273.16;
  v4 = result;
  v5 = 4;
  v16 = fabs(v3[3813]);
  v6 = ((fabs(v3[3919]) * v3[3929] + fabs(v3[3857]) * v3[3867]) * v3[4147] * 0.5
      + (v16 * v3[4149] + v3[4148]) * (v17 - *result))
     * a2
     + *result;
  *result = v6;
  v3[3930] = v6;
  v7 = ((fabs(v3[4043]) * v3[4053] + fabs(v3[3981]) * v3[3991]) * v3[4152] * 0.5
      + (v16 * v3[4154] + v3[4153]) * (v17 - v3[3992]))
     * a2
     + v3[3992];
  v3[3992] = v7;
  v3[4054] = v7;
  do
  {
    v9 = (*v4 - 1023.16) * 0.004;
    v10 = v9 < 0.0;
    v11 = 0;
    v12 = v9 == 0.0;
    LOWORD(result) = v8;
    if ( v9 >= 0.0 )
    {
      v13 = v9 < 1.0;
      v14 = 0;
      v15 = v9 == 1.0;
      LOWORD(result) = v8;
      if ( v9 > 1.0 )
        v9 = 1.0;
    }
    else
    {
      v9 = 0.0;
    }
    *v3 = v9;
    v4 += 62;
    v3 += 76;
    --v5;
  }
  while ( v5 );
  return result;
}
