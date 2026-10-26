void __thiscall sub_615280(float *this, float *a2, float *a3, float a4)
{
  double v7; // st7
  long double v8; // st7
  long double v9; // st6
  float v10; // [esp+8h] [ebp-10h]
  float v11; // [esp+Ch] [ebp-Ch]
  float v12; // [esp+10h] [ebp-8h]
  float v13; // [esp+14h] [ebp-4h]
  int v14; // [esp+1Ch] [ebp+4h]
  int v15; // [esp+20h] [ebp+8h]

  v7 = a3[3] * a2[3] + a3[2] * a2[2] + *a2 * *a3 + a3[1] * a2[1];
  *(float *)&v15 = v7;
  if ( v7 >= 0.0 )
  {
    v10 = *a3;
    v11 = a3[1];
    v12 = a3[2];
    v13 = a3[3];
  }
  else
  {
    *(float *)&v15 = -*(float *)&v15;
    v10 = -*a3;
    v11 = -a3[1];
    v12 = -a3[2];
    v13 = -a3[3];
  }
  *(float *)&v14 = 1.0 - a4;
  if ( 1.0 - *(float *)&v15 > 0.02 )
  {
    v8 = acos(*(float *)&v15);
    v9 = 1.0 / sin(v8);
    *(float *)&v14 = sin(v8 * *(float *)&v14) * v9;
    a4 = sin(v8 * a4) * v9;
  }
  *this = *(float *)&v14 * *a2 + v10 * a4;
  this[1] = *(float *)&v14 * a2[1] + v11 * a4;
  this[2] = v12 * a4 + *(float *)&v14 * a2[2];
  this[3] = v13 * a4 + *(float *)&v14 * a2[3];
}
