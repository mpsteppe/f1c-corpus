float *__thiscall sub_4F2480(float *this, float *a2, float *a3, float a4)
{
  long double v5; // st7
  double v6; // st7
  long double v7; // st6
  float *result; // eax
  double v9; // st6
  double v10; // st5
  double v11; // st4
  float v12; // [esp+8h] [ebp-8h]
  float v13; // [esp+Ch] [ebp-4h]
  int v14; // [esp+18h] [ebp+8h]
  float v15; // [esp+18h] [ebp+8h]
  float v16; // [esp+1Ch] [ebp+Ch]

  v13 = 1.0;
  *(float *)&v14 = *a3 * *this + this[3] * a3[3] + this[2] * a3[2] + this[1] * a3[1];
  if ( *(float *)&v14 < 0.0 )
  {
    v13 = -1.0;
    *(float *)&v14 = *(float *)&v14 * -1.0;
  }
  if ( 1.0 - *(float *)&v14 <= 0.0000099999997 )
  {
    v6 = 1.0 - a4;
    v7 = a4;
  }
  else
  {
    v5 = acos(*(float *)&v14);
    v15 = v5;
    v12 = 1.0 / sin(v5);
    v6 = sin((1.0 - a4) * v15) * v12;
    v7 = sin(v15 * a4) * v12;
  }
  result = a2;
  v16 = v7 * v13;
  v9 = v6 * this[3] + v16 * a3[3];
  v10 = v6 * this[2] + v16 * a3[2];
  v11 = v6 * this[1] + v16 * a3[1];
  *a2 = v16 * *a3 + v6 * *this;
  a2[1] = v11;
  a2[2] = v10;
  a2[3] = v9;
  return result;
}
