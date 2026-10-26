void __thiscall sub_53B5B0(float *this, float *a2, float *a3, float a4)
{
  double v7; // st7
  long double v8; // st6
  float v9; // [esp+8h] [ebp-10h]
  float v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+10h] [ebp-8h]
  float v12; // [esp+14h] [ebp-4h]
  int v13; // [esp+1Ch] [ebp+4h]
  int v14; // [esp+20h] [ebp+8h]

  v7 = a3[3] * a2[3] + a3[2] * a2[2] + *a2 * *a3 + a3[1] * a2[1];
  *(float *)&v14 = v7;
  if ( v7 >= 0.0 )
  {
    v9 = *a3;
    v10 = a3[1];
    v11 = a3[2];
    v12 = a3[3];
  }
  else
  {
    *(float *)&v14 = -*(float *)&v14;
    v12 = -a3[3];
    v9 = -*a3;
    v10 = -a3[1];
    v11 = -a3[2];
  }
  *(float *)&v13 = 1.0 - a4;
  if ( 1.0 - *(float *)&v14 > 0.02 )
  {
    FloatFunctionPassThrough();
    v8 = 1.0 / sin(*(float *)&v14);
    *(float *)&v13 = sin(*(float *)&v14 * *(float *)&v13) * v8;
    a4 = sin(*(float *)&v14 * a4) * v8;
  }
  this[3] = *(float *)&v13 * a2[3] + v12 * a4;
  *this = *(float *)&v13 * *a2 + v9 * a4;
  this[1] = *(float *)&v13 * a2[1] + v10 * a4;
  this[2] = v11 * a4 + *(float *)&v13 * a2[2];
}

